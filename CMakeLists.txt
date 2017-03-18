cmake_minimum_required(VERSION 2.8)

project(RubCube)
file(GLOB_RECURSE cube_SRC "*.cpp" "*.hpp")
include_directories (${PROJECT_SOURCE_DIR}/include)
add_executable(${PROJECT_NAME} ${cube_SRC})
