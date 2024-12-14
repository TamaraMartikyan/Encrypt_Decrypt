#include "RowColRLE.h"
#include <iostream>

using namespace std;

RowColRLE::RowColRLE() {}

RowColRLE::~RowColRLE() {}

void RowColRLE::SetKey(unsigned int sz) {
    m_rowCol.SetKey(sz);  
}

int RowColRLE::Encrypt(const unsigned char* pSrc, unsigned int SrcSz, unsigned char* pOut, unsigned int& OutSz) {
    unsigned char intermediate[1024]; 
    unsigned int intermediateSz = sizeof(intermediate);

    int ret = m_rowCol.Encrypt(pSrc, SrcSz, intermediate, intermediateSz);
    if (ret != 0) {
        return ret;  
    }

     return m_rle.Encrypt(intermediate, intermediateSz, pOut, OutSz);
}

int RowColRLE::Decrypt(const unsigned char* pSrc, unsigned int SrcSz, unsigned char* pOut, unsigned int& OutSz) {
    unsigned char intermediate[1024]; 
    unsigned int intermediateSz = sizeof(intermediate);

 
    int ret = m_rle.Decrypt(pSrc, SrcSz, intermediate, intermediateSz);
    if (ret != 0) {
        return ret; 
    }

        return m_rowCol.Decrypt(intermediate, intermediateSz, pOut, OutSz);
}
