//
// Created by Madatt on 14.12.2019.
//

#include <fstream>
#include <string>
#include <iostream>
#include "../include/MscnProblem.h"
#include "../include/Utils.h"
#include "../include/Random.h"

MscnSolution::MscnSolution(const std::vector<double> &t_sol, int t_d, int t_f, int t_m, int t_s) {
    d = t_d;
    f = t_f;
    m = t_m;
    s = t_s;

    xd.resize(t_d, t_f);
    xf.resize(t_f, t_m);
    xm.resize(t_m, t_s);

    int fd_s = t_f * t_d;
    int mf_s = t_m * t_f;
    int sm_s = t_s * t_m;

    for (int i = 0; i < fd_s; i++) {
        xd.getData()[i] = t_sol[i];
    }

    for (int i = 0; i < mf_s; i++) {
        xf.getData()[i] = t_sol[i + fd_s];
    }

    for (int i = 0; i < sm_s; i++) {
        xm.getData()[i] = t_sol[i + fd_s + mf_s];
    }
    //std::cout << xd.toStr() << xf.toStr() << xm.toStr();
}


MscnProblem::MscnProblem() {
    d = MSCN_DEF_SIZE;
    f = MSCN_DEF_SIZE;
    m = MSCN_DEF_SIZE;
    s = MSCN_DEF_SIZE;

    setD(MSCN_DEF_SIZE);
    setF(MSCN_DEF_SIZE);
    setM(MSCN_DEF_SIZE);
    setS(MSCN_DEF_SIZE);
}

MscnProblem::MscnProblem(std::string t_fname, int &t_err) {
    std::string ign;
    std::fstream file;
    file.open(t_fname);

    if (!file.is_open()) {
        t_err = MSCN_ERR_FILE;
        return;
    }

    file >> ign;
    file >> d;

    file >> ign;
    file >> f;

    file >> ign;
    file >> m;

    file >> ign;
    file >> s;

    setD(d);
    setF(f);
    setM(m);
    setS(s);

    file >> ign;
    sd = loadVectorFromStream(file, d);
    file >> ign;
    sf = loadVectorFromStream(file, f);
    file >> ign;
    sm = loadVectorFromStream(file, m);
    file >> ign;
    ss = loadVectorFromStream(file, s);
    file >> ign;
    cd = loadMatrixFromStream(file, d, f);
    file >> ign;
    cf = loadMatrixFromStream(file, f, m);
    file >> ign;
    cm = loadMatrixFromStream(file, m, s);
    file >> ign;
    ud = loadVectorFromStream(file, d);
    file >> ign;
    uf = loadVectorFromStream(file, f);
    file >> ign;
    um = loadVectorFromStream(file, m);
    file >> ign;
    ps = loadVectorFromStream(file, s);

    file >> ign;
    xdMinMax = loadVectorFromStream(file, f * d * 2);
    file >> ign;
    xfMinMax = loadVectorFromStream(file, f * m * 2);
    file >> ign;
    xmMinMax = loadVectorFromStream(file, s * m * 2);

    file.close();
    t_err = 0;

    //std::cout << cd.toStr() << cf.toStr() << cm.toStr();
}

int MscnSolution::saveToFile(std::string t_fname) {
    std::fstream file;
    file.open(t_fname, std::ofstream::out | std::ofstream::trunc);

    if (!file.is_open()) {
        return MSCN_ERR_FILE;
    }

    file << "D ";
    file << d << "\n";
    file << "F ";
    file << f << "\n";
    file << "M ";
    file << m << "\n";
    file << "S ";
    file << s << "\n";

    file << "xd ";
    saveMatrixToStream(file, xd);
    file << "xf ";
    saveMatrixToStream(file, xf);
    file << "xm ";
    saveMatrixToStream(file, xm);


    file.close();

    return 0;
}

int MscnProblem::saveToFile(std::string t_fname) {
    std::fstream file;
    file.open(t_fname, std::ofstream::out | std::ofstream::trunc);

    if (!file.is_open()) {
        return MSCN_ERR_FILE;
    }

    file << "D ";
    file << d << "\n";
    file << "F ";
    file << f << "\n";
    file << "M ";
    file << m << "\n";
    file << "S ";
    file << s << "\n";

    file << "sd ";
    saveVectorToStream(file, sd);
    file << "sf ";
    saveVectorToStream(file, sf);
    file << "sm ";
    saveVectorToStream(file, sm);
    file << "ss ";
    saveVectorToStream(file, ss);

    file << "cd ";
    saveMatrixToStream(file, cd);
    file << "cf ";
    saveMatrixToStream(file, cf);
    file << "cm ";
    saveMatrixToStream(file, cm);

    file << "ud ";
    saveVectorToStream(file, ud);
    file << "uf ";
    saveVectorToStream(file, uf);
    file << "um ";
    saveVectorToStream(file, um);
    file << "ps ";
    saveVectorToStream(file, ps);

    file << "xdminmax ";
    saveVectorToStream(file, xdMinMax);
    file << "xfminmax ";
    saveVectorToStream(file, xfMinMax);
    file << "xmminmax ";
    saveVectorToStream(file, xmMinMax);

    file.close();

    return 0;
}

