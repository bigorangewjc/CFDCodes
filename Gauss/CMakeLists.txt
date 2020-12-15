cmake_minimum_required(VERSION 3.0.0)
project(GaussSolver)


aux_source_directory(${PROJECT_SOURCE_DIR} SOURCE_DIR)
include_directories(${PROJECT_SOURCE_DIR}/include)
add_subdirectory(${PROJECT_SOURCE_DIR}/src)

set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)
add_executable(${PROJECT_NAME} ${SOURCE_DIR})
target_link_libraries(${PROJECT_NAME} LIB_SRCS)
