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
    if(bIsOpen())
        vCloseFile();
}

void CFileThrowEx::vOpenFile(std::string sFileName) {
    if(bIsOpen())
        throw 1;

    pf_file = fopen(sFileName.c_str(), "w+");
    if (!bIsOpen()) {
        pf_file = NULL;
        throw 1;
    }
}

void CFileThrowEx::vCloseFile() {
    if (bIsOpen())
        fclose(pf_file);
    else
        throw 5;
}

void CFileThrowEx::vPrintLine(std::string sText) {
    if (!bIsOpen())
        throw 2;

    fprintf(pf_file, (sText + "\n").c_str());
}

void CFileThrowEx::vPrintManyLines(std::vector<std::string> sText) {
    if (!bIsOpen())
        throw 3;

    for (std::vector<std::string>::iterator it = sText.begin(); it != sText.end(); ++it) {
        try {
            vPrintLine(*it);
        } catch (int e) {
            if (e == 2) throw 4;
        }
    }
}
