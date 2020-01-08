#include <string>

const int C_D_TABLE_LEN = 8;
const std::string C_D_TABLE_NAME = "default";

const std::string C_D_DEL_MSG = "usuwam: ";
const std::string C_D_PARAM_MSG = "parametr: ";
const std::string C_D_NOPARAM_MSG = "bezp: ";
const std::string C_D_COPY_MSG = "kopiuje: ";

const std::string C_D_COPY_PRE = "_kopia";

class CTable {
public:
    CTable();

    CTable(std::string sName, int iTableLen);

    CTable(const CTable &pcOther);

    virtual ~CTable();

    static int i_debug_copy;

    CTable operator+(const CTable &pcRight);

    CTable& operator=(const CTable &pcRight);

    CTable& operator/=(const int &iRight);

    void vSetName(std::string sName);

    bool bSetNewSize(int iTableLen);

    int iGetSize() { return i_len; };

    bool bSetValue(int iN, int iVal);

    int iGetValue(int iN);


    CTable *pcClone();

    void vShow();

    void vFillRising();

    void vFillRising(int iN);

    CTable cGetPairSumsTable();

private:
    std::string s_name;
    int *pi_tab;
    int i_len;
};

void v_mod_table(CTable *pcTab, int iNewSize);

void v_mod_table(CTable pcTab, int iNewSize);

void v_print_table(CTable &pcTab);
