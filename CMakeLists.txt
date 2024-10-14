cmake_minimum_required(VERSION 3.16..3.24)
project(our_project 
  VERSION 0.0.1
  DESCRIPTION "Our first project"
  LANGUAGES CXX
  )

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

if(NOT CMAKE_BUILD_TYPE) #<sets the build type to release by default, if its not aleady set from command line
  set(CMAKE_BUILD_TYPE Release CACHE STRING "" FORCE)
endif()
message(STATUS "CMAKE_BUILD_TYPE: ${CMAKE_BUILD_TYPE}")

add_library(cxx_setup INTERFACE) #Not really a library, just another target with an interface property which has properties we want to maintain throughout our project

target_compile_options(cxx_setup INTERFACE -Wall -Wpedantic -Wextra)
target_compile_features(cxx_setup INTERFACE cxx_std_20)
target_include_directories(cxx_setup INTERFACE ${PROJECT_SOURCE_DIR})


include (cmake/UpdateSubmodules.cmake)
include(CTest)

add_subdirectory(external)
add_subdirectory(${PROJECT_NAME})
add_subdirectory(executables)#<Or, "examples"

