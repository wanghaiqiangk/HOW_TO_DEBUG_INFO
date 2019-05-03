cmake_minimum_required(VERSION 2.8)
project(colorful_debug)

set(CMAKE_BUILD_TYPE Release)

include_directories(${PROJECT_SOURCE_DIR}/src)

set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)

add_executable(${PROJECT_NAME} test.cpp)
target_compile_options(${PROJECT_NAME} PRIVATE $<$<COMPILE_LANGUAGE:CXX>:-std=c++11>)
target_compile_definitions(${PROJECT_NAME} PRIVATE -DDEBUG)
