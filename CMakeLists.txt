cmake_minimum_required(VERSION 3.30)
project(supermarket_manager)

set(CMAKE_CXX_STANDARD 20)
file(GLOB_RECURSE SOURCES "${CMAKE_SOURCE_DIR}/*.cpp")
list(FILTER SOURCES EXCLUDE REGEX "CMakeFiles/.*CompilerIdCXX.*")
add_executable(${PROJECT_NAME} ${SOURCES})

