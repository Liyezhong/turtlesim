cmake_minimum_required(VERSION 3.0.2)
project(turtlesim)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
##find_package(catkin REQUIRED COMPONENTS geometry_msgs message_generation rosconsole roscpp roscpp_serialization roslib rostime std_msgs std_srvs)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
##find_package(Qt5Widgets REQUIRED)
##find_package(Boost REQUIRED COMPONENTS thread)




##ap head
set(CMAKE_CXX_STANDARD 14) # C++14...
set(CMAKE_CXX_STANDARD_REQUIRED ON) #...is required...
set(CMAKE_CXX_EXTENSIONS OFF) #...without compiler extensions like gnu++14
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

##ap config
#find_package(timesync REQUIRED)
# Import ARA
message(STATUS "Importing ARA")
find_package(ARA REQUIRED)
message(STATUS "    Package ARA found: ${ARA_FOUND}")

# Import ARA-SomeIP-posix
message(STATUS "Importing ARA-SomeIP-posix")
find_package(ARA-SomeIP-posix REQUIRED)
message(STATUS "    Package ARA-SomeIP-posix found: ${ARA-SomeIP-posix_FOUND}")

# Import Threads
message(STATUS "Importing Threads")
find_package(Threads REQUIRED)
message(STATUS "    Package Threads found: ${Threads_FOUND}")

# Import Logging API
message(STATUS "Importing ara-logging")
find_package(ara-logging REQUIRED)
message(STATUS "    Package ara-logging found: ${ara-logging_FOUND}")

# Import ApplicationClient
message(STATUS "Importing EM ApplicationClient")

option (ENABLE_EXEC_MANAGER "Enable Vector Execution Manager support" ON)
if(ENABLE_EXEC_MANAGER)
    add_definitions(-DENABLE_EXEC_MANAGER)
endif()
message(STATUS "option -DENABLE_EXEC_MANAGER=" ${ENABLE_EXEC_MANAGER})

if(ENABLE_EXEC_MANAGER)
    set(VectorApplicationClient amsr-vector-fs-em-executionmanagement_application-client)
    find_package(${VectorApplicationClient} QUIET)
    set(ARA_EXEC_LIBRARIES ${${VectorApplicationClient}_LIBRARIES})
    message(STATUS "    Package ApplicationClient (Vector) found with libraries: ${ARA_EXEC_LIBRARIES}")
    set(ARA_EXEC_INCLUDE_DIRS ${${VectorApplicationClient}_INCLUDE_DIRS})
endif()

option (ENABLE_DIAG_MANAGER "Enable Vector Diagnostic Manager support" OFF)
message(STATUS "option -DENABLE_DIAG_MANAGER=" ${ENABLE_DIAG_MANAGER})
if(ENABLE_DIAG_MANAGER)
    add_definitions(-DENABLE_DIAG_MANAGER)
    if(NOT DEFINED DIAG_EXAMPLE_DAEMON_CONFIG_DIR)
        SET(DIAG_EXAMPLE_DAEMON_CONFIG_DIR /opt/diag_example_daemon/etc)
    endif()
endif()

# Import vac
message(STATUS "Importing vac")
find_package(vac REQUIRED)
message(STATUS "    Package vac found: ${vac_FOUND}")
message(STATUS "-- User options ---------------------------------------------")
set(ADAPTIVE_MICROSAR_SRC_GEN_DIR "${PROJECT_BINARY_DIR}/src-gen" CACHE PATH "Directory containing generated artifacts.")
message(STATUS "option -DADAPTIVE_MICROSAR_SRC_GEN_DIR=\"${ADAPTIVE_MICROSAR_SRC_GEN_DIR}\"")

option(USE_ARA_PER "Enable ara/per example code" OFF)
message(STATUS "option -DUSE_ARA_PER=" ${USE_ARA_PER})

if (USE_ARA_PER)
    # Import persistency library
    message(STATUS "Importing persistency")
    find_package(persistency REQUIRED)
    message(STATUS "    Package persistency found: ${persistency_FOUND}")
    add_definitions(-DPERSISTENCY_ON)
endif()

if(NOT DEFINED APPLICATION_PREFIX)
    SET(APPLICATION_PREFIX /opt)
endif()

if(NOT DEFINED SOMEIPD_CONFIG_DIR)
    SET(SOMEIPD_CONFIG_DIR /opt/someipd_posix/etc)
endif()

option(ENABLE_CODE_GENERATION "Enable code generation." ON)
message(STATUS "option -DENABLE_CODE_GENERATION=${ENABLE_CODE_GENERATION}")
if(ENABLE_CODE_GENERATION)
    # Directory containing all containers
    set(GENERATORS_COMMON_DIR "" CACHE PATH "Directory containing all generators")
    message(STATUS "Generators Root Directory: -DGENERATORS_COMMON_DIR=${GENERATORS_COMMON_DIR}")
endif()

message(STATUS "-------------------------------------------------------------")

add_subdirectory(src)


