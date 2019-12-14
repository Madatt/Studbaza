//
// Created by Madatt on 14.12.2019.
//

#include <fstream>
#include <string>
#include <iostream>
#include "../include/MscnProblem.h"
#include "../include/MscnSolution.h"

MscnProblem::MscnProblem() :
        cd(MSCN_DEF_SIZE), cf(MSCN_DEF_SIZE), cm(MSCN_DEF_SIZE) {
    D = MSCN_DEF_SIZE;
    F = MSCN_DEF_SIZE;
    M = MSCN_DEF_SIZE;
    S = MSCN_DEF_SIZE;

    sd.resize(MSCN_DEF_SIZE);
    sf.resize(MSCN_DEF_SIZE);
    sm.resize(MSCN_DEF_SIZE);
    ss.resize(MSCN_DEF_SIZE);
}

MscnProblem::MscnProblem(std::string t_fname) {
    std::string ign;
    std::ifstream file(t_fname);

    file >> ign;
    file >> D; setD(D);
    file >> ign;
    file >> F; setF(F);
    file >> ign;
    file >> M; setM(M);
    file >> ign;
    file >> S; setS(S);

    std::cout << D << " " << F << " " << M << " " << S << " " << std::endl;

    file >> ign;
    sd = loadVectorFromStream(file, D);
    file >> ign;
    sf = loadVectorFromStream(file, F);
    file >> ign;
    sm = loadVectorFromStream(file, M);
    file >> ign;
    ss = loadVectorFromStream(file, S);
    file >> ign;
    cd = loadMatrixFromStream(file, F, D);
    file >> ign;
    cf = loadMatrixFromStream(file, M, F);
    file >> ign;
    cm = loadMatrixFromStream(file, S, M);
    file >> ign;
    ud = loadVectorFromStream(file, D);
    file >> ign;
    uf = loadVectorFromStream(file, F);
    file >> ign;
    um = loadVectorFromStream(file, M);
    file >> ign;
    ps = loadVectorFromStream(file, S);

    std::cout << cd.toStr() << cf.toStr() << cm.toStr();
}


int MscnProblem::setD(int t_d) {
    if (t_d < 0)
        return 1;

    D = t_d;
    cd.resize(F, D);
    sd.resize(D);
    ud.resize(D);
    return 0;
}

int MscnProblem::setF(int t_f) {
    if (t_f < 0)
        return 1;

    F = t_f;
    cd.resize(F, D);
    cf.resize(M, F);
    sf.resize(F);
    uf.resize(F);
    return 0;
}

int MscnProblem::setM(int t_m) {
    if (t_m < 0)
        return 1;

    M = t_m;
    cf.resize(M, F);
    cm.resize(S, M);
    sm.resize(M);
    um.resize(M);
    return 0;
}

int MscnProblem::setS(int t_s) {
    if (t_s < 0)
        return 1;
    S = t_s;
    cm.resize(S, M);
    ss.resize(S);
    ps.resize(S);
    return 0;
}

int MscnProblem::validateRange(int t_mx, int t_v) {
    if (t_v < 0 or t_v > t_mx)
        return 1;

    return 0;
}

int MscnProblem::setAndValidateMat(Matrix &t_mat, int t_c, int t_r, double t_val, int t_mx1, int t_mx2) {
    if (validateRange(t_mx1, t_c) or validateRange(t_mx2, t_r) or t_val < 0)
        return 1;

    t_mat.set(t_c, t_r, t_val);
    return 0;
}

int MscnProblem::setAndValidateVec(std::vector<double> &t_vec, int t_p, double t_val, int t_mx1) {
    if (validateRange(t_mx1, t_p) or t_val < 0)
        return 1;

    t_vec[t_p] = t_val;
    return 0;
}

int MscnProblem::setCdCell(int t_d, int t_f, double t_val) {
    return setAndValidateMat(cd, t_f, t_d, t_val, D, F);
}

int MscnProblem::setCfCell(int t_f, int t_m, double t_val) {
    return setAndValidateMat(cf, t_m, t_f, t_val, F, M);
}

int MscnProblem::setCmCell(int t_m, int t_s, double t_val) {
    return setAndValidateMat(cm, t_s, t_m, t_val, M, S);
}

int MscnProblem::setSdCell(int t_d, double t_val) {
    return setAndValidateVec(sd, t_d, t_val, D);
}

int MscnProblem::setSfCell(int t_f, double t_val) {
    return setAndValidateVec(sf, t_f, t_val, F);
}

int MscnProblem::setSmCell(int t_m, double t_val) {
    return setAndValidateVec(sm, t_m, t_val, M);
}

int MscnProblem::setSsCell(int t_s, double t_val) {
    return setAndValidateVec(ss, t_s, t_val, S);
}

