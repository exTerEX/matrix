
#include <vector>

#ifndef MATRIX_H
#define MATRIX_H

// T: Data type, V: Index integer type
template<typename T, typename V>
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
    Matrix inverse();

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

//
// Constructors & destructors
//
template<typename T, typename V>
Matrix<T, V>::Matrix(V size) {
    m_rowSize = m_colSize = size;

    fill(0);
}

template<typename T, typename V>
Matrix<T, V>::Matrix(V row, V col) {
    m_rowSize = row;
    m_colSize = col;

    fill(0);
}

template<typename T, typename V>
Matrix<T, V>::Matrix(V row, V col, T data) {
    m_rowSize = row;
    m_colSize = col;

    fill(data);
}

template<typename T, typename V>
Matrix<T, V>::Matrix(const Matrix& n_matrix) {
    m_rowSize = n_matrix.getRowSize();
    m_colSize = n_matrix.getColSize();

    m_matrix = n_matrix.m_matrix;
}

template<typename T, typename V>
Matrix<T, V>::Matrix(std::vector<T> n_matrix) {
    m_rowSize = n_matrix.size();
    m_colSize = 1;

    m_matrix.resize(m_rowSize);
    for (V i = 0; i < m_rowSize; i++)
    {
        m_matrix[i].resize(m_colSize, n_matrix[i]);
    }
}

template<typename T, typename V>
Matrix<T, V>::Matrix(std::vector<std::vector<T>> n_matrix) {
    m_rowSize = n_matrix.size();
    m_colSize = n_matrix[0].size();

    m_matrix = n_matrix;
}

template<typename T, typename V>
Matrix<T, V>::~Matrix() {}

//
// Access and iterators
//
template<typename T, typename V>
T& Matrix<T, V>::operator()(const V& row, const V& col) {
    return this->m_matrix[row][col];
}

//
// Matrix operations
//
template<typename T, typename V>
Matrix<T, V> Matrix<T, V>::operator+(const Matrix& n_matrix) {
    Matrix product(m_colSize, m_rowSize, 0.0);

    for (V i = 0; i < m_rowSize; i++)
    {
        for (V j = 0; j < m_colSize; j++)
        {
            product(i, j) = this->m_matrix[i][j] + n_matrix.m_matrix[i][j];
        }
    }
    return product;
}

template<typename T, typename V>
Matrix<T, V> Matrix<T, V>::operator-(const Matrix& n_matrix) {
    Matrix product(m_colSize, m_rowSize, 0.0);

    for (V i = 0; i < m_rowSize; i++)
    {
        for (V j = 0; j < m_colSize; j++)
        {
            product(i, j) = this->m_matrix[i][j] - n_matrix.m_matrix[i][j];
        }
    }
    return product;
}

template<typename T, typename V>
Matrix<T, V> Matrix<T, V>::operator*(const Matrix& n_matrix) {
    Matrix product(m_rowSize, n_matrix.getColSize(), 0.0);

    if(m_colSize == n_matrix.getRowSize()) {
        T tmp = 0.0;
        for (V i = 0; i < m_rowSize; i++)
        {
            for (V j = 0; j < n_matrix.getColSize(); j++)
            {
                tmp = 0.0;
                for (V k = 0; k < m_colSize; k++)
                {
                    tmp += m_matrix[i][k] * n_matrix.m_matrix[i][j];
                }
                product(i, j) = tmp;
            }
        }
        return product;
    }
}

template<typename T, typename V>
Matrix<T, V> Matrix<T, V>::transpose() {
    Matrix product(m_colSize, m_rowSize, 0.0);

    for (V i = 0; i < m_colSize; i++)
    {
        for (V j = 0; j < m_rowSize; j++) {
            product(i,j) = this->m_matrix[j][i];
        }
    }
    return product;
}

template<typename T, typename V>
Matrix<T, V> Matrix<T, V>::inverse() {
    ;
}

//
// Scalar operations
//
template<typename T, typename V>
Matrix<T, V> Matrix<T, V>::operator*(T scalar) {
    Matrix product(m_rowSize, m_colSize, 0.0);

    for (V i = 0; i < m_rowSize; i++)
    {
        for (V j = 0; j < m_colSize; j++)
        {
            product(i, j) = this->m_matrix[i][j] * scalar;
        }
    }
    return product;
}

//
// Aesthetic Methods
//


template<typename T, typename V>
void Matrix<T, V>::print() const {
    std::cout << "Matrix: " << std::endl;
    for (V i = 0; i < m_rowSize; i++) {
        for (V j = 0; j < m_colSize; j++) {
            std::cout << "[" << m_matrix[i][j] << "]";
        }
        std::cout << std::endl;
    }
}

//
// Protected
//
template<typename T, typename V>
V Matrix<T, V>::getRowSize() const {
    return this->m_rowSize;
}

template<typename T, typename V>
V Matrix<T, V>::getColSize() const {
    return this->m_colSize;
}

//
// Private
//
template<typename T, typename V>
void Matrix<T, V>::fill(T data) {
    m_matrix.resize(m_rowSize);
    for (V i = 0; i < m_rowSize; i++)
    {
        m_matrix[i].resize(m_colSize, data);
    }
}

#endif