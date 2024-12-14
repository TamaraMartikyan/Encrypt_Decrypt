#include <iostream>
#include <string>

using namespace std;


string rowColumnEncode(const string& word, int rows, int cols) {
    char matrix[rows][cols];
    int index = 0;

    
    for (int r = 0; r < rows; ++r) {
        for (int c = 0; c < cols; ++c) {
            if (index < word.size()) {
                matrix[r][c] = word[index++];
            } else {
                matrix[r][c] = ' '; 
            }
        }
    }

   
    string encoded;
    for (int c = 0; c < cols; ++c) {
        for (int r = 0; r < rows; ++r) {
            if (matrix[r][c] != ' ') {
                encoded += matrix[r][c];
            }
        }
    }

    return encoded;
}


string runLengthEncode(const string& encoded) {
    string rle;
    int count = 1;

    for (int i = 1; i <= encoded.size(); ++i) {
        if (i < encoded.size() && encoded[i] == encoded[i - 1]) {
            count++;
        } else {
            rle += encoded[i - 1];
            if (count > 1) {
                rle += to_string(count);
            }
            count = 1;
        }
    }

    return rle;
}


string runLengthDecode(const string& rle) {
    string decoded;
    for (int i = 0; i < rle.size(); ++i) {
        char ch = rle[i];
        int count = 1;

       
        if (i + 1 < rle.size() && isdigit(rle[i + 1])) {
            count = rle[++i] - '0';
            while (i + 1 < rle.size() && isdigit(rle[i + 1])) {
                count = count * 10 + (rle[++i] - '0');
            }
        }

        
        decoded.append(count, ch);
    }

    return decoded;
}


string rowColumnDecode(const string& encoded, int rows, int cols) {
    char matrix[rows][cols];
    int index = 0;


    for (int c = 0; c < cols; ++c) {
        for (int r = 0; r < rows; ++r) {
            if (index < encoded.size()) {
                matrix[r][c] = encoded[index++];
            } else {
                matrix[r][c] = ' ';
            }
        }
    }

   
    string decoded;
    for (int r = 0; r < rows; ++r) {
        for (int c = 0; c < cols; ++c) {
            if (matrix[r][c] != ' ') {
                decoded += matrix[r][c];
            }
        }
    }

    return decoded;
}


string encode(const string& word, int rows, int cols) {
    string encoded = rowColumnEncode(word, rows, cols);
    return runLengthEncode(encoded);
}


string decode(const string& rle, int rows, int cols) {
    string decodedRLE = runLengthDecode(rle);
    return rowColumnDecode(decodedRLE, rows, cols);
}

int main() {
    string word = "helloworld";
    int rows = 3, cols = 5;

    // Encoding
    string encoded = encode(word, rows, cols);
    cout << "Encoded: " << encoded << endl;

    // Decoding
    string decoded = decode(encoded, rows, cols);
    cout << "Decoded: " << decoded << endl;

    return 0;
}
