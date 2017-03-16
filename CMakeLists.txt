cmake_minimum_required(VERSION 2.8)

project(RubCube)
file(GLOB cube_SRC "*.cpp" "*.hpp")
add_executable(${PROJECT_NAME} ${cube_SRC})
