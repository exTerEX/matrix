cmake_minimum_required(VERSION 3.12 FATAL_ERROR)

project(
  matrix
  LANGUAGES C CXX
  VERSION 0.1.0)

set(CMAKE_CXX_STANDARD 11)

include(CPack)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

# output folders
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/dist)

# suffix
set(CMAKE_EXECUTABLE_SUFFIX .exe)

# library
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)
add_library(lib${PROJECT_NAME} INTERFACE)

# example
add_executable(${PROJECT_NAME} main.cpp)

# python bindings
find_package(Python COMPONENTS Interpreter Development)

if(${Python_FOUND} AND ${Python_VERSION} GREATER_EQUAL 3.6)
  if(${Python_Development_FOUND})

  else()
    message(WARNING "Cannot find Python3-dev library.")
  endif()
else()
  message(WARNING "Python requirements not met to build bindings.")
endif()

# Test
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})

include(CTest)

# List of files to run as test
file(GLOB tests "tests/**/test_*.cpp")

foreach(file ${tests})
  # Create filename without extension
  string(REGEX REPLACE "(^.*/|\\.[^.]*$)" "" name ${file})

  # Build test executable
  add_executable(${name} ${file})

  # Test executable with CTest
  add_test(${name} ${name})

  # Test properties
  set_tests_properties(
    ${name} PROPERTIES FAIL_REGULAR_EXPRESSION "(Exception|Assertion|failed.)"
                       TIMEOUT 120)
endforeach()

enable_testing()
