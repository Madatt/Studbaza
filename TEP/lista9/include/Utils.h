//
// Created by Madatt on 15.12.2019.
//

#ifndef LISTA9_UTILS_H
#define LISTA9_UTILS_H


#include <vector>
#include "Matrix.h"
#include "Random.h"

Matrix loadMatrixFromStream(std::iostream &t_strm, int t_rows, int t_cols);
std::vector<double> loadVectorFromStream(std::iostream &t_strm, int t_size);

void saveMatrixToStream(std::iostream &t_strm, Matrix& t_mat);
void saveVectorToStream(std::iostream &t_strm, std::vector<double>& t_vec);

void fillRandom(std::vector<double> &t_vec, Random& t_ran, double t_min, double t_max);
void fillRandom(Matrix &t_mat, Random& t_ran, double t_min, double t_max);

#endif //LISTA9_UTILS_H
