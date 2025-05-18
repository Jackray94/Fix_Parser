find_package(Git QUIET)
if(GIT_FOUND)
    option(UPDATE_SUBMODULES "Check submodules during build" ON)
    if(NOT UPDATE_SUBMODULES)
        return()
    endif()

    message(STATUS "Project submodules list:\n${EXISTING_SUBMODULES}")
    execute_process(COMMAND ${GIT_EXECUTABLE} submodule
                    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
                    OUTPUT_VARIABLE EXISTING_SUBMODULES
                    RESULT_VARIABLE RETURN_CODE
                    OUTPUT_STRIP_TRAILING_WHITESPACE)


    message(STATUS "Updating git submodules:\n${EXISTING_SUBMODULES}")
    execute_process(COMMAND ${GIT_EXECUTABLE} submodule update --init --recursive
                    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
                    RESULT_VARIABLE RETURN_CODE)

    set(protobuf_installer_dir ${CMAKE_CURRENT_SOURCE_DIR}/install/protobuf)
                  
    execute_process(COMMAND ${GIT_EXECUTABLE} fetch --all --tags
                   WORKING_DIRECTORY ${protobuf_installer_dir}
                   RESULT_VARIABLE RETURN_CODE)
    #execute_process(COMMAND ${GIT_EXECUTABLE} checkout tags/v29.3
    execute_process(COMMAND ${GIT_EXECUTABLE} checkout tags/v21.12
                   WORKING_DIRECTORY ${protobuf_installer_dir}
                   RESULT_VARIABLE RETURN_CODE)
    execute_process(COMMAND ${GIT_EXECUTABLE} submodule update --init --recursive
                   WORKING_DIRECTORY ${protobuf_installer_dir}
                   RESULT_VARIABLE RETURN_CODE)


    if(NOT RETURN_CODE EQUAL "0")
        message(WARNING "Cannot update submodules. Git command failed with ${RETURN_CODE}")
        return()
    endif()

    message(STATUS "Git submodules updated successfully")
endif()
