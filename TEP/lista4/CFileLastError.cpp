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
    vCloseFile();
}

void CFileLastError::vOpenFile(std::string sFileName) {
    b_last_error = false;

    if(bIsOpen())
    {
        b_last_error = true;
        return;
    }

    pf_file = fopen(sFileName.c_str(), "w+");
    if(!bIsOpen())
    {
        pf_file = NULL;
        b_last_error = true;
    }
}

void CFileLastError::vCloseFile() {
    b_last_error = false;
    if(bIsOpen())
        fclose(pf_file);
    else
        b_last_error = true;
}

void CFileLastError::vPrintLine(std::string sText) {
    b_last_error = false;

    if(!bIsOpen())
    {
        b_last_error = true;
        return;
    }

    fprintf(pf_file, (sText + "\n").c_str());
}

void CFileLastError::vPrintManyLines(std::vector<std::string> sText) {
    b_last_error = false;
    if(!bIsOpen())
    {
        b_last_error = true;
        return;
    }

    for(std::vector<std::string>::iterator it = sText.begin(); it != sText.end() or !b_last_error; ++it)
        vPrintLine(*it);
}
