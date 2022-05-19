cmake_minimum_required(VERSION 3.0)
project(your-project)

set(BLENDER_VERSION "3.0.0" CACHE STRING "Blender version to build for")
set(CMAKE_CXX_STANDARD 20)

set(SCRIPT_LIBRARIES "")
set(SCRIPT_INCLUDE_DIRECTORIES "")

include(bxx/cmake/generate.cmake)