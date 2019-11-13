//
// Created by Madatt on 11.11.2019.
//

#include "CFileErrCode.h"


CFileErrCode::CFileErrCode()
        : pf_file(NULL) {

}

CFileErrCode::CFileErrCode(std::string sFileName, bool& bErrCode) {
    bErrCode = bOpenFile(sFileName);
}

CFileErrCode::~CFileErrCode() {
    bCloseFile();
}

bool CFileErrCode::bOpenFile(std::string sFileName) {
    if (bIsOpen())
        return false;
    pf_file = fopen(sFileName.c_str(), "w+");
    if(!bIsOpen())
    {
        pf_file = NULL;
        return false;
    }

    return true;
}

bool CFileErrCode::bCloseFile() {
    if (bIsOpen())
        fclose(pf_file);
    else
        return false;

    return true;
}

bool CFileErrCode::bPrintLine(std::string sText) {
    if (!bIsOpen())
        return false;

    fprintf(pf_file, (sText + "\n").c_str());
    return true;
}

bool CFileErrCode::bPrintManyLines(std::vector<std::string> sText) {
    bool b_tmp = false;

    if (!bIsOpen())
        return false;

    for (std::vector<std::string>::iterator it = sText.begin(); it != sText.end() and !b_tmp; ++it) {
        b_tmp = bPrintLine(*it);
    }

    return b_tmp;
}
