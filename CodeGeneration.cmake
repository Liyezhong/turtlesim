# ----------------------------------------------------------------------------------------------------------------------
# Code generation support
# ----------------------------------------------------------------------------------------------------------------------

# \brief Set general generator variables
# \param generator_root_dir Root directory of the generator
FUNCTION(SetGeneralGeneratorVariables generator_root_dir)
    if(NOT ADAPTIVE_MICROSAR_SIP_DIR)
        if(COMMAND find_sip_dir)
            # SIP dir not yet set, search for SIP directory.
            find_sip_dir(ADAPTIVE_MICROSAR_SIP_DIR)
        else()
            message(FATAL_ERROR "SIP directory cannot be found. Please set it with CMake parameter -DADAPTIVE_MICROSAR_SIP_DIR.")
        endif()
    endif()

    set(GENERATOR_RUN_CMD "${ADAPTIVE_MICROSAR_SIP_DIR}/DaVinciConfigurator/Core/amsrgen.sh" PARENT_SCOPE)
    # message("== Generator command:  ${GENERATOR_RUN_CMD} =====================================")
    # -- List of all generator JAR files
    SET(GENERATOR_JAR_FILES "")
    foreach(generator ${generators})
      set(GENERATOR_JAR_FILES "${generator_root_dir}/${generator}/build/libs/${generator}.jar;${GENERATOR_JAR_FILES}")
    endforeach(generator)
    SET(GENERATOR_JAR_FILES "${GENERATOR_JAR_FILES}" PARENT_SCOPE)

ENDFUNCTION() # SetGeneralGeneratorVariables

# \brief Install generators
# \param generators List of generator names
# \param destdir Destination dirctory for generators
# \param component_name Component name of generators
FUNCTION(InstallGenerators generators destdir component_name)
    foreach(generator ${generators})
        install(FILES "${generator_root_dir}/${generator}/build/libs/${generator}.jar"
            DESTINATION ${destdir}
            COMPONENT ${component_name})
    endforeach(generator ${generators})
ENDFUNCTION() # SetGeneralGeneratorVariables



# \brief Setup generator build target 'generator'. Builds the generator JAR(s).
# \param generator_root_dir Root directory of the generator
# \param generators List of generator names to be build
FUNCTION(SetupGeneratorBuildTarget generator_root_dir generators)
    SetGeneralGeneratorVariables("${generator_root_dir}")

    # Generator source files
    set(GENERATOR_SRCS
        "${generator_root_dir}/projectConfig.gradle"
        "${generator_root_dir}/settings.gradle"
        # build.gradle and dvCfgGenDevKitBootstrap.gradle cause continuous rebuilds, therefore not included in dependency
        )
    foreach(generator ${generators})
        file(GLOB_RECURSE SINGLE_GENERATOR_SRCS
            "${generator_root_dir}/${generator}/src/*.java"
            "${generator_root_dir}/${generator}/templates/*.jet"
            "${generator_root_dir}/${generator}/ChangeHistory/*"
            # build.gradle causes continuous rebuilds, therefore not included in dependency
            )
        set(GENERATOR_SRCS "${SINGLE_GENERATOR_SRCS};${GENERATOR_SRCS}")
    endforeach(generator)

    # Custom target / command for build of code generator (JAR). add_dependencies() to this target required for code generation target(s).
    add_custom_command(
        OUTPUT ${GENERATOR_JAR_FILES}
        COMMAND ./gradlew build
        VERBATIM
        COMMENT "Build generator(s) via Gradle"
        DEPENDS ${GENERATOR_SRCS}
        WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
    )

    # Custom target "generator" which builds all generator(s)
    add_custom_target(generator
        DEPENDS ${GENERATOR_JAR_FILES})

    # Ensure cleanup of generator JARs on 'make clean'
    SET(GENERATOR_CLEANUP_FILES "")
    foreach(generator ${generators})
        set(GENERATOR_CLEANUP_FILES "${generator_root_dir}/${generator}/build;${generator_root_dir}/${generator}/bin;${GENERATOR_CLEANUP_FILES}")
    endforeach(generator)
    set_directory_properties(PROPERTIES ADDITIONAL_MAKE_CLEAN_FILES "${GENERATOR_CLEANUP_FILES}")

ENDFUNCTION() # SetupGeneratorBuildTarget

# \brief Setup general target source code generation 'src-gen'. This target depends on all configuration specific code generation targets.
#        src-gen --depends--> src-gen-{config_name}. Dependency to this target will be added by SetupSrcGenTarget().
FUNCTION(SetupGeneralSrcGenTarget)
    add_custom_target(src-gen
        COMMENT "Code generation of all test configurations")
