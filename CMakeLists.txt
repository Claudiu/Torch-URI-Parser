cmake_minimum_required (VERSION 2.8.11)
project(TORCH_URIPARSER)

set(CMAKE_BUILD_TYPE Release)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)

set(TORCH_URIPARSER_SOURCES
		Src/uriparser.cpp
)

add_library(TORCH_URIPASER ${TORCH_URIPARSER_SOURCES})
#target_link_libraries(TORCH_URIPARSER)