int MscnProblem::setD(int t_d) {
    if (t_d < 0)
        return MSCN_ERR_VALUE;

    d = t_d;
    cd.resize(d, f);
    sd.resize(d);
    ud.resize(d);
    xdMinMax.resize(d * f * 2);
    return 0;
}

int MscnProblem::setF(int t_f) {
    if (t_f < 0)
        return MSCN_ERR_VALUE;

    f = t_f;
    cd.resize(d, f);
    cf.resize(f, m);
    sf.resize(f);
    uf.resize(f);
    xdMinMax.resize(d * f * 2);
    xfMinMax.resize(f * m * 2);
    return 0;
}

int MscnProblem::setM(int t_m) {
    if (t_m < 0)
        return MSCN_ERR_VALUE;

    m = t_m;
    cf.resize(f, m);
    cm.resize(m, s);
    sm.resize(m);
    um.resize(m);
    xfMinMax.resize(f * m * 2);
    xmMinMax.resize(s * m * 2);
    return 0;
}

int MscnProblem::setS(int t_s) {
    if (t_s < 0)
        return MSCN_ERR_VALUE;
    s = t_s;
    cm.resize(m, s);
    ss.resize(s);
    ps.resize(s);
    xmMinMax.resize(s * m * 2);
    return 0;
}

int MscnProblem::validateRange(int t_mx, int t_v) {
    if (t_v < 0 or t_v > t_mx)
        return MSCN_ERR_RANGE;

    return 0;
}

int MscnProblem::setAndValidateMat(Matrix &t_mat, int t_row, int t_col, double t_val, int t_mx1, int t_mx2) {
    if (validateRange(t_mx1, t_row) or validateRange(t_mx2, t_col) or t_val < 0)
        return MSCN_ERR_RANGE;

    t_mat.set(t_row, t_col, t_val);
    return 0;
}

int MscnProblem::setAndValidateVec(std::vector<double> &t_vec, int t_p, double t_val, int t_mx1) {
    if (validateRange(t_mx1, t_p) or t_val < 0)
        return MSCN_ERR_RANGE;

    t_vec[t_p] = t_val;
    return 0;
}

int MscnProblem::setCdCell(int t_d, int t_f, double t_val) {
    return setAndValidateMat(cd, t_d, t_f, t_val, f, d);
}

int MscnProblem::setCfCell(int t_f, int t_m, double t_val) {
    return setAndValidateMat(cf, t_f, t_m, t_val, m, f);
}

int MscnProblem::setCmCell(int t_m, int t_s, double t_val) {
    return setAndValidateMat(cm, t_m, t_s, t_val, s, m);
}

int MscnProblem::setSdCell(int t_d, double t_val) {
    return setAndValidateVec(sd, t_d, t_val, d);
}

int MscnProblem::setSfCell(int t_f, double t_val) {
    return setAndValidateVec(sf, t_f, t_val, f);
}

int MscnProblem::setSmCell(int t_m, double t_val) {
    return setAndValidateVec(sm, t_m, t_val, m);
}

int MscnProblem::setSsCell(int t_s, double t_val) {
    return setAndValidateVec(ss, t_s, t_val, s);
}

int MscnProblem::setUdCell(int t_d, double t_val) {
    return setAndValidateVec(ud, t_d, t_val, d);
}

int MscnProblem::setUfCell(int t_f, double t_val) {
    return setAndValidateVec(uf, t_f, t_val, f);
}

int MscnProblem::setUmCell(int t_m, double t_val) {
    return setAndValidateVec(um, t_m, t_val, m);
}

int MscnProblem::setPsCell(int t_s, double t_val) {
    return setAndValidateVec(ps, t_s, t_val, s);
}

std::pair<double, double>
MscnProblem::getAndValidateVec(std::vector<double> &t_vec, int t_row, int t_col, int t_mx1, int t_mx2) {
    if (validateRange(t_mx1, t_row) or validateRange(t_mx2, t_col)) {
        return std::make_pair(MSCN_ERR_SOL_MINMAX, MSCN_ERR_SOL_MINMAX);
    }

    return std::make_pair(t_vec[(t_col + t_row * f) * 2], t_vec[(t_col + t_row * f) * 2 + 1]);
}

std::pair<double, double> MscnProblem::getXdMinMax(int t_d, int t_f) {
    return getAndValidateVec(xdMinMax, t_d, t_f, d, f);
}

