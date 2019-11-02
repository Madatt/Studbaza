#include "table.h"
#include "test_constants.h"
#include <iostream>

int main() {
  CTable c_tab_0("1", 4);
  CTable c_tab_1("2", 6);
  CTable c_tab_2;

  c_tab_0.bSetValue(0, 22);
  c_tab_1.bSetValue(2, 39);
  c_tab_2 = c_tab_0 + c_tab_1;
  c_tab_0.vShow();
  c_tab_1.vShow();
  c_tab_2.vShow();
}
