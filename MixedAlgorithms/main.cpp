#include <iostream>
#include <cstring>
#include "RLE.h"
#include "RowCol.h"

using namespace std;

int main() {
    unsigned char src[1024], rowColEncrypted[1024], rleEncrypted[1024], decrypted[1024];
    unsigned int size, rowColEncryptedSize, rleEncryptedSize;

    cout << "Enter a string to encrypt: ";
    cin.getline((char*)src, 1024);

      cout << "Enter the RowCol key (number of columns): ";
    unsigned int rowColKey;
    cin >> rowColKey;

      rowcol rowColObj;
    rowColObj.SetKey(rowColKey);
    if (rowColObj.Encrypt(src, strlen((const char*)src), rowColEncrypted, rowColEncryptedSize)) {
        cout << "Failed to encrypt with RowCol cipher...\n";
        return -1;
    }
    rowColEncrypted[rowColEncryptedSize] = '\0';
    cout << "RowCol Encrypted string: " << rowColEncrypted << endl;

     RLE rle;
    if (rle.Encrypt(rowColEncrypted, rowColEncryptedSize, rleEncrypted, rleEncryptedSize)) {
        cout << "Failed to compress with RLE...\n";
        return -2;
    }
    rleEncrypted[rleEncryptedSize] = '\0';
    cout << "RLE Compressed string: " << rleEncrypted << endl;

     unsigned char rleDecrypted[1024];
    unsigned int rleDecryptedSize;
    if (rle.Decrypt(rleEncrypted, rleEncryptedSize, rleDecrypted, rleDecryptedSize)) {
        cout << "Failed to decrypt with RLE...\n";
        return -3;
    }
    rleDecrypted[rleDecryptedSize] = '\0';
    cout << "RLE Decompressed string: " << rleDecrypted << endl;

      if (rowColObj.Decrypt(rleDecrypted, rleDecryptedSize, decrypted, size)) {
        cout << "Failed to decrypt with RowCol cipher...\n";
        return -4;
    }
    decrypted[size] = '\0';
    cout << "Decrypted string: " << decrypted << endl;

      if (strcmp((const char*)src, (const char*)decrypted) == 0) {
        cout << "Success! Decryption is correct." << endl;
    } else {
        cout << "Decryption failed." << endl;
    }

    return 0;
}
