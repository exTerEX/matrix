cmake_minimum_required(VERSION 3.0.0)
project(Matrix)

set(CMAKE_PATCH_VERSION 0)
set(CMAKE_MINOR_VERSION 1)
set(CMAKE_MAJOR_VERSION 1)

include(CTest)
include(CPack)

enable_testing()

set(EXECUTABLE_OUTPUT_PATH "/Matrix/")
set(LIBRARY_OUTPUT_PATH "/Matrix/")

# Variables
set(FilesToIncludeInMatrixExe
    "main.cpp"
    "src/MatrixTemplate.h"
    #"src/Matrix.cpp"
)

#set(FilesToIncludeInMatrixLib
#    "src/Matrix.h"
#    "src/Matrix.cpp"
#)

add_executable(Matrix ${FilesToIncludeInMatrixExe})
# add_library(Matrix ${FilesToIncludeInMatrixLib})

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})