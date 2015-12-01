cmake_minimum_required(VERSION 2.8)

project(braf)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -g -std=c11 -O3")

add_library(braf_l STATIC src/util.c src/error_check.c src/braf.c)
add_executable(braf src/interactive_mode.c src/main.c)
target_link_libraries(braf braf_l)
install(TARGETS braf DESTINATION bin)
install(TARGETS braf_l DESTINATION bin)
install(FILES src/braf.h DESTINATION include)
