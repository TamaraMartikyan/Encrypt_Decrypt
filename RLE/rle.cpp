#include <iostream>
#include <string>
using namespace std;

class RLE {
public:

	string encoded(const string& word) {
		string encoded = "";
		int n = word.length();

		for (int i = 0;i < n;i++) {
			int count = 1;

			while (i < n-1 && word[i] == word[i + 1]) {
				count++;
				i++;
			}

			encoded += word[i];
			encoded += to_string(count);
		}
		return encoded;

	}


	string decoded(const string& word) {
		string decoded = "";
		int n = word.length();

		for (int i = 0;i < n;i++) {
			char ch = word[i];
			i++;
			string countstr = "";

			while (i < n && isdigit(word[i])) {
				countstr += word[i];
				i++;

			}

			i--;

			int count = stoi(countstr);
			for (int j = 0;j < count;j++) {
				 decoded += ch;

			}
		}

		return decoded;
	}
};

int main() {

	RLE rle;
	//string word = "taammaaaraa";
	//cout << "The word is: " << word<<endl;
	//string encoded = rle.encoded(word);
	//cout << "Encoded word is: " << encoded << endl;

	//string encodedstr = "t1a2m2a3r1a2";
	//string decoded = rle.decoded(encoded);
	//cout << "Decoded word is:" << decoded << endl;
	
	string word = "";
	cout << "Enter a word: " << endl;
	cin >> word;

	string encodedword = rle.encoded(word);
	cout << "Encoded word is: " << encodedword << endl;

	string decodedword = rle.decoded(encodedword);
	cout << "Decoded word is:" << decodedword << endl;


	return 0;
}