std::pair<double, double> MscnProblem::getXfMinMax(int t_f, int t_m) {
    return getAndValidateVec(xfMinMax, t_f, t_m, f, m);
}

std::pair<double, double> MscnProblem::getXmMinMax(int t_m, int t_s) {
    return getAndValidateVec(xmMinMax, t_m, t_s, m, s);
}

std::pair<double, double> MscnProblem::getSolutionMinMax(int t_pos) {
    int df = d * f;
    int fm = f * m;
    int ms = m * s;
    if (t_pos < 0 or t_pos > df + fm + ms)
        return std::make_pair(MSCN_ERR_SOL_MINMAX, MSCN_ERR_SOL_MINMAX);

    if (t_pos < df) {
        return getXdMinMax(t_pos / d, t_pos % f);
    } else if (t_pos < fm + df) {
        return getXfMinMax(t_pos / f, t_pos % m);
    }
    if (t_pos < fm + df + ms) {
        return getXmMinMax(t_pos / m, t_pos % s);
    }
}

double MscnProblem::getQuality(MscnSolution &t_sol, int &t_err) {
    t_err = initialSatisfied(t_sol);
    if (t_err)
        return 0.0;


    return calculateP(t_sol) - calculateKu(t_sol) - calculateKt(t_sol);
}


int MscnProblem::initialSatisfied(MscnSolution &t_sol) {
    if (t_sol.d != d or t_sol.f != f or t_sol.m != m or t_sol.s != s)
        return MSCN_ERR_SOL_SIZE;


    for (int i = 0; i < t_sol.xd.getTotalSize(); i++) {
        if (t_sol.xd.getData()[i] < 0)
            return MSCN_ERR_SOL_NEG;
    }


    for (int i = 0; i < t_sol.xf.getTotalSize(); i++) {
        if (t_sol.xf.getData()[i] < 0)
            return MSCN_ERR_SOL_NEG;
    }


    for (int i = 0; i < t_sol.xm.getTotalSize(); i++) {
        if (t_sol.xm.getData()[i] < 0)
            return MSCN_ERR_SOL_NEG;
    }

    return 0;
}

bool MscnProblem::constraintsSatisfied(MscnSolution &t_sol, int &t_err) {
    t_err = initialSatisfied(t_sol);
    if (t_err)
        return 0;

    int ok = 1;

    for (int i = 0; i < d; i++) {
        if (t_sol.xd.rowSum(i) > sd[i]) ok = 0;
    }

    for (int i = 0; i < f; i++) {
        if (t_sol.xf.rowSum(i) > sf[i]) ok = 0;
    }

    for (int i = 0; i < m; i++) {
        if (t_sol.xm.rowSum(i) > sm[i]) ok = 0;
    }

    for (int i = 0; i < s; i++) {
        if (t_sol.xm.colSum(i) > ss[i]) ok = 0;
    }

    for (int i = 0; i < f; i++) {
        if (t_sol.xd.colSum(i) < t_sol.xf.rowSum(i)) ok = 0;
    }

    for (int i = 0; i < m; i++) {
        if (t_sol.xf.colSum(i) < t_sol.xm.rowSum(i)) ok = 0;
    }

    for (int i = 0; i < d; i++) {
        for (int j = 0; j < f; j++) {
            if (t_sol.xd.get(i, j) < getXdMinMax(i, j).first or t_sol.xd.get(i, j) > getXdMinMax(i, j).second) {
                ok = 0;
            }
        }
    }

    for (int i = 0; i < f; i++) {
        for (int j = 0; j < m; j++) {
            if (t_sol.xf.get(i, j) < getXfMinMax(i, j).first or t_sol.xf.get(i, j) > getXfMinMax(i, j).second) {
                ok = 0;
            }
        }
    }

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < s; j++) {
            if (t_sol.xm.get(i, j) < getXmMinMax(i, j).first or t_sol.xm.get(i, j) > getXmMinMax(i, j).second) {
                ok = 0;
            }
        }
    }

    return ok;
}

double MscnProblem::calculateKt(const MscnSolution &t_sol) {
    double kt = 0;

    for (int i = 0; i < d; i++) {
        for (int j = 0; j < f; j++) {
            kt += cd.get(i, j) * t_sol.xd.get(i, j);
        }
    }

    for (int i = 0; i < f; i++) {
        for (int j = 0; j < m; j++) {
            kt += cf.get(i, j) * t_sol.xf.get(i, j);
        }
    }

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < s; j++) {
            kt += cm.get(i, j) * t_sol.xm.get(i, j);
        }
    }

    return kt;
}

