//
// Created by Madatt on 14.12.2019.
//

#ifndef LISTA9_MATRIX_H
#define LISTA9_MATRIX_H

#include <string>
#include <vector>

const int MATRIX_DEF_SIZE = 4;


class Matrix {
public:
    Matrix();
    Matrix(const Matrix& t_mat);
    Matrix(double* t_raw, int t_rows, int t_cols);
    Matrix(int t_rows, int t_cols);
    ~Matrix();

    void operator=(const Matrix& t_mat);


    double get(int t_rows, int t_cols) const;
    void set(int t_rows, int t_cols, double t_val);
    void resize(int t_rows, int t_cols);
    void clear();

    double* getData(){return data;};
    int getRows() const{return rows;};
    int getColumns() const{return columns;};
    int getTotalSize() const {return columns * rows;};

    void setMinMax(int t_rows, int t_cols, double t_min, double t_max);
    void rowMult(int t_row, double t_val);
    void colMult(int t_col, double t_val);
    double rowSum(int t_row) const;
    double colSum(int t_col) const;

    bool rowEmpty(int t_row) const;
    bool hasNegative() const;

    std::string toStr();


private:
    double* data;

    int rows;
    int columns;
};


#endif //LISTA9_MATRIX_H
