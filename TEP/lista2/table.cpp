#include "table.h"

#include <iostream>
#include <cstring>

CTable::CTable()
:s_name(C_D_TABLE_NAME), pi_tab(new int[C_D_TABLE_LEN]), i_len(C_D_TABLE_LEN) {
  std::cout << "bezp: " << s_name << std::endl;
}

CTable::CTable(std::string sName, int iTableLen)
:s_name(sName), pi_tab(new int[iTableLen]), i_len(iTableLen){
  std::cout << "parametr: " << s_name << std::endl;
}

CTable::CTable(CTable &pcOther)
:s_name(pcOther.s_name + "_copy"), pi_tab(new int[pcOther.i_len]), i_len(pcOther.i_len) {
  memcpy(pi_tab, pcOther.pi_tab, i_len);
  std::cout << "kopiuj: " << s_name << std::endl;
}

CTable::~CTable() {
  std::cout << "usuwam: " << s_name << std::endl;
  delete [] pi_tab;
}

void CTable::vSetName(std::string sName) {
  s_name = sName;
}

bool CTable::bSetNewSize(int iTableLen) {
  if(iTableLen <= 0 or iTableLen < i_len)
    return false;

  i_len = iTableLen;

  int* tab = new int[iTableLen];
  memcpy(tab, pi_tab, i_len);
  delete [] pi_tab;
  pi_tab = tab;

  return true;
}

CTable* CTable::pcClone() {
  return new CTable(*this);
}

void v_mod_table(CTable* pcTab, int iNewSize) {
  pcTab->bSetNewSize(iNewSize);
}

void v_mod_table(CTable pcTab, int iNewSize) {
  pcTab.bSetNewSize(iNewSize);
}