int MscnProblem::setUdCell(int t_d, double t_val) {
    return setAndValidateVec(ud, t_d, t_val, D);
}

int MscnProblem::setUfCell(int t_f, double t_val) {
    return setAndValidateVec(uf, t_f, t_val, F);
}

int MscnProblem::setUmCell(int t_m, double t_val) {
    return setAndValidateVec(um, t_m, t_val, M);
}

int MscnProblem::setPsCell(int t_s, double t_val) {
    return setAndValidateVec(ps, t_s, t_val, S);
}


double MscnProblem::getQuality(const MscnSolution &t_sol, int &t_err) {
    t_err = constraintsSatisfied(t_sol);
    //if(!t_err)
        return calculateP(t_sol) - calculateKt(t_sol) - calculateKu(t_sol);

    return 0.0;
}

double MscnProblem::getQuality(double *t_sol, int t_s, int &t_err) {
    int err = 0;
    t_err = 0;
    err = constraintsSatisfied(t_sol, t_s);
    if (err) {
        t_err = err;
        //return 0.0;
    }

    MscnSolution sol(t_sol, D, F, M, S, t_err);

    return getQuality(sol, t_err);
}

int MscnProblem::constraintsSatisfied(const MscnSolution &t_sol) {
    int err = 0;

    for (int i = 0; i < D; i++) {
        if (t_sol.xd.rowSum(i) > sd[i]) err = 1;
    }

    for (int i = 0; i < F; i++) {
        if (t_sol.xf.rowSum(i) > sf[i]) err = 1;
    }

    for (int i = 0; i < M; i++) {
        if (t_sol.xm.rowSum(i) > sm[i]) err = 1;
    }

    for (int i = 0; i < S; i++) {
        if (t_sol.xm.colSum(i) > ss[i]) err = 1;
    }

    for (int i = 0; i < F; i++) {
        if (t_sol.xd.colSum(i) < t_sol.xf.rowSum(i)) err = 1;
    }

    for (int i = 0; i < M; i++) {
        if (t_sol.xf.colSum(i) < t_sol.xm.rowSum(i)) err = 1;
    }

    return err;
}

int MscnProblem::constraintsSatisfied(double *t_sol, int t_s) {
    if (t_s != cd.getTotalSize() + cf.getTotalSize() + cm.getTotalSize())
        return 1;

    for (int i = 0; i < t_s; i++) {
        if (t_sol[i] < 0)
            return 1;
    }

    int err = 0;

    MscnSolution sol(t_sol, D, F, M, S, err);

    for (int i = 0; i < D; i++) {
        if (sol.xd.rowSum(i) > sd[i]) err = 1;
    }

    for (int i = 0; i < F; i++) {
        if (sol.xf.rowSum(i) > sf[i]) err = 1;
    }

    for (int i = 0; i < M; i++) {
        if (sol.xm.rowSum(i) > sm[i]) err = 1;
    }

    for (int i = 0; i < S; i++) {
        if (sol.xm.colSum(i) > ss[i]) err = 1;
    }

    for (int i = 0; i < F; i++) {
        if (sol.xd.colSum(i) < sol.xf.rowSum(i)) err = 1;
    }

    for (int i = 0; i < M; i++) {
        if (sol.xf.colSum(i) < sol.xm.rowSum(i)) err = 1;
    }

    return err;
}

double MscnProblem::calculateKt(const MscnSolution &t_sol) {
    double kt = 0;

    for (int i = 0; i < F; i++) {
        for (int j = 0; j < D; j++) {
            kt += cd.get(i, j) * t_sol.xd.get(i, j);
        }
    }

    for (int i = 0; i < M; i++) {
        for (int j = 0; j < F; j++) {
            kt += cf.get(i, j) * t_sol.xf.get(i, j);
        }
    }

    for (int i = 0; i < S; i++) {
        for (int j = 0; j < M; j++) {
            kt += cm.get(i, j) * t_sol.xm.get(i, j);
        }
    }

    return kt;
}

double MscnProblem::calculateKu(const MscnSolution &t_sol) {
    double ku = 0;

    for (int i = 0; i < D; i++) {
        if (t_sol.xd.rowSum(i) > 0) ku += ud[i];
    }

    for (int i = 0; i < F; i++) {
        if (t_sol.xf.rowSum(i) > 0) ku += uf[i];
    }

    for (int i = 0; i < M; i++) {
        if (t_sol.xm.rowSum(i) > 0) ku += um[i];
    }

    return ku;
}

double MscnProblem::calculateP(const MscnSolution &t_sol) {
    double p = 0;

    for (int i = 0; i < S; i++) {
        for (int j = 0; j < M; j++) {
            p += ps[i] * t_sol.xm.get(i, j);
        }
    }

    return p;
}

