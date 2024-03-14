#include "Matrix.h"

Matrix::Matrix(int nRows, int nColumns) : rows(nRows), columns(nColumns) {
    assert(nRows > 0 && nColumns > 0);
    data = new double [nRows * nColumns] {};
}

Matrix::Matrix(int nRows) : Matrix(nRows, nRows) {
    for (int i = 0; i < rows; i++) {
        data[i * columns + i] = 1.0;
    }
}

Matrix::~Matrix() {
    delete[] data;
}

double Matrix::get(int row, int col) const {
    assert(row >= 0 && row < rows && col >= 0 && col < columns);
    return data[row * columns + col];
}

void Matrix::set(int row, int col, double value) {
    assert(row >= 0 && row < rows && col >= 0 && col < columns);
    data[row * columns + col] = value;
}

int Matrix::getRows() const {
    return rows;
}

int Matrix::getColumns() const {
    return columns;
}

std::ostream& operator<<(std::ostream& os, const Matrix& matrix) {
    for (int i = 0; i < matrix.getRows(); i++) {
        for (int j = 0; j < matrix.getColumns(); j++) {
            os << matrix.get(i, j) << " ";
        }
        os << std::endl;
    }
    return os;
}

Matrix::Matrix(const Matrix& rhs) : rows(rhs.rows), columns(rhs.columns) {
    data = new double[rows * columns];
    for (int i = 0; i < rows * columns; i++) {
        data[i] = rhs.data[i];
    }
}

void Matrix::swap(Matrix& other) {
    std::swap(rows, other.rows);
    std::swap(columns, other.columns);
    std::swap(data, other.data);
}

Matrix& Matrix::operator=(Matrix rhs) {
    swap(rhs);
    return *this;
}

//Oppgave 5a)
Matrix& Matrix::operator+=(const Matrix& rhs) {
    if (rows != rhs.rows || columns != rhs.columns) {
        throw std::invalid_argument("Matrices must have the same dimensions");
    }

    for (int i = 0; i < rows * columns; i++) {
        data[i] += rhs.data[i];
    }

    return *this;
}