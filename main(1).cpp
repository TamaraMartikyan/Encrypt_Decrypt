#include <iostream>
#include <cstring>
#include "rowcol.h"

using namespace std;

int main() {
    unsigned char src[1024], dest[1024], decrypt[1024];
    unsigned int size, key;

    cout << "Enter a string to encrypt: ";
    cin.getline((char*)src, 1024);

    cout << "Enter the key (number of columns): ";
    cin >> key;

    size = strlen((const char*)src);

    rowcol obj;
    obj.SetKey(key);

     if (obj.Encrypt(src, size, dest, size)) {
        cout << "Failed to encrypt...\n";
        return -1;
    }

   dest[size] = '\0';
    cout << "Encrypted string: " << dest << endl;

     if (obj.Decrypt(dest, size, decrypt, size)) {
        cout << "Failed to decrypt...\n";
        return -2;
    }

    decrypt[size] = '\0';
    cout << "Decrypted string: " << decrypt << endl;

    if (strcmp((const char*)src, (const char*)decrypt)) {
        cout << "Decryption failed" << endl;
    } else {
        cout << "Success" << endl;
    }

    return 0;
}
