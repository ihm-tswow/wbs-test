include(bxx/cmake/main.cmake)
cmake_minimum_required(VERSION 3.12)

project(wbs-test)
set(BUILD_VERSIONS "3.0.0" CACHE STRING "Blender versions to build for")
set(CMAKE_CXX_STANDARD 20)

set(SCRIPT_LIBRARIES "")
set(SCRIPT_INCLUDE_DIRECTORIES "")

foreach(version ${BUILD_VERSIONS})
  generate_blender_version(${version})
endforeach()
finish_bxx_generate()