cmake_minimum_required(VERSION 2.8)

project(test)

set(TORCH_URI_PATH "${CMAKE_CURRENT_SOURCE_DIR}/..")
add_subdirectory(${TORCH_URI_PATH} "${CMAKE_CURRENT_SOURCE_DIR}/build-parser")

add_executable(test main.cpp)
include_directories(${TORCH_URI_PATH}/Include)

target_link_libraries(test TORCH_URIPARSER)
