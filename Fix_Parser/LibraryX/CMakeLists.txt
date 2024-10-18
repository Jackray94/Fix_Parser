add_library(roughStart rough_start.cpp)

add_library(createFixMsg createFIXMessage.cpp)
target_link_libraries(createFixMsg PUBLIC cxx_setup )

add_library(random random.cpp)
target_link_libraries(random PUBLIC cxx_setup )

target_link_libraries(roughStart PUBLIC cxx_setup createFixMsg random spdlog)
