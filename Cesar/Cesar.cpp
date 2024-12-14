#include "Cesar.h"
#include <cstring>
#include <cstdlib>
#include <iostream>

Cesar::Cesar() : mShift(3) // Default shift set to 3
{
}

Cesar::~Cesar()
{
}

int Cesar::SetShift(unsigned int shift)
{
    mShift = shift % 256; // Ensuring the shift is within byte range
    return 0;
}

int Cesar::Encrypt(const unsigned char* psource, unsigned int sourcesize, unsigned char* pout, unsigned int& outsize)
{
    if (!psource || !pout || sourcesize == 0 || outsize < sourcesize)
        return -1;

    for (unsigned int i = 0; i < sourcesize; ++i)
    {
        pout[i] = static_cast<unsigned char>((psource[i] + mShift) % 256);
    }

    outsize = sourcesize; // Update the output size
    return 0;
}

int Cesar::Decrypt(const unsigned char* psource, unsigned int sourcesize, unsigned char* pout, unsigned int& outsize)
{
    if (!psource || !pout || sourcesize == 0 || outsize < sourcesize)
        return -1;

    for (unsigned int i = 0; i < sourcesize; ++i)
    {
        pout[i] = static_cast<unsigned char>((psource[i] - mShift + 256) % 256); // Adding 256 to avoid negative values
    }

    outsize = sourcesize; // Update the output size
    return 0;
}
