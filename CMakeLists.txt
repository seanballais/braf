cmake_minimum_required(VERSION 2.8)

project(braf)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -std=c11 -O3 -lcs50")

# Add a debug definition if the build type is a debug
if (CMAKE_BUILD_TYPE STREQUAL "Debug" OR CMAKE_BUILD_TYPE STREQUAL "DEBUG")
    add_definitions(-DDEBUG)
    message(STATUS "Yep! We're going for debug this time.")
endif ()

add_library(libbraf SHARED src/braf.c)
add_executable(braf src/main.c)
target_link_libraries(braf libbraf)
install(TARGETS braf DESTINATION bin)
install(TARGETS libbraf DESTINATION bin)
install(FILES src/braf.h DESTINATION include)
