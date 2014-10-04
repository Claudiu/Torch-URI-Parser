cmake_minimum_required (VERSION 2.8)
project(TORCH_URIPARSER)

set(CMAKE_BUILD_TYPE Release)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/Include)

set(TORCH_URIPARSER_INCLUDES
	Include/torch/uriparser.hpp
)

set(TORCH_URIPARSER_SOURCES
		Src/uriparser.cpp
)

add_library(${PROJECT_NAME} ${${PROJECT_NAME}_SOURCES} ${${PROJECT_NAME}_INCLUDES})
#target_link_libraries(TORCH_URIPARSER)
