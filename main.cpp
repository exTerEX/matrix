#include <vector>
#include <string>
#include <fstream>
#include <iostream>
#include <limits>
#include <stdint.h>

//#include "src/Matrix.h"

template <typename T, typename V = unsigned>
class Matrix
{
public:
    Matrix(V* size, T data) {
        m_rowSize = size[0];
        m_colSize = size[1];
        fill_matrix(data);
    }

    void Matrix<T, V>::print() const
    {
        std::cout << "Matrix: " << std::endl;
        for (V i = 0; i < m_rowSize; i++)
        {
            for (V j = 0; j < m_colSize; j++)
            {
                std::cout << "[" << m_matrix[i][j] << "]";
            }
            std::cout << std::endl;
        }
    }

private:
    V m_rowSize, m_colSize;
	std::vector<std::vector<T>> m_matrix;

	void Matrix<T, V>::fill_matrix(T data)
    {
        m_matrix.resize(m_rowSize);
        for (V i = 0; i < m_rowSize; i++)
        {
            m_matrix[i].resize(m_colSize, data);
        }
    }
};

int main(int argc, char** argv) {
    int shape[2] = {2,2};
    Matrix<int> m1(shape, 5);
    m1.print();
}