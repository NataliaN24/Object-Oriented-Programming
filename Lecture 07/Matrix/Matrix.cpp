#include "Matrix.h"

void Matrix::allocate()
{
    matrix = new int* [rows];
    for (int i = 0; i < rows; ++i)
    {
        matrix[i] = new int[cols];
    }
}

void Matrix::copyFrom(const Matrix& other)
{
    rows = other.rows;
    cols = other.cols;
    allocate();
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            matrix[i][j] = other.matrix[i][j];
        }
    }
}

void Matrix::free()
{
    for (int i = 0; i < rows; i++)
    {
        delete[]matrix[i];
    }
    delete[]matrix;
}

Matrix::Matrix():Matrix(rowsValue,colsValue)
{
}

Matrix::Matrix(int m, int n):rows(m),cols(n)
{
    allocate();
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            matrix[i][j] = 0;
        }
    }
}

Matrix& Matrix::operator=(const Matrix& other)
{
    if (this != &other)
    {
        free();
        copyFrom(other);
    }
    return *this;
}

Matrix::Matrix(const Matrix& other)
{
    copyFrom(other);
}

Matrix::~Matrix()
{
    free();
}

Matrix& Matrix::operator+=(const Matrix& other)
{
    if (rows != other.rows || cols != other.cols)
    {
        return *this;
    }
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            matrix[i][j] += other.matrix[i][j];
        }
    }
    return *this;
    
    
}

Matrix& Matrix::operator-=(const Matrix& other)
{
    if (rows != other.rows || cols != other.cols)
    {
        return *this;
    }
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            matrix[i][j] -= other.matrix[i][j];
        }
    }
    return *this;
}

Matrix& Matrix::operator*=(const Matrix& other)
{
    if ( cols != other.rows)
    {
        throw("error!");
    }
    Matrix result(rows, other.cols);
    for (int i = 0; i < rows; ++i)
    {
        for (int j = 0; j < other.cols; ++j)
        {
            result.matrix[i][j] = 0;
        }
    }

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < other.cols; j++)
        {
            for (int k = 0; k < cols; ++k)
            {
                result.matrix[i][j]+= matrix[i][k] * other.matrix[k][j];
            }
            
        }
    }
    *this = result;
    return *this;

}

Matrix& Matrix::operator*=(double number)
{
    
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            matrix[i][j] *= number;
        }
    }
    return *this;
}

int* Matrix::operator[](int index)
{
    if (index < 0 || index >= rows) throw std::out_of_range("Index out of bounds");

    return matrix[index];
    
}

const int* Matrix::operator[](int index) const
{
    if (index < 0 || index >= rows) throw std::out_of_range("Index out of bounds");

    return matrix[index];
}

bool Matrix::operator==(const Matrix& other) const
{
    if (rows != other.rows || cols != other.cols) return false;

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            if (matrix[i][j] != other.matrix[i][j])
            {
                return false;
            }
        }
    }
    return true;
}

bool Matrix::operator!=(const Matrix& other) const
{
    return !(*this == other);
}

Matrix::operator bool() const
{
    for (int i = 0; i < rows; ++i)
    {
        for (int j = 0; j < cols; ++j)
        {
            if (matrix[i][j] != 0) {

                return true;
            }
        }
    }
    return false;
}

void Matrix::print() const
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
           std::cout<< matrix[i][j]<<" ";
        }
        std::cout << '\n';
    }
}

Matrix operator+(const Matrix& lhs, const Matrix& rhs)
{
    Matrix lhsCopy(lhs);
    lhsCopy += rhs;
    return lhsCopy;

}

Matrix operator-(const Matrix& lhs, const Matrix& rhs)
{
    Matrix lhsCopy(lhs);
    lhsCopy -= rhs;
    return lhsCopy;
}

Matrix operator*(const Matrix& lhs, const Matrix& rhs)
{
    Matrix lhsCopy(lhs);
    lhsCopy *= rhs;
    return lhsCopy;
}

Matrix operator*(const Matrix& lhs, double number)
{
    Matrix lhsCopy(lhs);
    lhsCopy *=number;
    return lhsCopy;
}
