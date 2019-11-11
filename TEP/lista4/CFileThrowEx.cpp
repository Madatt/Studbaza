//
// Created by Madatt on 10.11.2019.
//

#include "CFileThrowEx.h"

CFileThrowEx::CFileThrowEx()
        : pf_file(NULL) {

}

CFileThrowEx::CFileThrowEx(std::string sFileName) {
    vOpenFile(sFileName);
}

CFileThrowEx::~CFileThrowEx() {
    vCloseFile();
}

void CFileThrowEx::vOpenFile(std::string sFileName) {
    vCloseFile();

    pf_file = fopen(sFileName.c_str(), "w+");
    if(!bIsOpen())
    {
        pf_file = NULL;
        throw 1;
    }
}

void CFileThrowEx::vCloseFile() {
    if(bIsOpen())
        fclose(pf_file);
}

void CFileThrowEx::vPrintLine(std::string sText) {
    if(!bIsOpen())
    {
        throw 2;
        return;
    }

    fprintf(pf_file, (sText + "\n").c_str());
}

void CFileThrowEx::vPrintManyLines(std::vector<std::string> sText) {
    if(!bIsOpen())
    {
        throw 3;
        return;
    }

    for(std::vector<std::string>::iterator it = sText.begin(); it != sText.end(); ++it)
        fprintf(pf_file, (*it + "\n").c_str());
}
