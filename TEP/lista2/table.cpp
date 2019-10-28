#include "table.h"

#include <iostream>


CTable::CTable()
:s_name(C_D_TABLE_NAME), pi_tab(new int[C_D_TABLE_LEN]), i_len(C_D_TABLE_LEN) {
  std::cout << C_D_NOPARAM_MSG << s_name << std::endl;
}

CTable::CTable(std::string sName, int iTableLen)
:s_name(sName), pi_tab(NULL), i_len(iTableLen){
  if(iTableLen < 0)
    i_len = C_D_TABLE_LEN;

  pi_tab = new int[i_len];
  std::cout << C_D_PARAM_MSG << s_name << std::endl;
}

CTable::CTable(const CTable &pcOther)
:s_name(pcOther.s_name + C_D_COPY_PRE), pi_tab(new int[pcOther.i_len]), i_len(pcOther.i_len) {
  for(int i = 0; i < i_len; i++)
    pi_tab[i] = pcOther.pi_tab[i];
  //std::copy(pcOther.pi_tab, pcOther.pi_tab + i_len, pi_tab);
  std::cout << C_D_COPY_MSG << s_name << std::endl;
}

CTable::~CTable() {
  std::cout << C_D_DEL_MSG << s_name << std::endl;
  delete [] pi_tab;
}

void CTable::vSetName(std::string sName) {
  s_name = sName;
}

bool CTable::bSetNewSize(int iTableLen) {
  if(iTableLen < 0)
    return false;

  int i_end = iTableLen < i_len ? iTableLen : i_len;
  i_len = iTableLen;


  int* pi_new_tab = new int[iTableLen];
  for(int i = 0; i < i_end; i++)
    pi_new_tab[i] = pi_tab[i];
  //std::copy(pi_tab, pi_tab + i_len, tab);
  delete [] pi_tab;
  pi_tab = pi_new_tab;

  return true;
}

CTable* CTable::pcClone() {
  CTable* pi_new_tab = new CTable(*this);
  pi_new_tab->vSetName(s_name);
  return pi_new_tab;
}

bool CTable::bSetValue(int iN, int iVal) {
  if(iN < 0 or iN > i_len)
    return false;
  pi_tab[iN] = iVal;
  return true;
}

int CTable::iGetValue(int iN) {
  if(iN < 0 or iN > i_len)
    return 0;
  return pi_tab[iN];
}

void v_mod_table(CTable* pcTab, int iNewSize) {
  pcTab->bSetNewSize(iNewSize);
}

void v_mod_table(CTable pcTab, int iNewSize) {
  pcTab.bSetNewSize(iNewSize);
}

void v_print_table(CTable &pcTab) {
  for(int i = 0; i < pcTab.iGetSize(); i++)
    std::cout << pcTab.iGetValue(i) << " ";
}
