#include <iostream>
using namespace std;

class Enc_Dec
{
private:
    string Alphabet;
    string subAlphabet;

public:
    Enc_Dec() {
        Alphabet = "abcdefghijklmnopqrstuvwxyz";
        subAlphabet = "qwertyuioplkjhgfdsazxcvbnm";
    }

    string encrypt(const string& word) {
        string encryptedWord = "";
        for (int i = 0; i < word.length(); ++i) {
            for (int j = 0; j < 26; ++j) {
                if (word[i] == Alphabet[j]) {
                    encryptedWord += subAlphabet[j];
                    break;
                }
            }
        }
        return encryptedWord;
    }

    string decrypt(const string& encryptedWord) {
        string decryptedWord = "";
        for (int i = 0; i < encryptedWord.length(); ++i) {
            for (int j = 0; j < 26; ++j) {
                if (encryptedWord[i] == subAlphabet[j]) {
                    decryptedWord += Alphabet[j];
                    break;
                }
            }
        }
        return decryptedWord;
    }
};

int main() {
    Enc_Dec ed;
    string word;

    cout << "Enter a word: ";
    cin >> word;

    string encryptedWord = ed.encrypt(word);
    cout << "Encrypted word: " << encryptedWord << endl;

     string decryptedWord = ed.decrypt(encryptedWord);
    cout << "Decrypted word: " << decryptedWord << endl;

    return 0;
}
