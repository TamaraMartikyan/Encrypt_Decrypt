#include "Cesar.h"
#include <string.h>
#include <iostream>
#include <algorithm>
#include <random>
#include <cstddef>

using namespace std;

#define BUF_SIZE  1024

int main()
{
    unsigned char src[BUF_SIZE], dest[BUF_SIZE], decrypt[BUF_SIZE];
    
    std::string str("This is an apple! 1234 ~!@#$%^&*()_+<>?");
    unsigned int size = static_cast<unsigned int>(str.size());
    
    // Initialize source buffer with the input string
    strncpy(reinterpret_cast<char*>(src), str.c_str(), BUF_SIZE);
    
    cout << "Text to encrypt:\n" << src << endl;
    
    // Initialize the Caesar cipher object
    Cesar obj;
    obj.SetShift(5); // Example shift value; can be set to any value between 0-255
    
    unsigned int outSize = BUF_SIZE;
    
    // Encrypt the source text
    if (obj.Encrypt(src, size, dest, outSize))
    {
        cout << "Failed to Encrypt...\n";
        return -1;
    }
    
    // Null-terminate the encrypted string for display purposes
    if (outSize < BUF_SIZE)
        dest[outSize] = '\0';
    else
        dest[BUF_SIZE - 1] = '\0';
    
    cout << "Encrypted text:\n";
    // Display encrypted text in hexadecimal to visualize all byte values
    for (unsigned int i = 0; i < size; ++i)
    {
        printf("%02X ", dest[i]);
    }
    cout << endl;
    
    // Decrypt the encrypted text
    if (obj.Decrypt(dest, size, decrypt, outSize))
    {
        cout << "Failed to Decrypt...\n";
        return -2;
    }
    
    // Null-terminate the decrypted string for display purposes
    if (outSize < BUF_SIZE)
        decrypt[outSize] = '\0';
    else
        decrypt[BUF_SIZE - 1] = '\0';
    
    cout << "Decrypted text:\n" << decrypt << endl;
    
    // Verify that decryption matches the original source
    if (strncmp(reinterpret_cast<const char*>(src), reinterpret_cast<const char*>(decrypt), size) != 0)
    {
        cout << "Failed: Decrypted text does not match the original." << endl;
    }
    else
    {
        cout << "Success: Decrypted text matches the original." << endl;
    }
    
    return 0;
}
