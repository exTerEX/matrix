#include "Matrix.h"

// Initialize a Matrix of m x n with a single numerical value.
Matrix::Matrix(unsigned m_rowSize, unsigned m_colSize, double data) {
    m_rowSize = m_rowSize;
    m_colSize = m_colSize;

    m_matrix.resize(m_rowSize);
    for (unsigned i = 0; i < m_matrix.size(); i++)
    {
        m_matrix[i].resize(m_colSize, data);
    }
}

// Initialize a Matrix from a nested array.
Matrix::Matrix(double** n_matrix) {
    ;
}

// Initialize a Matrix from another Matrix object.
Matrix::Matrix(const Matrix& n_matrix) {

}

// Operator to allow for addition of Matrix objects like M + N.
Matrix Matrix::operator+(Matrix& n_matrix) {
    Matrix sum(m_rowSize, m_colSize, 0.0);

    for (unsigned i = 0; i < m_rowSize; i++) {
        for (unsigned j = 0; j < m_colSize; j++) {
            sum(i, j) = this->m_matrix[i][j] + n_matrix(i, j);
        }
    }
    return sum;
}

// Operator to allow for subtraction of Matrix objects like M - N.
Matrix Matrix::operator-(Matrix& n_matrix) {
    Matrix diff(m_rowSize, m_colSize, 0.0);

    for (unsigned i = 0; i < m_rowSize; i++) {
        for (unsigned j = 0; j < m_colSize; j++) {
            diff(i, j) = this->m_matrix[i][j] - n_matrix(i, j);
        }
    }
    return diff;
}
/*
// Operator to allow for multiplication of Matrix objects like M*N.
Matrix Matrix::operator*(Matrix& n_matrix) {
    Matrix product(m_rowSize, n_matrix.m_colSize(), 0.0);
    
    if (m_colSize == n_matrix.rowSize())
    {
        double tmp = 0.0;
        for (unsigned i = 0; i < m_rowSize; i++) {
            for (unsigned j = 0; j < n_matrix.m_colSize(); j++) {
                tmp = 0.0;
                for (unsigned k = 0; k < m_rowSize; k++) {
                    tmp += m_matrix[i][k] * n_matrix(k, j);
                }
                product(i, j) = tmp;
            }
        }
        return product;
    }
    else
    {
        std::cout << "Error!" << std::endl; // Add some sort of exception handler.
    }
}

// Operator to allow for division of Matrix objects like M/N.
Matrix Matrix::operator/(Matrix& n_matrix) {

}*/

// Transponse operation on Matrix.
Matrix Matrix::transpose() {
    Matrix Transpose(m_rowSize, m_colSize, 0.0);

    for (unsigned i = 0; i < m_colSize; i++) {
        for (unsigned j = 0; j < m_rowSize; j++) {
            Transpose(i, j) = this->m_matrix[j][i];
        }
    }
    return Transpose;
}

// Operator to allow scalar multiplication on a Matrix.
Matrix Matrix::operator*(double scalar) {
    Matrix result(m_rowSize, m_colSize, 0.0);

    for (unsigned i = 0; i < m_rowSize; i++)
    {
        for (unsigned j = 0; j < m_colSize; j++)
        {
            result(i, j) = this->m_matrix[i][j] * scalar;
        }
    }
    return result;
}

// Operator to allow scalar division on a Matrix.
Matrix Matrix::operator/(double scalar) {
    Matrix result(m_rowSize, m_colSize, 0.0);
    
    for (unsigned i = 0; i < m_rowSize; i++)
    {
        for (unsigned j = 0; j < m_colSize; j++)
        {
            result(i, j) = this->m_matrix[i][j] / scalar;
        }
    }
    return result;
}

// Operator to return the value in a position like (row, col).
double& Matrix::operator()(const unsigned& row, const unsigned& col)
{
    return this->m_matrix[row][col];
}

// A function to return an array with the size of column and the row like this (row, col).
unsigned Matrix::shape() const {
    return this->rowSize(), this->m_colSize();
}

// Function to return row size.
unsigned Matrix::rowSize() const {
    return this->m_rowSize;
}

// Function to return column size.
unsigned Matrix::m_colSize() const {
    return this->m_colSize;
}

// Function to print out the Matrix.
void Matrix::print() const {
    std::cout << "Matrix: " << std::endl;

    for (unsigned i = 0; i < m_rowSize; i++) {
        for (unsigned j = 0; j < m_colSize; j++) {
            std::cout << "[" << m_matrix[i][j] << "]";
        }
        std::cout << std::endl;
    }
}

/*
// Power iteration.
std::tuple<Matrix, double, int> power_iteration(unsigned num, double tol) {
    Matrix X(num, 1, 1.0);

    for (unsigned i = 1; i <= num; i++) {
        X(i - 1, 0) = i;
    }

    int errorCode = 0;
    double difference = 1.0;

    unsigned j = 0;
    unsigned location;

    std::vector<double> eigen;
    double eigenvalue = 0.0;
    eigen.push_back(0.0);

    while (abs(difference) > tol)
    {
        j++;
        
        for (int i = 0; i < num; ++i) {
            eigenvalue = X(0, 0);

            if (abs(X(i, 0)) >= abs(eigenvalue)) {
                eigenvalue = X(i, 0);
                location = i;
            }
        }

        if (j >= 5e5) {
            std::cout << "Oops, that was a nasty complex number wasn't it?" << std::endl;
            std::cout << "ERROR! Returning code black, code black!";
            errorCode = -1;
            return std::make_tuple(X, 0.0, errorCode);
        }

        eigen.push_back(eigenvalue);
        difference = eigen[j] - eigen[j - 1];

        X = X / eigenvalue;

        X = (*this) * X; // Need to be fixed | X = (*this) * X;
    }

    X = X / eigenvalue;

    return std::make_tuple(X, eigenvalue, errorCode);
}

// Deflation.
Matrix deflation(Matrix& X, double& eigenvalue) {
    double denominator = eigenvalue / (X.transpose() * X)(0, 0);

    Matrix x_trans = X.transpose();
    Matrix RHS = (X * x_trans);
    Matrix RHS2 = RHS * denominator;
    Matrix A2 = (*this) - RHS2; // Need to be fixed | Matrix A2 = *this - RHS2;
    return A2;
}*/