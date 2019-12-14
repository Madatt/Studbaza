//
// Created by Madatt on 14.12.2019.
//

#ifndef LISTA9_MSCNPROBLEM_H
#define LISTA9_MSCNPROBLEM_H

#include <vector>
#include "Matrix.h"
#include "MscnSolution.h"

const int MSCN_DEF_SIZE = 4;

class MscnProblem {
public:
    MscnProblem();
    MscnProblem(std::string t_fname);
    ~MscnProblem() = default;

    int setD(int t_d);
    int setF(int t_d);
    int setM(int t_d);
    int setS(int t_d);

    int setCdCell(int t_d, int t_f, double t_val);
    int setCfCell(int t_f, int t_m, double t_val);
    int setCmCell(int t_m, int t_s, double t_val);

    int setSdCell(int t_d, double t_val);
    int setSfCell(int t_f, double t_val);
    int setSmCell(int t_m, double t_val);
    int setSsCell(int t_s, double t_val);

    int setUdCell(int t_d, double t_val);
    int setUfCell(int t_f, double t_val);
    int setUmCell(int t_m, double t_val);

    int setPsCell(int t_s, double t_val);

    double getQuality(double* t_sol, int t_s, int& t_err);
    double getQuality(const MscnSolution& t_sol, int& t_err);
    int constraintsSatisfied(double* t_sol, int t_s);
    int constraintsSatisfied(const MscnSolution& t_sol);

private:
    Matrix cd;
    Matrix cf;
    Matrix cm;

    std::vector<double> ud;
    std::vector<double> uf;
    std::vector<double> um;

    std::vector<double> sd;
    std::vector<double> sf;
    std::vector<double> sm;
    std::vector<double> ss;

    std::vector<double> ps;

    int D;
    int F;
    int M;
    int S;

    int validateRange(int t_mx , int t_v);
    int setAndValidateMat(Matrix& t_mat, int t_c, int t_r, double t_val, int t_mx1, int t_mx2);
    int setAndValidateVec(std::vector<double>& t_vec, int t_p, double t_val, int t_mx1);

    double calculateKt(const MscnSolution& t_sol);
    double calculateKu(const MscnSolution& t_sol);
    double calculateP(const MscnSolution& t_sol);
};

/*
    Matrix xd;
    Matrix xf;
    Matrix xm;
 */


#endif //LISTA9_MSCNPROBLEM_H
