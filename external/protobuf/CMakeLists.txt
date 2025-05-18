#   add_custom_command(OUTPUT address.pb.h address.pb.cc
#                     COMMAND ${CMAKE_CURRENT_SOURCE_DIR}/bin/protoc -I=${CMAKE_CURRENT_SOURCE_DIR} --cpp_out=. address.proto)
#
#   include_directories(${CMAKE_CURRENT_BINARY_DIR})
#   include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)
#
#   add_library(generated_proto ${CMAKE_CURRENT_BINARY_DIR}/address.pb.h ${CMAKE_CURRENT_BINARY_DIR}/address.pb.cc)
#
#   set(PROTOBUF_USE_STATIC_LIBS ON)
#
#   find_package(Protobuf REQUIRED CONFIG PATHS ${CMAKE_CURRENT_SOURCE_DIR}/lib/cmake)
#
#   add_library(app apple.cpp)
#
#   target_link_libraries(app PRIVATE protobuf::libprotobuf generated_proto)

  add_custom_command(OUTPUT fixMessage.pb.h fixMessage.pb.cc
    COMMAND ${CMAKE_CURRENT_SOURCE_DIR}/bin/protoc -I=${CMAKE_CURRENT_SOURCE_DIR} --cpp_out=. fixMessage.proto)

  include_directories(${CMAKE_CURRENT_BINARY_DIR})
  include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)

  add_library(generated_proto ${CMAKE_CURRENT_BINARY_DIR}/fixMessage.pb.h ${CMAKE_CURRENT_BINARY_DIR}/fixMessage.pb.cc)

  set(PROTOBUF_USE_STATIC_LIBS ON)

  find_package(Protobuf REQUIRED CONFIG PATHS ${CMAKE_CURRENT_SOURCE_DIR}/lib/cmake)
  
  target_link_libraries(generated_proto protobuf::libprotobuf)

  #add_library(app apple.cpp)

  #target_link_libraries(app PRIVATE protobuf::libprotobuf generated_proto)
