//
// Created by Madatt on 11.11.2019.
//

#ifndef LISTA4_CFILEERRCODE_H
#define LISTA4_CFILEERRCODE_H

#include <string>
#include <vector>
#include <cstdio>

class CFileErrCode
{
public:
    CFileErrCode();
    CFileErrCode(std::string sFileName, bool& bErrCode);
    ~CFileErrCode();

    bool bIsOpen() {return (pf_file != NULL);};

    bool bOpenFile(std::string sFileName);
    bool bCloseFile();
    bool bPrintLine(std::string sText);
    bool bPrintManyLines(std::vector<std::string> sText);
private:
    FILE *pf_file;
};



#endif //LISTA4_CFILEERRCODE_H
