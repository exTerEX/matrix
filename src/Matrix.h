#include <vector>
#include <iostream>

#ifndef MATRIX_H
#define MATRIX_H

// T: Data type, V: Index integer type
template<typename T, typename V = unsigned>
class Matrix {
public:
    // Initialize a square matrix
    Matrix(V);

    // Initialize a m*n matrix
    Matrix(V, V);

    // Initialize m*n matrix with value.
    Matrix(V, V, T);

    // Copy constructor
    Matrix(const Matrix&);

    // Initialize a matrix from vector.
    Matrix(std::vector<T>);

    // Initialize a matrix from nested vector.
    Matrix(std::vector<std::vector<T>>);

    // Destructor
    ~Matrix();

    // Access and iterators
    T& operator()(const V&, const V&);

    // Matrix operations
    Matrix operator+(const Matrix&);
    Matrix operator-(const Matrix&);
    Matrix operator*(const Matrix&);
    Matrix operator^(T); // ni
    Matrix operator^(char*); // ni
    Matrix transpose();

    // Essential digital operators
    void operator=(const Matrix&); // ni
    void operator+=(const Matrix&); // ni
    void operator-=(const Matrix&); // ni
    void operator*=(const Matrix&); // ni

    // Boolean operators
    bool operator==(const Matrix&);
    bool operator!=(const Matrix&);
    bool operator<(const Matrix&); // ni
    bool operator>(const Matrix&); // ni
    bool operator<=(const Matrix&); // ni
    bool operator>=(const Matrix&); // ni

    // Scalar operations
    Matrix operator*(T);
    Matrix operator/(T);

    // Matrix functions
    Matrix inverse(const Matrix&); // nfi
    T determinant(const Matrix&) // ni

    // Aesthetic Methods
    V shape() const; // nfi
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