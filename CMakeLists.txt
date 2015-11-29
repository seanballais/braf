cmake_minimum_required(VERSION 2.8)

project(braf)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -std=c11 -O3")

add_library(braf_l STATIC src/braf.c src/error_check.c src/util.c)
add_executable(braf src/main.c src/interactive_mode.c)
target_link_libraries(braf braf_l)
install(TARGETS braf DESTINATION bin)
install(TARGETS braf_l DESTINATION bin)
install(FILES src/braf.h DESTINATION include)
