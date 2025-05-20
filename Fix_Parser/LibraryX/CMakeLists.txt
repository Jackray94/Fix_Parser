add_library(roughStart rough_start.cpp)

add_library(createFixMsg createFIXMessage.cpp)
target_link_libraries(createFixMsg PUBLIC cxx_setup )

add_library(random random.cpp)
target_link_libraries(random PUBLIC cxx_setup )

include_directories(${CMAKE_CURRENT_BINARY_DIR}/../../external/protobuf)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/../../external/protobuf)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/../../external/protobuf/include)


#add_library(generated_proto ${CMAKE_CURRENT_BINARY_DIR}/../../external/protobuf/fixMessage.pb.h ${CMAKE_CURRENT_BINARY_DIR}/../../external/protobuf/fixMessage.pb.cc)

add_library(messageFields messageFields.cpp)
add_library(fieldsSerializer fieldsSerializer.cpp)
#target_link_libraries(messageFields PRIVATE protobuf::libprotobuf generated_proto)
target_link_libraries(messageFields PRIVATE generated_proto)
target_link_libraries(fieldsSerializer PRIVATE generated_proto)

target_link_libraries(roughStart PUBLIC cxx_setup random spdlog)
