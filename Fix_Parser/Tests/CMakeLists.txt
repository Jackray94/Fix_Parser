if(BUILD_TESTING)

  add_executable(my_test my_test.cpp)
  #target_link_libraries(my_test PRIVATE GTest::gtest_main tools)
  target_link_libraries(my_test PRIVATE GTest::gtest_main random roughStart)

  include(GoogleTest)
  gtest_discover_tests(my_test)

endif()