ENDFUNCTION() # SetupSrcGenTarget

# \brief Setup target for configuration specific code generation. Generates source code out of ARXML models.
#        Target name: src-gen-{config_name}
# \param generator_root_dir Root directory of the generator
# \param generators List of generator names to be build
# \param external_generator_paths List of generator names to be build
# \param config_root_dir Root directory of the configuration
# \param config_src_gen_dir Directory of the generated artifacts
# \param config_name Name of the configuration to be generated
FUNCTION(SetupSrcGenTarget generator_root_dir internal_generator_paths external_generator_paths config_root_dir config_src_gen_dir config_name)

    # Absolute paths containing internal and external generators
    set(generator_paths "")

    SetGeneralGeneratorVariables("${generator_root_dir}")

    # creates absolute paths for internal generators
    if(internal_generator_paths)
        set(build_internal_generator_target generator)
        foreach(generator ${internal_generator_paths})
            # generators must set to use SetGeneralGeneratorVariables
            set(generators "${generator};${generators}")
            set(generator_paths "${generator_root_dir}/${generator};${generator_paths}")
        endforeach()
    endif()

    # creates absolute paths and determine jar files for external generators
    foreach(generator ${external_generator_paths})
        set(generator_paths "${generator};${generator_paths}")
        set(GLOB tmp_external_jar_files "${generator}/*.jar")
        set(EXTERNAL_JAR_FILES "${tmp_external_jar_files};${EXTERNAL_JAR_FILES}")
    endforeach()

    # set configuration specific variables
    set(${config_name}_MODEL_DIR       "${config_root_dir}/model")
    set(${config_name}_SOURCE_GEN_DIR  "${config_src_gen_dir}")
    set(${config_name}_GEN_REPORT_XML  "${${config_name}_SOURCE_GEN_DIR}/GeneratorReport.xml")
    file(GLOB_RECURSE ${config_name}_MODEL_DEPENDENCIES ${${config_name}_MODEL_DIR}/*.arxml)    # ARXML model list

    # Debug message to print paths of used generators
    message("-- Absolute paths of generators: ${generator_paths}")

    set(${config_name}_GENERATORS_RUN_LISTS "")
    foreach(generator ${generator_paths})
        set(${config_name}_GENERATORS_RUN_LISTS "-g ${generator} ${${config_name}_GENERATORS_RUN_LISTS}")
    endforeach(generator)

    # Initially create a empty generator report to make later cmake reconfiguration with CMAKE_CONFIGURE_DEPENDS possible
    # The generator report XML will be overwritten during generation process. This forces cmake re-configuration on next make execution.
    if(NOT EXISTS "${${config_name}_GEN_REPORT_XML}")
        file(WRITE ${${config_name}_GEN_REPORT_XML} "")
    endif()

    # Force cmake reconfiguration to update the file lists of the generated files after first make run generating the sources
    set_property(DIRECTORY APPEND PROPERTY CMAKE_CONFIGURE_DEPENDS ${${config_name}_GEN_REPORT_XML})

    # -- Custom target / command for code generation. add_dependencies() to this target required for concrete executables / libraries.
    add_custom_command(
        OUTPUT
            ${${config_name}_GEN_REPORT_XML}
        COMMAND ${GENERATOR_RUN_CMD} -v
            ${${config_name}_GENERATORS_RUN_LISTS}
            -x ${${config_name}_MODEL_DIR}
            -o ${${config_name}_SOURCE_GEN_DIR}
            --saveProject
        COMMENT "Generating code for ${config_name}"
        VERBATIM
        DEPENDS
            ${${config_name}_MODEL_DEPENDENCIES}
            ${GENERATOR_JAR_FILES}
            ${EXTERNAL_JAR_FILES}
        WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
    )
    add_custom_target(src-gen-${config_name}
        DEPENDS
            ${${config_name}_GEN_REPORT_XML}   # Link to custom command which executes the code generation
            ${build_internal_generator_target} # target dependency to generator to ensure that generator JARs are build before code generation
    )

    # Add dependency to src-gen target that code is also generated for this test configuration
    add_dependencies(src-gen src-gen-${config_name})
ENDFUNCTION() # SetupSrcGenTarget

# \brief Setup dependency of target to the related code generation target.
# \details Adds dependency: {target_name} --depends--> src-gen-{config_name}
# \param target_name Target name where a dependency shall be added
# \param config_name Name of the configuration to be generated
FUNCTION(SetupSrcGenTargetDependency target_name config_name)
    # Add dependency to test configuration specific src-gen target to (re-)generate required sources
    add_dependencies(${target_name} src-gen-${config_name})
ENDFUNCTION() # SetupSrcGenTargetDependency
