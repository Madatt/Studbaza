//
// Created by Madatt on 14.12.2019.
//

#ifndef LISTA9_MSCNPROBLEM_H
#define LISTA9_MSCNPROBLEM_H

#include <vector>
#include <string>
#include "../Matrix.h"
#include "../Abstract/Problem.h"
#include "../Abstract/Solution.h"

const int MSCN_DEF_SIZE = 3;

const int MSCN_ERR_VALUE = 1;
const int MSCN_ERR_RANGE = 2;
const int MSCN_ERR_SOL_SIZE = 3;
const int MSCN_ERR_SOL_NEG = 4;
const int MSCN_ERR_FILE = 5;
const int MSCN_ERR_SOL_MINMAX = -1;

const double MSCN_C_MIN = 1.0;
const double MSCN_C_MAX = 40.0;

const double MSCN_S_MIN = 1.0;
const double MSCN_S_MAX = 1000.0;

const double MSCN_U_MIN = 1.0;
const double MSCN_U_MAX = 3.0;

const double MSCN_P_MIN = 60.0;
const double MSCN_P_MAX = 500.0;


class MscnSolution {
    friend class MscnProblem;
public:
    MscnSolution() = default;
    MscnSolution(const std::vector<double> &t_sol, int t_d, int t_f, int t_m, int t_s);
    int saveToFile(std::string t_fname);

private:
    Matrix xd;
    Matrix xf;
    Matrix xm;

    int d;
    int f;
    int m;
    int s;
};


class MscnProblem : public Problem {
public:
    MscnProblem();
    MscnProblem(std::string t_fname, int &t_err);


    int getD(){return d;};
    int getF(){return f;};
    int getM(){return m;};
    int getS(){return s;};

    int setD(int t_d);
    int setF(int t_f);
    int setM(int t_m);
    int setS(int t_s);

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

    std::pair<double, double> getSolutionMinMax(int t_pos);
    double getQuality(Solution &solution) override;

    std::pair<double, double> getXdMinMax(int t_d, int t_f);
    std::pair<double, double> getXfMinMax(int t_f, int t_m);
    std::pair<double, double> getXmMinMax(int t_m, int t_s);


    int getSize() override;
    double getQuality(MscnSolution &t_sol, int &t_err);
    bool constraintsSatisfied(MscnSolution &t_sol, int &t_err);
    bool constraintsSatisfied(Solution &t_sol);

    int saveToFile(std::string t_fname);

    void generateInstance(int t_seed);

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

    std::vector<double> xdMinMax;
    std::vector<double> xfMinMax;
    std::vector<double> xmMinMax;

    int d;
    int f;
    int m;
    int s;

    int validateRange(int t_mx, int t_v);
    int setAndValidateMat(Matrix &t_mat, int t_row, int t_col, double t_val, int t_mx1, int t_mx2);
    int setAndValidateVec(std::vector<double> &t_vec, int t_p, double t_val, int t_mx1);

    double calculateKt(const MscnSolution &t_sol);
    double calculateKu(const MscnSolution &t_sol);
    double calculateP(const MscnSolution &t_sol);

    int initialSatisfied(MscnSolution &t_sol);

    std::pair<double, double> getAndValidateVec(std::vector<double> &t_vec,  int t_row, int t_col, int t_mx1, int t_mx2);
};

std::string errorToString(int t_err);

MscnSolution loadSolution(std::string t_fname, int &t_err);
std::vector<double> loadSolutionSemicolon(std::string t_fname, int &t_err);


#endif //LISTA9_MSCNPROBLEM_H
