cmake_minimum_required(VERSION 3.8 FATAL_ERROR)

project(
  libmatrix
  VERSION 0.1.0
  LANGUAGES C CXX)

include(CTest)
include(CPack)
include(GNUInstallDirs)

# library
add_library(${PROJECT_NAME} INTERFACE)
target_include_directories(
  ${PROJECT_NAME} INTERFACE $<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}/include>
                            $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>)

# test
add_executable(binary main.cpp)