double MscnProblem::calculateKu(const MscnSolution &t_sol) {
    double ku = 0;

    for (int i = 0; i < d; i++) {
        if (!t_sol.xd.rowEmpty(i)) ku += ud[i];
    }

    for (int i = 0; i < f; i++) {
        if (!t_sol.xf.rowEmpty(i)) ku += uf[i];
    }

    for (int i = 0; i < m; i++) {
        if (!t_sol.xm.rowEmpty(i)) ku += um[i];
    }

    return ku;
}

double MscnProblem::calculateP(const MscnSolution &t_sol) {
    double p = 0;

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < s; j++) {
            p += ps[j] * t_sol.xm.get(i, j);
        }
    }

    return p;
}

MscnSolution loadSolution(std::string t_fname, int &t_err) {
    std::string ign;
    std::ifstream file(t_fname);
    t_err = 0;

    if (!file.is_open()) {
        t_err = MSCN_ERR_FILE;
        return MscnSolution();
    }

    int d, f, m, s;

    file >> ign;
    file >> d;
    file >> ign;
    file >> f;
    file >> ign;
    file >> m;
    file >> ign;
    file >> s;
    file >> ign;

    int df = d * f;
    int fm = f * m;
    int ms = m * s;
    int size = df + fm + ms;
    std::vector<double> solution(size);

    for (int i = 0; i < size; i++) {
        if (i == df or i == df + fm)
            file >> ign;
        file >> solution[i];
    }

    MscnSolution sol(solution, d, f, m, s);

    file.close();
    return sol;
}

std::vector<double> loadSolutionSemicolon(std::string t_fname, int &t_err) {
    std::string ign;
    std::string line;
    std::ifstream file(t_fname);
    t_err = 0;

    if (!file.is_open()) {
        t_err = MSCN_ERR_FILE;
        return std::vector<double>();
    }

    int d, f, m, s;

    file >> ign;
    file >> d;
    file >> ign;
    file >> f;
    file >> ign;
    file >> m;
    file >> ign;
    file >> s;
    file >> ign;

    int df = d * f;
    int fm = f * m;
    int ms = m * s;
    int size = df + fm + ms;
    std::vector<double> solution(size);

    for (int i = 0; i < size; i++) {
        if (i == df or i == df + fm)
            file >> ign;

        std::getline(file, line, ';');
        if (file.fail()) {
            t_err = MSCN_ERR_FILE;
            return std::vector<double>();
        }
        solution[i] = std::atof(line.c_str());

    }

    file.close();
    return solution;
}

void MscnProblem::generateInstance(int t_seed) {
    Random rand(t_seed);

    fillRandom(cd, rand, MSCN_C_MIN, MSCN_C_MAX);
    fillRandom(cf, rand, MSCN_C_MIN, MSCN_C_MAX);
    fillRandom(cm, rand, MSCN_C_MIN, MSCN_C_MAX);

    fillRandom(ud, rand, MSCN_U_MIN, MSCN_U_MAX);
    fillRandom(uf, rand, MSCN_U_MIN, MSCN_U_MAX);
    fillRandom(um, rand, MSCN_U_MIN, MSCN_U_MAX);

    fillRandom(sd, rand, MSCN_S_MIN, MSCN_S_MAX);
    fillRandom(sf, rand, MSCN_S_MIN, MSCN_S_MAX);
    fillRandom(sm, rand, MSCN_S_MIN, MSCN_S_MAX);
    fillRandom(ss, rand, MSCN_S_MIN, MSCN_S_MAX);

    fillRandom(ps, rand, MSCN_P_MIN, MSCN_P_MAX);

    int c = 0;
    for (int i = 0; i < d; i++) {
        for (int j = 0; j < f; j++) {
            xdMinMax[c] = 0;
            xdMinMax[c + 1] = sd[i];
            c += 2;
        }
    }

    c = 0;
    for (int i = 0; i < f; i++) {
        for (int j = 0; j < m; j++) {
            xfMinMax[c] = 0;
            xfMinMax[c + 1] = sf[i];
            c += 2;
        }
    }

    c = 0;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < s; j++) {
            xmMinMax[c] = 0;
            xmMinMax[c + 1] = sm[i];
            c += 2;
        }
    }

}

std::string errorToString(int t_err) {
    if (t_err == MSCN_ERR_VALUE) return "MSCN_ERR_VALUE";
    if (t_err == MSCN_ERR_RANGE) return "MSCN_ERR_RANGE";
    if (t_err == MSCN_ERR_SOL_SIZE) return "MSCN_ERR_SOL_SIZE";
    if (t_err == MSCN_ERR_SOL_NEG) return "MSCN_ERR_SOL_NEG";
    if (t_err == MSCN_ERR_FILE) return "MSCN_ERR_FILE";
    if (t_err == MSCN_ERR_SOL_MINMAX) return "MSCN_ERR_SOL_MINMAX";
    return "MSCN_NO_ERR";
}
