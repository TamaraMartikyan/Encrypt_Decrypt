#include "rowcol.h"
#include <cstring>
#include <iostream>

using namespace std;

rowcol::rowcol() {}

rowcol::~rowcol() {}

int rowcol::Encrypt(const unsigned char* psource, unsigned int sourcesize, unsigned char* pout, unsigned int& outsize)
{
    if (!psource || !pout || !sourcesize || !outsize || outsize < sourcesize) {
        return -1; 
    }

     unsigned int numRows = (sourcesize + mkey - 1) / mkey;  
    unsigned int index = 0;
    char matrix[numRows][mkey];

    for (unsigned int i = 0; i < numRows; ++i)
        for (unsigned int j = 0; j < mkey; ++j)
            matrix[i][j] = ' ';

    for (unsigned int i = 0; i < numRows && index < sourcesize; ++i) {
        for (unsigned int j = 0; j < mkey && index < sourcesize; ++j) {
            matrix[i][j] = psource[index++];
        }
    }

    index = 0;
    for (unsigned int j = 0; j < mkey; ++j) {
        for (unsigned int i = 0; i < numRows; ++i) {
            pout[index++] = matrix[i][j];
        }
    }

    outsize = sourcesize;
    return 0; 
}

int rowcol::Decrypt(const unsigned char* psource, unsigned int sourcesize, unsigned char* pout, unsigned int& outsize)
{
    if (!psource || !pout || !sourcesize || outsize < sourcesize) {
        return -1; 
    }

    unsigned int numRows = (sourcesize + mkey - 1) / mkey;  
    unsigned int index = 0;
    char matrix[numRows][mkey];

    for (unsigned int i = 0; i < numRows; ++i)
        for (unsigned int j = 0; j < mkey; ++j)
            matrix[i][j] = ' ';

    for (unsigned int j = 0; j < mkey && index < sourcesize; ++j) {
        for (unsigned int i = 0; i < numRows && index < sourcesize; ++i) {
            matrix[i][j] = psource[index++];
        }
    }

    index = 0;
    for (unsigned int i = 0; i < numRows; ++i) {
        for (unsigned int j = 0; j < mkey; ++j) {
            pout[index++] = matrix[i][j];
        }
    }

    outsize = sourcesize;
    return 0; 
}

int rowcol::SetKey(unsigned int sz)
{
    mkey = sz;
    return 0;
}

int rowcol::GetKey()
{
    return mkey;
}
