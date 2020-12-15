cmake_minimum_required(VERSION 3.0.0)

aux_source_directory(. SUB_SRC)
add_library (LIB_SRCS ${SUB_SRC})
