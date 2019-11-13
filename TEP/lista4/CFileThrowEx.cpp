//
// Created by Madatt on 10.11.2019.
//

#include "CFileThrowEx.h"

const int C_OPEN_FILE_ERR = 1;
const int C_CLOSE_FILE_ERR = 2;
const int C_PRINT_LINE_ERR = 3;
const int C_PRINT_MANY_LINES_ERR = 4;

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
        throw C_OPEN_FILE_ERR;

    pf_file = fopen(sFileName.c_str(), "w+");
    if (!bIsOpen()) {
        pf_file = NULL;
        throw C_OPEN_FILE_ERR;
    }
}

void CFileThrowEx::vCloseFile() {
    if (bIsOpen())
        fclose(pf_file);
    else
        throw C_CLOSE_FILE_ERR;
}

void CFileThrowEx::vPrintLine(std::string sText) {
    if (!bIsOpen())
        throw C_PRINT_LINE_ERR;

    fprintf(pf_file, (sText + "\n").c_str());
}

void CFileThrowEx::vPrintManyLines(std::vector<std::string> sText) {
    if (!bIsOpen())
        throw C_PRINT_MANY_LINES_ERR;

    for (std::vector<std::string>::iterator it = sText.begin(); it != sText.end(); ++it) {
        try {
            vPrintLine(*it);
        } catch (int e) {
            if (e == C_PRINT_LINE_ERR) throw C_PRINT_MANY_LINES_ERR;
        }
    }
}
