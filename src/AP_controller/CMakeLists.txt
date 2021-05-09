######################################################################################################################
#  COPYRIGHT
#  -------------------------------------------------------------------------------------------------------------------
#  \verbatim
#  Copyright (c) 2020 by Vector Informatik GmbH.                                                  All rights reserved.
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

set(TARGET_NAME AP_controller)


# Get direct dependencies

message(STATUS "-------------------------------------------------------------")
message(STATUS "Importing ARA-IpcBinding-posix")
find_package(ARA-IpcBinding-posix REQUIRED)
message(STATUS "Package ARA-IpcBinding-posix found: ${ARA-IpcBinding-posix_FOUND}")

# Build
if (ENABLE_DIAG_MANAGER)
    message(STATUS "-------------------------------------------------------------")
    message(STATUS "Importing LIB_ARA_DIAG")
    find_package(LibAraDiag REQUIRED)
    message(STATUS "Package LIB_ARA_DIAG found: ${LIB_ARA_DIAG_FOUND}")
    message(STATUS "LIB_ARA_DIAG_INCLUDE_DIRS: ${LIB_ARA_DIAG_INCLUDE_DIRS}")
    message(STATUS "LIB_ARA_DIAG_LIBRARIES: ${LIB_ARA_DIAG_LIBRARIES}")
else()
    set(LIB_ARA_DIAG_SOURCES  )
endif()



