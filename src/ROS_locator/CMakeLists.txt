#######################################################################################################################
#  COPYRIGHT
#  -------------------------------------------------------------------------------------------------------------------
#  \verbatim
#  Copyright (c) 2018 by Vector Informatik GmbH.                                                  All rights reserved.
#
#                This software is copyright protected and proprietary to Vector Informatik GmbH.
#                Vector Informatik GmbH grants to you only those rights as set out in the license conditions.
#                All other rights remain with Vector Informatik GmbH.
#  \endverbatim
#  -------------------------------------------------------------------------------------------------------------------
#  FILE DESCRIPTION
#  -----------------------------------------------------------------------------------------------------------------*/
#
#         \file
#        \brief  This file is part of the CMake build-configuration.
#
#      \details  This file is part of the CMake build-configuration.
#
#######################################################################################################################

#######################################################################################################################
#  REVISION HISTORY
#  -------------------------------------------------------------------------------------------------------------------
#  Refer to the module's ChangeHistory.txt
#
#
#  FILE VERSION
#  -------------------------------------------------------------------------------------------------------------------
#  The file version is identical to the component version. To determine the actual version of the component,
#  see the technical reference.
#
#######################################################################################################################


set(TARGET_NAME ROS_locator)
file(GLOB_RECURSE ROS_locator_SRCS ${PROJECT_SOURCE_DIR}/src/ROS_locator/*.cpp )
message(STATUS "ROS_locator_SRCS: ${ROS_locator_SRCS}")

#file(GLOB_RECURSE ROS_locator_GEN_SRCS_SOMEIP ${ADAPTIVE_MICROSAR_SRC_GEN_DIR}/${TARGET_NAME}/someip-posix/*.cc ${ADAPTIVE_MICROSAR_SRC_GEN_DIR}/${TARGET_NAME}/someip-posix/*.cpp)
#file(GLOB_RECURSE ROS_locator_GEN_SRCS ${ADAPTIVE_MICROSAR_SRC_GEN_DIR}/${TARGET_NAME}/src/*.cc ${ADAPTIVE_MICROSAR_SRC_GEN_DIR}/${TARGET_NAME}/src/*.cpp)
#set(ROS_locator_GEN_SRCS ${ROS_locator_GEN_SRCS} ${ROS_locator_GEN_SRCS_SOMEIP})
#message(STATUS "ROS_locator_GEN_SRCS: ${ROS_locator_GEN_SRCS}")

message(STATUS "-------------------------------------------------------------")

if(ENABLE_DOXYGEN)
    add_subdirectory(doc)
endif()
#set(ROS_locator_HDRS
#        include/turtle_frame.h
#        include/turtle.h
#        )
#qt5_wrap_cpp(ROS_locator_MOCS ${ROS_locator_HDRS})


# Build
add_executable(${TARGET_NAME} ${ROS_locator_SRCS} ROS_locator.cpp)


# Collect Includes
target_include_directories(${TARGET_NAME} PRIVATE
#        ${VAC_INCLUDE_DIRS}
#        ${ADAPTIVE_MICROSAR_SRC_GEN_DIR}/${TARGET_NAME}/includes
#        ${ADAPTIVE_MICROSAR_SRC_GEN_DIR}/${TARGET_NAME}/someip-posix
#        ${ARA_LOGGING_INCLUDE_DIRS}
#        #${timesync_INCLUDE_DIRS}
#        ${PROJECT_SOURCE_DIR}/src/common
        ${catkin_INCLUDE_DIRS}
        )
target_include_directories(${TARGET_NAME} PRIVATE
#        ${PROJECT_SOURCE_DIR}/addon/${TARGET_NAME}/
#        ${PROJECT_SOURCE_DIR}/src/common
#        ${ADAPTIVE_MICROSAR_SRC_GEN_DIR}/${TARGET_NAME}/includes
#        ${ADAPTIVE_MICROSAR_SRC_GEN_DIR}/${TARGET_NAME}/someip-posix
#        ${ADAPTIVE_MICROSAR_SRC_GEN_DIR}/${TARGET_NAME}/ipc-posix
#        ${VAC_INCLUDE_DIRS}
#        ${ARA_LOGGING_INCLUDE_DIRS}
#        ${ARA_IPC_BINDING_POSIX_INCLUDE_DIRS}
#        ${ARA_SOMEIP_POSIX_INCLUDE_DIRS}
        ${catkin_INCLUDE_DIRS}

        )

target_link_libraries(${TARGET_NAME}
#        ${ARA_SOMEIP_POSIX_LIBRARIES}
#        ${ADAPTIVEPLATFORM_LIBRARIES}
#        ${ARA_LIBRARIES}
#        ${ARA_LOGGING_LIBRARIES}
#        ${VAC_LIBRARIES}
        # ${timesync_LIBRARIES}
        ${catkin_LIBRARIES}
        )


target_link_libraries(${TARGET_NAME}  ${catkin_LIBRARIES} ${Boost_LIBRARIES})


# Create link to config files ros
#add_dependencies(${TARGET_NAME} rosap_generate_messages_cpp)
add_dependencies(${TARGET_NAME} turtlesim_gencpp)

target_link_libraries(${TARGET_NAME} ${ARA_EXEC_LIBRARIES})

# Create link to config files
add_custom_command(TARGET ${TARGET_NAME} POST_BUILD
        COMMENT "Creating symlink to logging_config file"
        COMMAND mkdir -p ${CMAKE_BINARY_DIR}/src/server/etc/
        COMMAND ln -sf ${PROJECT_SOURCE_DIR}/etc/server/logging_config.json ${CMAKE_BINARY_DIR}/src/server/etc/logging_config.json)

# Deploy
install(TARGETS ${TARGET_NAME} RUNTIME
        DESTINATION ${APPLICATION_PREFIX}/${TARGET_NAME}/bin)
install(FILES ${MANIFEST_FILE_SERVER}
        PERMISSIONS OWNER_READ OWNER_WRITE GROUP_READ WORLD_READ
        DESTINATION ${APPLICATION_PREFIX}/${TARGET_NAME}/etc
        RENAME ${MANIFEST_TARGET_FILENAME})
#[[install(FILES ${PROJECT_SOURCE_DIR}/etc/${TARGET_NAME}/logging_config.json
        PERMISSIONS OWNER_READ OWNER_WRITE GROUP_READ WORLD_READ
        DESTINATION ${APPLICATION_PREFIX}/${TARGET_NAME}/etc/)]]
#[[install(FILES ${PROJECT_SOURCE_DIR}/etc/${TARGET_NAME}/application.json
        PERMISSIONS OWNER_READ OWNER_WRITE GROUP_READ WORLD_READ
        DESTINATION ${APPLICATION_PREFIX}/${TARGET_NAME}/etc/)]]
#[[install(FILES ${ADAPTIVE_MICROSAR_SRC_GEN_DIR}/${TARGET_NAME}/configuration/someip_config.json
        PERMISSIONS OWNER_READ OWNER_WRITE GROUP_READ WORLD_READ
        DESTINATION ${APPLICATION_PREFIX}/${TARGET_NAME}/etc/)]]
#if(ENABLE_EXEC_MANAGER)
#    install(FILES ${ADAPTIVE_MICROSAR_SRC_GEN_DIR}/${TARGET_NAME}/configuration/exec_config.json
#            PERMISSIONS OWNER_READ OWNER_WRITE GROUP_READ WORLD_READ
#            DESTINATION ${APPLICATION_PREFIX}/${TARGET_NAME}/etc RENAME exec_config.json)
#endif()
