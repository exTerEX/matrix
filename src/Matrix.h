#include <vector>
#include <iostream>

#ifndef MATRIX_H
#define MATRIX_H

// T: Data type, V: Index integer type
template<typename T, typename V = unsigned>
class Matrix {
public:
    // Initialize a matrix with parameters.
    Matrix(V);
    Matrix(V, V);
    Matrix(V, V, T);

    // Copy constructor
    Matrix(const Matrix&);

    // Initialize a matrix from vector.
    Matrix(std::vector<T>);
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
    Matrix transpose();

    // Boolean operators
    bool operator==(const Matrix&);
    bool operator!=(const Matrix&);

    // Scalar operations
    Matrix operator*(T);

    // Matrix functions
    Matrix inverse(const Matrix&); // ni
    T determinant(const Matrix&); // ni

    // Aesthetic Methods
    V shape() const; // ni
    void print() const;

protected:
    V getRowSize() const;
    V getColSize() const;

private:
    V m_rowSize, m_colSize;
    std::vector<std::vector<T>> m_matrix;

    void fill_matrix(T);

};

#endif