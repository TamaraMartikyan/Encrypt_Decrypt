#pragma once
#include "RowCol.h"
#include "RLE.h"
#include <cstddef>

class RowColRLE {
public:
    RowColRLE();
    virtual ~RowColRLE();

    int Encrypt(const unsigned char* pSrc, unsigned int SrcSz, unsigned char* pOut, unsigned int& OutSz);
    int Decrypt(const unsigned char* pSrc, unsigned int SrcSz, unsigned char* pOut, unsigned int& OutSz);

    void SetKey(unsigned int sz); 

private:
    rowcol m_rowCol;
    RLE m_rle;      
};
