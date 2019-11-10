//
// Created by Madatt on 10.11.2019.
//

#include "CFileLastError.h"

bool CFileLastError::b_last_error = false;

CFileLastError::CFileLastError()
:pf_file(NULL)
{

}

CFileLastError::CFileLastError(std::string sFileName) {
    vOpenFile(sFileName);
}

CFileLastError::~CFileLastError() {
    if(bIsOpen())
        vCloseFile();
}

void CFileLastError::vOpenFile(std::string sFileName) {
    vClear();

    if(bIsOpen())
        vCloseFile();

    pf_file = fopen(sFileName.c_str(), "w+");
    if(!bIsOpen())
    {
        pf_file = NULL;
        vErr();
    }
}

void CFileLastError::vCloseFile() {
    fclose(pf_file);
}

void CFileLastError::vPrintLine(std::string sText) {
    vClear();

    if(!bIsOpen())
    {
        vErr();
        return;
    }

    fprintf(pf_file, (sText + "\n").c_str());
}

void CFileLastError::vPrintManyLines(std::vector<std::string> sText) {
    vClear();

    if(!bIsOpen())
    {
        vErr();
        return;
    }

    for(std::vector<std::string>::iterator it = sText.begin(); it != sText.end(); ++it)
        fprintf(pf_file, (*it + "\n").c_str());
}
