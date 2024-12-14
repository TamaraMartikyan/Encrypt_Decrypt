#pragma once

#include "Crypto.h"
#include <cstddef>

const unsigned int TemplateSize = 256;

class Cesar  : public Crypto
{
public:
	Cesar();
	virtual ~Cesar();

	virtual int Encrypt(const unsigned char* pSrc, unsigned int SrcSz, unsigned char* pOut, unsigned int& Outsz) override;
    virtual int Decrypt(const unsigned char* pSrc, unsigned int SrcSz, unsigned char* pOut, unsigned int& Outsz) override;

	int SetShift(unsigned int shift); // Set the shift value for Caesar cipher

private:

	unsigned int mShift; // Number of positions to shift

};
