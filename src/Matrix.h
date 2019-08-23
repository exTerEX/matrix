#include <vector>
#include <iostream>

#ifndef MATRIX_H
#define MATRIX_H

// T: Data type, V: Index integer type
template<typename T, typename V = unsigned>
class Matrix {
public:
    // Initialize a square matrix with zero values.
    Matrix(V);

    // Initialize a m*n matrix with zero values.
    Matrix(V, V);

    // Initialize m*n matrix with a specific value.
    Matrix(V, V, T);

    // Copy constructor to make copies from a given class
    Matrix(const Matrix&);

    // Initialize a matrix from a vector.
    Matrix(std::vector<T>);

    // Initialize a matrix from a nested vector.
    Matrix(std::vector<std::vector<T>>);

    // Destructor<
    ~Matrix();

    // Access and iterators
    T& operator()(const V&, const V&);

    // Matrix operations
    Matrix operator+(const Matrix&);
    Matrix operator-(const Matrix&);
    Matrix operator*(const Matrix&);
    Matrix transpose();
    Matrix inverse(const Matrix&);

    // Scalar operations
    Matrix operator*(T);
    Matrix operator/(T);

    // Aesthetic Methods
    V shape() const; // must be implemented
    void print() const;

protected:
    V getRowSize() const;
    V getColSize() const;

private:
    V m_rowSize, m_colSize;
    std::vector<std::vector<T>> m_matrix;

    void fill(T);

};

#endif