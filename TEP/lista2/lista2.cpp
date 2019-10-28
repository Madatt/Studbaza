#include "table.h"
#include "test_constants.h"
#include <iostream>

int main() {
  CTable* pc_tab1 = new CTable();
  CTable* pc_tab2 = new CTable(C_T_NAME1, C_T_TABLE_LEN1);

  pc_tab2->bSetValue(0, C_T_VAL1);
  pc_tab2->bSetValue(1, C_T_VAL2);

  CTable* pc_tab3 = new CTable(*pc_tab2);

  v_print_table(*pc_tab1);
  std::cout << std::endl;
  v_print_table(*pc_tab2);
  std::cout << std::endl;
  v_print_table(*pc_tab3);
  std::cout << std::endl;

  pc_tab3->bSetNewSize(C_T_TABLE_LEN1A);

  v_print_table(*pc_tab3);
  std::cout << std::endl;


  pc_tab3->bSetNewSize(C_T_TABLE_LEN3);

  v_print_table(*pc_tab3);
  std::cout << std::endl;

  CTable* pc_tab3_c = pc_tab3->pcClone();

  v_print_table(*pc_tab3);
  std::cout << std::endl;

  delete pc_tab1;
  delete pc_tab2;
  delete pc_tab3;
  delete pc_tab3_c;

  std::cout << std::endl;

  {
    CTable pc_tab4(C_T_NAME2, C_T_TABLE_LEN1);
    {
      CTable pc_tab5(C_T_NAME3, C_T_TABLE_LEN2);
    }
  }

  std::cout << std::endl;

  CTable* pc_tab6 = new CTable(C_T_NAME4, C_T_TABLE_LEN2);
  std::cout << pc_tab6->iGetSize() << std::endl;

  v_mod_table(*pc_tab6, C_T_TABLE_LEN3);
  std::cout << pc_tab6->iGetSize() << std::endl;

  v_mod_table(pc_tab6, C_T_TABLE_LEN3);
  std::cout  << pc_tab6->iGetSize() << std::endl;

  delete pc_tab6;


  CTable c_tab_arr[C_T_ARR_LEN];
  CTable* pc_tab_arr = new CTable[C_T_ARR_LEN];
  delete [] pc_tab_arr;

}
