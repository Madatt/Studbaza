//
// Created by Madatt on 10.11.2019.
//

#ifndef LISTA4_CFILETHROWEX_H
#define LISTA4_CFILETHROWEX_H

#include <string>
#include <vector>
#include <cstdio>

class CFileThrowEx
{
public:
    CFileThrowEx();
    CFileThrowEx(std::string sFileName);
    ~CFileThrowEx();

    bool bIsOpen() {return (pf_file != NULL);};

    void vOpenFile(std::string sFileName);
    void vCloseFile();
    void vPrintLine(std::string sText);

    void vPrintManyLines(std::vector<std::string> sText);

private:
    FILE *pf_file;
};


#endif //LISTA4_CFILETHROWEX_H
