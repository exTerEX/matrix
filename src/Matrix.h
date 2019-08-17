#include <cmath>
#include <tuple>
#include <vector>
#include <iostream>

#ifndef MATRIX_H
#define MATRIX_H


class Matrix
{
public:
    Matrix(unsigned, unsigned, double);
    Matrix(double**);
    Matrix(const Matrix&);
    ~Matrix();

    // Matrix operations
    Matrix operator+(Matrix&);
    Matrix operator-(Matrix&);
    Matrix operator*(Matrix&);
    Matrix operator/(Matrix&);
    Matrix transpose();

    // Scalar operations
    Matrix operator*(double);
    Matrix operator/(double);

    // Aesthetic Methods
    double& operator()(const unsigned&, const unsigned&);
    unsigned shape() const;
    unsigned rowSize() const;
    unsigned colSize() const;
    void print() const;

    // Power iteration
    std::tuple<Matrix, double, int> power_iteration(unsigned, double);

    // Deflation
    Matrix deflation(Matrix&, double&);

protected:

private:
    unsigned m_rowSize, m_colSize; // Make OS specific data type
    std::vector<std::vector<double>> m_matrix;
};

#endif