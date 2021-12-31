cmake_minimum_required(VERSION 3.0)

project(CallbackTestDemo)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)

aux_source_directory(${CMAKE_CURRENT_SOURCE_DIR}/src SRC_FILES)

add_executable(main ${SRC_FILES} main.cpp)


