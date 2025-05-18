#add_executable(spdlogTutorial spdlog_tutorial.cpp)
#target_link_libraries(spdlogTutorial PRIVATE cxx_setup spdlog app)

add_executable(main main.cpp)
#target_link_libraries(main PRIVATE tools cxx_setup spdlog)
#target_link_libraries(main PRIVATE roughStart messageFields cxx_setup spdlog)
target_link_libraries(main PRIVATE spdlog roughStart messageFields cxx_setup)
