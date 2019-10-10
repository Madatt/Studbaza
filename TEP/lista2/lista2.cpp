#include "table.h"
#include <iostream>

int main() {
  CTable* pc_tab1 = new CTable();
  CTable* pc_tab2 = new CTable("asd", 4);
  CTable* pc_tab3 = new CTable(*pc_tab2);

  std::cout << std::endl;

  delete pc_tab1;
  delete pc_tab2;
  delete pc_tab3;

  std::cout << std::endl;

  {
    CTable pc_tab4("tab4", 4);
    {
      CTable pc_tab5("tab5", 5);
    }
  }

  std::cout << std::endl;

  CTable* pc_tab6 = new CTable("tab6", 6);
  std::cout << "dlugosc tab6: " << pc_tab6->iGetSize() << std::endl;

  v_mod_table(*pc_tab6, 12);
  std::cout << "dlugosc tab6: " << pc_tab6->iGetSize() << std::endl;

  v_mod_table(pc_tab6, 12);
  std::cout << "dlugosc tab6: " << pc_tab6->iGetSize() << std::endl;

  delete pc_tab6;
}
