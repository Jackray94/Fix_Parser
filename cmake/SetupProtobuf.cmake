    message(STATUS "Setting up Protocol Buffer:\n")

    set(protobuf_dir ${CMAKE_CURRENT_SOURCE_DIR}/external/protobuf )
    #set(abseil_dir ${CMAKE_CURRENT_SOURCE_DIR}/external/abseil-cpp)
    set(protobuf_installer_dir ${CMAKE_CURRENT_SOURCE_DIR}/install/protobuf)

    execute_process(COMMAND ${CMAKE_COMMAND} -E make_directory ${protobuf_installer_dir}/build
                   WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
                   RESULT_VARIABLE RETURN_CODE)

    execute_process(COMMAND ${CMAKE_COMMAND} cmake .. -DCMAKE_INSTALL_PREFIX=${protobuf_dir} -DCMAKE_CXX_STANDARD=20 
                    WORKING_DIRECTORY ${protobuf_installer_dir}/build
                    RESULT_VARIABLE RETURN_CODE)

    execute_process(COMMAND ${CMAKE_COMMAND} --build . --target install --parallel 10
                    WORKING_DIRECTORY ${protobuf_installer_dir}/build
                    RESULT_VARIABLE RETURN_CODE)