# Collect Sources
file(GLOB_RECURSE AP_controller_SRCS
        ${PROJECT_SOURCE_DIR}/src/AP_controller/*.cc
        ${PROJECT_SOURCE_DIR}/src/AP_controller/*.cpp
        ${PROJECT_SOURCE_DIR}/src/common/*.cc
        )
message(STATUS "AP_controller_SRCS: ${AP_controller_SRCS}")

# Collect Generated Sources
file(GLOB_RECURSE AP_controller_GEN_SRCS_ALL
        ${ADAPTIVE_MICROSAR_SRC_GEN_DIR}/${TARGET_NAME}/*.cc
        ${ADAPTIVE_MICROSAR_SRC_GEN_DIR}/${TARGET_NAME}/*.cpp
        )
set(AP_controller_GEN_SRCS
        ${AP_controller_GEN_SRCS}
        ${AP_controller_GEN_SRCS_ALL}
        )
message(STATUS "AP_controller_GEN_SRCS: ${AP_controller_GEN_SRCS}")


# Add Target
add_executable(${TARGET_NAME}
        ${AP_controller_SRCS}
        ${AP_controller_GEN_SRCS}
        ${LIB_ARA_DIAG_SOURCES}
        ${PERSISTENCY_SOURCES}
        )

# Collect Sources

target_link_libraries(${TARGET_NAME} PRIVATE
        ${ARA_IPC_BINDING_POSIX_LIBRARIES}
        ${ARA_SOMEIP_POSIX_LIBRARIES}
        ${PERSISTENCY_LIBRARIES}
        ${ARA_LOGGING_LIBRARIES}
        ${VAC_LIBRARIES}
#        ${catkin_LIBRARIES}
        )
target_link_libraries(${TARGET_NAME} PRIVATE "-latomic")

##add_dependencies(${TARGET_NAME} turtlesim_generate_messages_cpp)
if (USE_ARA_PER OR ENABLE_DIAG_MANAGER)
    target_link_libraries(${TARGET_NAME} PUBLIC
            ${PERSISTENCY_LIBRARIES}
            )
    target_include_directories(${TARGET_NAME} PRIVATE
            "$<BUILD_INTERFACE:$<TARGET_PROPERTY:persistency,INTERFACE_INCLUDE_DIRECTORIES>>"
            )
    target_include_directories(${TARGET_NAME} PUBLIC
            ${PERSISTENCY_INCLUDE_DIRS}
            )
endif()

if (ENABLE_DIAG_MANAGER)
    target_link_libraries(${TARGET_NAME} INTERFACE
            ${LIB_ARA_DIAG_LIBRARIES}
            )
    target_include_directories(${TARGET_NAME} PRIVATE
            "$<BUILD_INTERFACE:$<TARGET_PROPERTY:LibAraDiag,INTERFACE_INCLUDE_DIRECTORIES>>"
            )
    #${LIB_ARA_DIAG_INCLUDE_DIRS}

    target_include_directories(${TARGET_NAME} PUBLIC
            ${DM_INCLUDE_DIRS}
            )
endif()

if(ENABLE_EXEC_MANAGER)
    target_link_libraries(${TARGET_NAME} PRIVATE
            ${ARA_EXEC_LIBRARIES}
            )
    target_include_directories(${TARGET_NAME} PRIVATE
            ${EXEC_MANAGER_INCLUDE_DIRS}
            )
endif()


# Collect Includes
target_include_directories(${TARGET_NAME} PRIVATE
        ${PROJECT_SOURCE_DIR}/addon/${TARGET_NAME}/
        ${PROJECT_SOURCE_DIR}/src/common
        ${ADAPTIVE_MICROSAR_SRC_GEN_DIR}/${TARGET_NAME}/includes
        ${ADAPTIVE_MICROSAR_SRC_GEN_DIR}/${TARGET_NAME}/someip-posix
        ${ADAPTIVE_MICROSAR_SRC_GEN_DIR}/${TARGET_NAME}/ipc-posix
        ${VAC_INCLUDE_DIRS}
        ${ARA_LOGGING_INCLUDE_DIRS}
        ${ARA_IPC_BINDING_POSIX_INCLUDE_DIRS}
        ${ARA_SOMEIP_POSIX_INCLUDE_DIRS}
#        ${catkin_INCLUDE_DIRS}
        )

## Create link to config files
add_custom_command(TARGET ${TARGET_NAME} POST_BUILD
        COMMENT "Creating symlink to logging_config file"
        COMMAND mkdir -p ${CMAKE_BINARY_DIR}/src/AP_controller/etc/
        COMMAND mkdir -p ${CMAKE_BINARY_DIR}/src/AP_controller/var/
        COMMAND ln -sf ${PROJECT_SOURCE_DIR}/etc/AP_controller/logging_config.json ${CMAKE_BINARY_DIR}/src/AP_controller/etc/logging_config.json)

# Deploy
install(TARGETS ${TARGET_NAME} RUNTIME
        DESTINATION ${APPLICATION_PREFIX}/${TARGET_NAME}/bin)
install(FILES ${MANIFEST_FILE_CLIENT}
        PERMISSIONS OWNER_READ OWNER_WRITE GROUP_READ WORLD_READ
        DESTINATION ${APPLICATION_PREFIX}/${TARGET_NAME}/etc RENAME ${MANIFEST_TARGET_FILENAME})
install(FILES ${PROJECT_SOURCE_DIR}/etc/${TARGET_NAME}/logging_config.json
        PERMISSIONS OWNER_READ OWNER_WRITE GROUP_READ WORLD_READ
        DESTINATION ${APPLICATION_PREFIX}/${TARGET_NAME}/etc/)
install(FILES ${PROJECT_SOURCE_DIR}/etc/${TARGET_NAME}/application.json
        PERMISSIONS OWNER_READ OWNER_WRITE GROUP_READ WORLD_READ
        DESTINATION ${APPLICATION_PREFIX}/${TARGET_NAME}/etc/)
install(FILES ${ADAPTIVE_MICROSAR_SRC_GEN_DIR}/${TARGET_NAME}/configuration/someip_config.json
        PERMISSIONS OWNER_READ OWNER_WRITE GROUP_READ WORLD_READ
        DESTINATION ${APPLICATION_PREFIX}/${TARGET_NAME}/etc/)

if(USE_ARA_PER)
    if(EXISTS ${ADAPTIVE_MICROSAR_SRC_GEN_DIR}/${TARGET_NAME}/etc/per_config.json)
        install(FILES ${ADAPTIVE_MICROSAR_SRC_GEN_DIR}/${TARGET_NAME}/etc/per_config.json
                PERMISSIONS OWNER_READ OWNER_WRITE GROUP_READ WORLD_READ
                DESTINATION ${APPLICATION_PREFIX}/${TARGET_NAME}/etc/)
    else()
        message(ERROR "per_config.json does not exist at: ${ADAPTIVE_MICROSAR_SRC_GEN_DIR}/${TARGET_NAME}/etc/")
    endif()
    if(EXISTS ${ADAPTIVE_MICROSAR_SRC_GEN_DIR}/${TARGET_NAME}/etc/per_key_value_storage_config.json)
        install(FILES ${ADAPTIVE_MICROSAR_SRC_GEN_DIR}/${TARGET_NAME}/etc/per_key_value_storage_config.json
                PERMISSIONS OWNER_READ OWNER_WRITE GROUP_READ WORLD_READ
                DESTINATION ${APPLICATION_PREFIX}/${TARGET_NAME}/etc/)
    else()
        message(ERROR "per_key_value_storage_config.json does not exist at: ${ADAPTIVE_MICROSAR_SRC_GEN_DIR}/${TARGET_NAME}/etc/")
    endif()
    if(EXISTS ${ADAPTIVE_MICROSAR_SRC_GEN_DIR}/${TARGET_NAME}/etc/per_file_storage_config.json)
        install(FILES ${ADAPTIVE_MICROSAR_SRC_GEN_DIR}/${TARGET_NAME}/etc/per_file_storage_config.json
                PERMISSIONS OWNER_READ OWNER_WRITE GROUP_READ WORLD_READ
                DESTINATION ${APPLICATION_PREFIX}/${TARGET_NAME}/etc/)
    else()
        message(ERROR "per_file_storage_config.json does not exist at: ${ADAPTIVE_MICROSAR_SRC_GEN_DIR}/${TARGET_NAME}/etc/")
    endif()
    install(DIRECTORY
            DESTINATION ${APPLICATION_PREFIX}/${TARGET_NAME}/var)
endif()

if (ENABLE_DIAG_MANAGER)
    if(EXISTS ${ADAPTIVE_MICROSAR_SRC_GEN_DIR}/dm_server_config_sample_cluster.json)
        install(FILES ${ADAPTIVE_MICROSAR_SRC_GEN_DIR}/dm_server_config_sample_cluster.json
                PERMISSIONS OWNER_READ OWNER_WRITE GROUP_READ WORLD_READ
                DESTINATION ${APPLICATION_PREFIX}/${TARGET_NAME}/etc/)
    else()
        message(ERROR "dm_server_config_sample_cluster.json does not exist at: ${ADAPTIVE_MICROSAR_SRC_GEN_DIR}")
    endif()
endif()

if(ENABLE_EXEC_MANAGER)
    install(FILES ${ADAPTIVE_MICROSAR_SRC_GEN_DIR}/${TARGET_NAME}/configuration/exec_config.json
            PERMISSIONS OWNER_READ OWNER_WRITE GROUP_READ WORLD_READ
            DESTINATION ${APPLICATION_PREFIX}/${TARGET_NAME}/etc RENAME exec_config.json)
endif()
