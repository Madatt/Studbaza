//
// Created by Madatt on 14.12.2019.
//

#include <algorithm>
#include <fstream>
#include "../include/Matrix.h"

Matrix::Matrix()
        : Matrix(MATRIX_DEF_SIZE, MATRIX_DEF_SIZE) {

}

Matrix::Matrix(const Matrix &t_mat):
columns(t_mat.columns), rows(t_mat.rows){
    data = new double[t_mat.getTotalSize()];
    std::copy(t_mat.data, t_mat.data + t_mat.getTotalSize(), data);
}

Matrix::Matrix(double *t_raw, int t_rows, int t_cols)
        : columns(t_cols), rows(t_rows), data(t_raw) {

}

Matrix::Matrix(int t_rows, int t_cols)
        : columns(t_cols), rows(t_rows) {
    data = new double[t_cols * t_rows];
}


Matrix::~Matrix() {
    delete data;
}

void Matrix::operator=(const Matrix &t_mat) {
    if(this == &t_mat)
        return;
    delete data;

    data = new double[t_mat.getTotalSize()];
    std::copy(t_mat.data, t_mat.data + t_mat.getTotalSize(), data);
    rows = t_mat.rows;
    columns = t_mat.columns;
}

double Matrix::get(int t_rows, int t_cols) const {
    if (t_cols >= 0 and t_rows >= 0 and t_cols < columns and t_rows < rows) {
        return data[t_cols + t_rows * columns];
    }
    return 0.0;
}



void Matrix::set(int t_rows, int t_cols, double t_val) {
    if (t_cols >= 0 and t_rows >= 0 and t_cols < columns and t_rows < rows) {
        data[t_cols + t_rows * columns] = t_val;
    }
}

void Matrix::resize(int t_rows, int t_cols) {
    if (t_cols < 0 or t_rows < 0)
        return;

    double *new_data = new double[t_rows * t_cols];


    int cols_inter = t_cols < columns ? t_cols : columns;
    int rows_inter = t_rows < rows ? t_rows : rows;

    for (int i = 0; i < rows_inter; i++) {
        std::copy(
                data + i * columns,
                data + i * columns + cols_inter,
                new_data + i * t_cols
        );
    }

    columns = t_cols;
    rows = t_rows;
    delete data;
    data = new_data;
}

void Matrix::clear() {
    for (int i = 0; i < columns * rows; i++) {
        data[i] = 0;
    }
}

double Matrix::rowSum(int t_row) const {
    double res = 0;
    for (int i = 0; i < columns; i++) {
        res += data[t_row * columns + i];
    }

    return res;
}

double Matrix::colSum(int t_col) const {
    double res = 0;
    for (int i = 0; i < rows; i++) {
        res += data[i * columns + t_col];
    }

    return res;
}

std::string Matrix::toStr() {
    std::string res = "[";
    for(int i = 0; i < getTotalSize(); i++)
        res += std::to_string(data[i]) + ", ";

    res = res.substr(0, res.size() - 2);
    res += "]\n";
    return res;
};

bool Matrix::rowEmpty(int t_row) const {
    bool empty = true;
    for (int i = 0; i < columns and empty; i++) {
        if (data[t_row * columns + i] != 0.0) empty = false;
    }

    return empty;
}

bool Matrix::hasNegative() const {
    bool nega = false;
    for (int i = 0; i < getTotalSize() and !nega; i++) {
        if (data[i] < 0) nega = true;
    }

    return nega;
}
