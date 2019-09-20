cmake_minimum_required(VERSION 3.0.0)
project(Matrix)

set(CMAKE_PATCH_VERSION 0)
set(CMAKE_MINOR_VERSION 1)
set(CMAKE_MAJOR_VERSION 1)

include(CTest)
include(CPack)

enable_testing()

set(EXECUTABLE_OUTPUT_PATH "/Matrix/bin/")
set(LIBRARY_OUTPUT_PATH "/Matrix/bin/")

# Variables
set(FilesToIncludeInMatrixExe
    "main.cpp"
    "src/Matrix.h"
    "src/Matrix.cpp"
)

set(FilesToIncludeInMatrixLib
    "src/Matrix.h"
    "src/Matrix.cpp"
)

add_executable(Matrix ${FilesToIncludeInMatrixExe})
add_library(MatrixLib STATIC ${FilesToIncludeInMatrixLib})

add_test(square_int_test sit "test/int_square_matrix_test.cpp")
add_test(square_float_test sft "test/float_square_matrix_test.cpp")
add_test(square_double_test sdt "test/double_square_matrix_test.cpp")
add_test(mn_int_test mit "test/int_mn_matrix_test.cpp")
add_test(mn_float_test mft "test/float_mn_matrix_test.cpp")
add_test(mn_double_test mdt "test/double_mn_matrix_test.cpp")
add_test(vector_int_test vit "test/int_vector_matrix_test.cpp")
add_test(vector_float_test vft "test/float_vector_matrix_test.cpp")
add_test(vector_double_test vdt "test/double_vector_matrix_test.cpp")

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})