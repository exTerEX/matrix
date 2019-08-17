
#include <vector>

#ifndef MATRIX_H
#define MATRIX_H

// T: Data type
template<class T>
class Matrix {
public:
    // Initialize a square matrix with zero values.
    Matrix(unsigned);

    // Initialize a m*n matrix with zero values.
    Matrix(unsigned, unsigned);

    // Initialize m*n matrix with a specific value.
    Matrix(unsigned, unsigned, T);

    // Copy constructor to make copies from a given class
    Matrix(const Matrix&);

    // Initialize a matrix from a nested vector.
    Matrix(std::vector<std::vector<T>>);

    // Destructor
    ~Matrix();

    // Access and iterators
    T& operator()(const unsigned&, const unsigned&);

    // Matrix operations
    Matrix operator+(const Matrix&);
    Matrix operator-(const Matrix&);
    Matrix operator*(const Matrix&);
    Matrix operator/(const Matrix&);
    Matrix transpose();

    // Scalar operations
    Matrix operator*(T);
    Matrix operator/(T);

    // Aesthetic Methods
    // unsigned* shape() const;
    void print() const;

protected:
    unsigned getRowSize() const;
    unsigned getColSize() const;

private:
    unsigned m_rowSize, m_colSize;
    std::vector<std::vector<T>> m_matrix;

    void fill(T);
};

//
// Constructors & destructors
//

template<typename T>
Matrix<T>::Matrix(unsigned size) {
    m_rowSize = m_colSize = size;

    fill(0);
}

template<typename T>
Matrix<T>::Matrix(unsigned row, unsigned col) {
    m_rowSize = row;
    m_colSize = col;

    fill(0);
}

template<typename T>
Matrix<T>::Matrix(unsigned row, unsigned col, T data) {

    m_rowSize = row;
    m_colSize = col;

    fill(data);
}

template<typename T>
Matrix<T>::Matrix(const Matrix& n_matrix) {
    m_rowSize = n_matrix.getRowSize();
    m_colSize = n_matrix.getColSize();

    m_matrix = n_matrix.m_matrix;
}

template<typename T>
Matrix<T>::Matrix(std::vector<std::vector<T>> n_matrix) {
    m_rowSize = n_matrix.size();
    m_colSize = n_matrix[0].size();

    m_matrix = n_matrix;
}

template<typename T>
Matrix<T>::~Matrix() {}

//
// Access and iterators
//
template<typename T>
T& Matrix<T>::operator()(const unsigned& row, const unsigned& col) {
    return this->m_matrix[row][col];
}

//
// Matrix operations
//
template<typename T>
Matrix<T> Matrix<T>::operator+(const Matrix& n_matrix) {
    Matrix product(m_colSize, m_rowSize, 0.0);

    for (unsigned i = 0; i < m_rowSize; i++)
    {
        for (unsigned j = 0; j < m_colSize; j++)
        {
            product(i, j) = this->m_matrix[i][j] + n_matrix.m_matrix[i][j];
        }
    }
    return product;
}

template<typename T>
Matrix<T> Matrix<T>::operator-(const Matrix& n_matrix) {
    Matrix product(m_colSize, m_rowSize, 0.0);

    for (unsigned i = 0; i < m_rowSize; i++)
    {
        for (unsigned j = 0; j < m_colSize; j++)
        {
            product(i, j) = this->m_matrix[i][j] - n_matrix.m_matrix[i][j];
        }
    }
    return product;
}

/*template<typename T>
Matrix<T> Matrix<T>::operator*(const Matrix& n_matrix) {
    Matrix product(m_rowSize, n_matrix.getColSize(),0.0);

    if(m_colSize == n_matrix.getRowSize()) {
        double tmp = 0.0;
        for (unsigned i = 0; i < m_rowSize; i++)
        {
            for (unsigned j = 0; j < n_matrix.getColSize(); j++)
            {
                tmp = 0.0;
                for (unsigned k = 0; k < m_colSize; k++)
                {
                    tmp += m_matrix[i][k] * n_matrix.m_matrix[i][j];
                }
                product(i, j) = tmp;
            }
        }
        return product;
    } else {
        ;
    }
}*/

template<typename T>
Matrix<T> Matrix<T>::operator/(const Matrix& n_matrix) {
    ;
}

//
// Scalar operations
//
template<typename T>
Matrix<T> Matrix<T>::operator*(T scalar) {
    ;
}

template<typename T>
Matrix<T> Matrix<T>::operator/(T scalar) {
    ;
}

//
// Aesthetic Methods
//
/*template<typename T>
unsigned* Matrix<T>::shape() const {
    unsigned* tmp = {m_rowSize, m_colSize};
    return tmp;
}*/

template<typename T>
void Matrix<T>::print() const {
    std::cout << "Matrix: " << std::endl;
    for (unsigned i = 0; i < m_rowSize; i++) {
        for (unsigned j = 0; j < m_colSize; j++) {
            std::cout << "[" << m_matrix[i][j] << "]";
        }
        std::cout << std::endl;
    }
}

//
// Protected
//
template<typename T>
unsigned Matrix<T>::getRowSize() const {
    return this->m_rowSize;
}

template<typename T>
unsigned Matrix<T>::getColSize() const {
    return this->m_colSize;
}

//
// Private
//
template<typename T>
void Matrix<T>::fill(T data) {
    m_matrix.resize(m_rowSize);
    for (unsigned i = 0; i < m_rowSize; i++)
    {
        m_matrix[i].resize(m_colSize, data);
    }
}

#endif