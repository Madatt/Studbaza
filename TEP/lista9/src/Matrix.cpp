//
// Created by Madatt on 14.12.2019.
//

#include <algorithm>
#include <fstream>
#include "../include/Matrix.h"

Matrix::Matrix()
        : Matrix(MATRIX_DEF_SIZE, MATRIX_DEF_SIZE) {

}

Matrix::Matrix(double *t_raw, int t_cols, int t_rows)
        : columns(t_cols), rows(t_rows), data(t_raw) {

}

Matrix::Matrix(int t_cols, int t_rows)
        : columns(t_cols), rows(t_rows) {
    data = new double[t_cols * t_rows];
}

Matrix::Matrix(int t_cols)
        : Matrix(t_cols, t_cols) {
}

Matrix::~Matrix() {
    delete data;
}

void Matrix::operator=(const Matrix &t_mat) {
    delete data;

    data = new double[t_mat.getTotalSize()];
    std::copy(t_mat.data, t_mat.data + t_mat.getTotalSize(), data);
    rows = t_mat.rows;
    columns = t_mat.columns;
}

double Matrix::get(int t_cols, int t_rows) const {
    if (t_cols >= 0 and t_rows >= 0 and t_cols < columns and t_rows < rows) {
        return data[t_cols + t_rows * columns];
    }
    return 0.0;
}

void Matrix::set(int t_cols, int t_rows, double t_val) {
    if (t_cols >= 0 and t_rows >= 0 and t_cols < columns and t_rows < rows) {
        data[t_cols + t_rows * columns] = t_val;
    }
}

void Matrix::resize(int t_cols, int t_rows) {
    if (t_cols < 0 or t_rows < 0)
        return;

    double *new_data = new double[t_rows * t_cols];
    columns = t_cols;
    rows = t_rows;

    /*int cols_inter = t_cols < columns ? t_cols : columns;
    int rows_inter = t_rows < rows ? t_rows : rows;

    for (int i = 0; i < rows_inter; i++) {
        std::copy(
                data + i * columns,
                data + i * columns + cols_inter,
                new_data + i * t_cols
        );
    }*/

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

Matrix loadMatrixFromStream(std::ifstream &t_strm, int t_cols, int t_rows) {
    Matrix mat(t_cols, t_rows);
    for(int i = 0; i < mat.getTotalSize(); i++) {
        t_strm >> mat.getData()[i];
    }

    return mat;
}

std::vector<double> loadVectorFromStream(std::ifstream &t_strm, int t_size) {
    std::vector<double> vec(t_size);
    for(int i = 0; i < vec.size(); i++) {
        t_strm >> vec[i];
    }
    return vec;
}
