//
// Created by Madatt on 10.11.2019.
//

#ifndef LISTA4_CFILELASTERROR_H
#define LISTA4_CFILELASTERROR_H

#include <string>
#include <vector>
#include <cstdio>

class CFileLastError
{
public:
    static bool bGetLastError() {return(b_last_error);}

    CFileLastError();
    CFileLastError(std::string sFileName);
    ~CFileLastError();

    bool bIsOpen() {return (pf_file != NULL);};

    void vOpenFile(std::string sFileName);
    void vCloseFile();
    void vPrintLine(std::string sText);
    void vPrintManyLines(std::vector<std::string> sText);
private:
    static bool b_last_error;
    FILE *pf_file;

    static void vErr() {b_last_error = true;};
    static void vClear() {b_last_error = false;};
};


#endif //LISTA4_CFILELASTERROR_H
