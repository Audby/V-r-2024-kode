#include <iostream>
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
    data[row * columns] = value;
}

int Matrix::getRows() {
    return 
}