message(STATUS "---------------------------------------------------------")
if(ENABLE_CODE_GENERATION)
    message(STATUS "Create src-gen and sip rule for automatic code generation")
    include("${PROJECT_SOURCE_DIR}/CodeGeneration.cmake")


    set(EXTERNAL_GENERATORS
            amsr_modelleddatatypes_api
            amsr_com_api
            amsr_com_someip
            amsr_com_ipc
            )

    if(ENABLE_EXEC_MANAGER)
        set(EXTERNAL_GENERATORS
                ${EXTERNAL_GENERATORS}
                amsr_em_exec_config
                )
    endif()
    if(ENABLE_DIAG_MANAGER)
        set(EXTERNAL_GENERATORS
                ${EXTERNAL_GENERATORS}
                amsr_diag_daemon
                amsr_diag_api
                amsr_diag_model
                )
    endif()
    if(USE_ARA_PER)
        set(EXTERNAL_GENERATORS
                ${EXTERNAL_GENERATORS}
                amsr_persistency_config
                )
    endif()
    # Get required generators
    # Set path of used generators. Prefer common generator paths specified by cmake define
    set(EXTERNAL_GENERATOR_DIRS "")
    if(GENERATORS_COMMON_DIR)
        foreach(generator ${EXTERNAL_GENERATORS})
            set(EXTERNAL_GENERATOR_DIRS "${GENERATORS_COMMON_DIR}/${generator};${EXTERNAL_GENERATOR_DIRS}")
        endforeach()
    else()
        set(EXTERNAL_GENERATOR_DIRS "${ARA_GENERATOR_DIRS}")
        if(ENABLE_EXEC_MANAGER)
            set(EXTERNAL_GENERATOR_DIRS "${amsr-vector-fs-em-executionmanagement_application-client_GENERATOR_DIRS};${EXTERNAL_GENERATOR_DIRS}")
        else()
            set(EXTERNAL_GENERATOR_DIRS "${EXTERNAL_GENERATOR_DIRS}")
        endif()
    endif()
    message(STATUS "External generator directories: ${EXTERNAL_GENERATOR_DIRS}")

    # Generate source files
    SetupGeneralSrcGenTarget()
    SetupSrcGenTarget("${GENERATOR_ROOT_DIR}" "" "${EXTERNAL_GENERATOR_DIRS}" "${PROJECT_SOURCE_DIR}" "${ADAPTIVE_MICROSAR_SRC_GEN_DIR}" turtlesim)

    message(STATUS "-------------------------------------------------------------")
endif()

# Deploy
install(FILES ${PROJECT_SOURCE_DIR}/etc/someip-posix/someipd-posix.json
        PERMISSIONS OWNER_READ OWNER_WRITE GROUP_READ WORLD_READ
        DESTINATION ${SOMEIPD_CONFIG_DIR}
        )
install(FILES ${PROJECT_SOURCE_DIR}/etc/someip-posix/someipd-posix-gen.json
        PERMISSIONS OWNER_READ OWNER_WRITE GROUP_READ WORLD_READ
        DESTINATION ${SOMEIPD_CONFIG_DIR}
        )








##include_directories(include ${catkin_INCLUDE_DIRS} ${Boost_INCLUDE_DIRS})
##link_directories(${catkin_LIBRARY_DIRS})

##add_message_files(DIRECTORY msg FILES
##                  Color.msg Pose.msg)
##add_service_files(DIRECTORY srv FILES
##                  Kill.srv
##                  SetPen.srv
##                  Spawn.srv
##                  TeleportAbsolute.srv
##                  TeleportRelative.srv)
##generate_messages(DEPENDENCIES geometry_msgs std_msgs std_srvs)

##catkin_package(CATKIN_DEPENDS geometry_msgs message_runtime std_msgs std_srvs
##        roscpp  std_msgs message_runtime)
##include_directories(
##        # include
##        ${catkin_INCLUDE_DIRS}
##)
#set(turtlesim_node_SRCS
#  src/AP_actuator.cpp
#  src/turtle.cpp
#  src/turtle_frame.cpp
#        src/rosap_exe.cpp)

#set(turtlesim_node_HDRS
#  include/AP_actuator/turtle_frame.h
#)

#qt5_wrap_cpp(turtlesim_node_MOCS ${turtlesim_node_HDRS})


#add_executable(turtlesim_node ${turtlesim_node_SRCS} ${turtlesim_node_MOCS})
#target_link_libraries(turtlesim_node Qt5::Widgets ${catkin_LIBRARIES} ${Boost_LIBRARIES})
#add_dependencies(turtlesim_node turtlesim_gencpp)

#add_executable(turtle_teleop_key src/rosap_exe/rosap_exe.cpp)
#target_link_libraries(turtle_teleop_key ${catkin_LIBRARIES})
#add_dependencies(turtle_teleop_key turtlesim_gencpp)

#add_executable(draw_square tutorials/draw_square.cpp)
#target_link_libraries(draw_square ${catkin_LIBRARIES} ${Boost_LIBRARIES})
#add_dependencies(draw_square turtlesim_gencpp)


#add_executable(mimic tutorials/mimic.cpp)
#target_link_libraries(mimic ${catkin_LIBRARIES})
#add_dependencies(mimic turtlesim_gencpp)

#install(TARGETS turtlesim_node turtle_teleop_key draw_square mimic
 # RUNTIME DESTINATION ${CATKIN_PACKAGE_BIN_DESTINATION})

##install(DIRECTORY images
##  DESTINATION ${CATKIN_PACKAGE_SHARE_DESTINATION}
##  FILES_MATCHING PATTERN "*.png" PATTERN "*.svg")
