//
// Created by Madatt on 15.12.2019.
//

#include <fstream>
#include <sstream>
#include "../include/Utils.h"

Matrix loadMatrixFromStream(std::iostream &t_strm, int t_rows, int t_cols) {
    Matrix mat(t_rows, t_cols);
    for(int i = 0; i < mat.getTotalSize(); i++) {
        t_strm >> mat.getData()[i];
    }

    return mat;
}

std::vector<double> loadVectorFromStream(std::iostream &t_strm, int t_size) {
    std::vector<double> vec;
    vec.resize(t_size);
    for(int i = 0; i < vec.size(); i++) {
        t_strm >> vec[i];
    }
    return vec;
}

void saveMatrixToStream(std::iostream &t_strm, Matrix &t_mat) {
    for(int i = 0; i < t_mat.getTotalSize(); i++) {
        t_strm << t_mat.getData()[i] << " ";
    }
    t_strm << "\n";
}

void saveVectorToStream(std::iostream &t_strm, std::vector<double> &t_vec) {
    for(int i = 0; i < t_vec.size(); i++) {
        t_strm << t_vec[i] << " ";
    }
    t_strm << "\n";
}

void fillRandom(std::vector<double> &t_vec, Random &t_ran, double t_min, double t_max) {
    for(int i = 0; i < t_vec.size(); i++) {
        t_vec[i] = t_ran.randomReal(t_min, t_max);
    }
}

void fillRandom(Matrix &t_mat, Random &t_ran, double t_min, double t_max) {
    for(int i = 0; i < t_mat.getTotalSize(); i++) {
        t_mat.getData()[i] = t_ran.randomReal(t_min, t_max);
    }
}
