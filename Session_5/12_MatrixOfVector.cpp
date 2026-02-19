#include<iostream>
#include<vector>


class CMatrix{
private:
    std::vector<std::vector<int>> m_data;
    int m_rows;
    int m_cols;

public:
    CMatrix(int rows, int cols) : m_rows(rows), m_cols(cols) {
        m_data.resize(m_rows, std::vector<int>(m_cols, 0));
    }

    void input(int row, int col, int value) {
        if (row >= 0 && row < m_rows && col >= 0 && col < m_cols) {
            m_data[row][col] = value;
        }
    }

    void display() {
        for (int i = 0; i < m_rows; ++i) {
            for (int j = 0; j < m_cols; ++j) {
                std::cout << m_data[i][j] << " ";
            }
            std::cout << std::endl;
        }
    }

    CMatrix multiply(CMatrix& other) {
        if (other.m_cols != m_cols || other.m_rows != 1) {
            throw std::invalid_argument("Vector size must match the number of columns in the matrix.");
        }

        CMatrix result(m_rows, 1);
        for (int i = 0; i < m_rows; ++i) {
            int sum = 0;
            for (int j = 0; j < m_cols; ++j) {
                sum += m_data[i][j] * other.m_data[0][j];
            }
            result.input(i, 0, sum);
        }
        return result;
    }

    CMatrix add(CMatrix& other) {
        if (other.m_rows != m_rows || other.m_cols != m_cols) {
            throw std::invalid_argument("Matrices must have the same dimensions for addition.");
        }

        CMatrix result(m_rows, m_cols);
        for (int i = 0; i < m_rows; ++i) {
            for (int j = 0; j < m_cols; ++j) {
                result.input(i, j, m_data[i][j] + other.m_data[i][j]);
            }
        }
        return result;
    }


};



int main() {
    CMatrix matrix(2, 3);
    matrix.input(0, 0, 1);
    matrix.input(0, 1, 2);
    matrix.input(0, 2, 3);
    matrix.input(1, 0, 4);
    matrix.input(1, 1, 5);
    matrix.input(1, 2, 6);

    std::cout << "Matrix:" << std::endl;
    matrix.display();

    CMatrix vector(1, 3);
    vector.input(0, 0, 7);
    vector.input(0, 1, 8);
    vector.input(0, 2, 9);

    std::cout << "Vector:" << std::endl;
    vector.display();

    CMatrix result = matrix.multiply(vector);
    std::cout << "Result of Matrix-Vector Multiplication:" << std::endl;
    result.display();

    return 0;
}