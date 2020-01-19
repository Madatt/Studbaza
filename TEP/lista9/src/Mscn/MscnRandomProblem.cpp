#include "Utils.h"
#include "Mscn/MscnRandomProblem.h"

MscnProblem MscnRandomProblem::generate() {
    MscnProblem prob;

    fillRandom(prob.cd, rand, MSCN_C_MIN, MSCN_C_MAX);
    fillRandom(prob.cf, rand, MSCN_C_MIN, MSCN_C_MAX);
    fillRandom(prob.cm, rand, MSCN_C_MIN, MSCN_C_MAX);

    fillRandom(prob.ud, rand, MSCN_U_MIN, MSCN_U_MAX);
    fillRandom(prob.uf, rand, MSCN_U_MIN, MSCN_U_MAX);
    fillRandom(prob.um, rand, MSCN_U_MIN, MSCN_U_MAX);

    fillRandom(prob.sd, rand, MSCN_S_MIN, MSCN_S_MAX);
    fillRandom(prob.sf, rand, MSCN_S_MIN, MSCN_S_MAX);
    fillRandom(prob.sm, rand, MSCN_S_MIN, MSCN_S_MAX);
    fillRandom(prob.ss, rand, MSCN_S_MIN, MSCN_S_MAX);

    fillRandom(prob.ps, rand, MSCN_P_MIN, MSCN_P_MAX);

    int c = 0;
    for (int i = 0; i < prob.d; i++) {
        for (int j = 0; j < prob.f; j++) {
            prob.xdMinMax[c] = 0;
            prob.xdMinMax[c + 1] = prob.sd[i] / prob.d;
            c += 2;
        }
    }

    c = 0;
    for (int i = 0; i < prob.f; i++) {
        for (int j = 0; j < prob.m; j++) {
            prob.xfMinMax[c] = 0;
            prob.xfMinMax[c + 1] = prob.sf[i] / prob.f;
            c += 2;
        }
    }

    c = 0;
    for (int i = 0; i < prob.m; i++) {
        for (int j = 0; j < prob.s; j++) {
            prob.xmMinMax[c] = 0;
            prob.xmMinMax[c + 1] = prob.sm[i] / prob.m;
            c += 2;
        }
    }

    return prob;
}
