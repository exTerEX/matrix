#include <vector>
#include <string>
#include <fstream>
#include <iostream>
#include <limits>
#include <stdint.h>

#include "src/Matrix.h"

int main(int argc, char **argv)
{
    int shape[2] = {2, 2};
    Matrix<int> m1(shape, 5);
    m1.print();
}