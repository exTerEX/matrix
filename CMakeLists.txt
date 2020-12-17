cmake_minimum_required(VERSION 3.8 FATAL_ERROR)

# https://medium.com/heuristics/c-application-development-part-3-cmakelists-txt-from-scratch-7678253e5e24
# https://dominikberner.ch/cmake-interface-lib/
# https://stackoverflow.com/questions/17511496/how-to-create-a-shared-library-with-cmake
# http://www.mariobadr.com/creating-a-header-only-library-with-cmake.html

project(
  libmatrix
  VERSION 0.1.0
  LANGUAGES CXX)

include(CTest)
include(CPack)
include(GNUInstallDirs)

# modules
add_subdirectory(${CMAKE_SOURCE_DIR}/utils/format.cmake)

# library
add_library(${PROJECT_NAME} INTERFACE)
target_include_directories(
  ${PROJECT_NAME}
  INTERFACE $<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}/include>
            $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>)

# test
