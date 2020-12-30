cmake_minimum_required(VERSION 3.12 FATAL_ERROR)

project(
  matrix
  LANGUAGES CXX
  VERSION 0.1.0)

set(CMAKE_CXX_STANDARD 11)

include(CTest)
include(CPack)

enable_testing()

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

# library
include_directories("${CMAKE_CURRENT_SOURCE_DIR}/include")
add_library(lib${PROJECT_NAME} INTERFACE)

# example
add_executable(${PROJECT_NAME} main.cpp)

# python bindings
find_package(Python COMPONENTS Interpreter Development)

if(${Python_FOUND} AND ${Python_VERSION} GREATER_EQUAL "3.6")
  if(${Python_Development_FOUND})

  else()
    message(WARNING "Cannot find Python3-dev library.")
  endif()
else()
  message(WARNING "Python requirements not met to build bindings.")
endif()

# test
file(GLOB tests "tests/**/test_*.cpp")

foreach(file ${tests})
  add_executable(ext ${file})
  add_test(${file} COMMAND ${ext})
  set_tests_properties(${file} PROPERTIES TIMEOUT 120)
endforeach()
