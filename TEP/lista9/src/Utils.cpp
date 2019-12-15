//
// Created by Madatt on 15.12.2019.
//

#include <fstream>
#include <sstream>
#include "../include/Utils.h"

Matrix loadMatrixFromStream(std::iostream &t_strm, int t_cols, int t_rows) {
    Matrix mat(t_cols, t_rows);
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
