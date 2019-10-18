#include <string>

#define C_D_TABLE_LEN 8
#define C_D_TABLE_NAME "default"

class CTable {
public:
  CTable();
  CTable(std::string sName, int iTableLen);
  CTable(const CTable &pcOther);
  virtual ~CTable();

  void vSetName(std::string sName);

  bool bSetNewSize(int iTableLen);
  int iGetSize() {return i_len;};

  CTable *pcClone();

private:
  std::string s_name;
  int* pi_tab;
  int i_len;
};

void v_mod_table(CTable* pcTab, int iNewSize);
void v_mod_table(CTable pcTab, int iNewSize);
