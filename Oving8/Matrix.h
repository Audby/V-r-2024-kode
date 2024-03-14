#include <iostream>
#include <cassert>
#pragma once
 
//Oppgave 2a) og 2b)
class Matrix {
private:
    int rows;
    int columns;
    double* data;
    void swap(Matrix& other);
public:
    Matrix(int nRows, int nColumns);
    explicit Matrix(int nRows);
    ~Matrix();
    double get(int row, int col) const;
    void set(int row, int col, double value);
    int getRows() const;
    int getColumns() const;
    Matrix(const Matrix& rhs);
    Matrix& operator=(Matrix rhs);
    //Oppgave 5a)
    Matrix& operator+=(const Matrix& rhs);
};

std::ostream& operator<<(std::ostream& os, const Matrix& matrix);