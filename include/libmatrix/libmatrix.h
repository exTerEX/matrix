#include <vector>

#ifndef LIBMATRIX_H
#define LIBMATRIX_H

template <class T> // (T)ype
class matrix
{
private:
    unsigned m_rowSize, m_colSize;
    std::vector<std::vector<T>> data;

    void fill_matrix(T);

protected:
    unsigned getRowSize() const;
    unsigned getColSize() const;

public:
    matrix(unsigned, T fill = NULL);
    matrix(unsigned, unsigned, T fill = NULL);
    ~matrix();

    matrix(std::vector<T>);
    // matrix(std::vector <std::vector <T>>);

    // Operators
    matrix operator[](unsigned);
    matrix operator+(const matrix &);
    matrix operator*(T);
    matrix operator*(const matrix &);
    matrix operator^(T);

    matrix transpose();
    Matrix inverse(const matrix &);
    T determinant(const matrix &);
    unsigned shape() const;
    void print() const;

    bool operator==(const matrix &);
    bool operator!=(const matrix &);
};

#endif