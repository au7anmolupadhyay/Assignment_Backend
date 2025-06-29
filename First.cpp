#include <iostream>
#include <string>
using namespace std;

string caesarCipher(const string& input, int rotation) {
    string result = "";
    for (char ch : input) {
        if (isalpha(ch)) {
            char base = isupper(ch) ? 'A' : 'a';
            char shifted = (ch - base + rotation) % 26 + base;
            result += shifted;
        } else {
            result += ch; 
        }
    }
    return result;
}

string runLengthEncode(const string& input) {
    string result = "";
    int count = 1;
    for (int i = 1; i <= input.size(); ++i) {
        if (i < input.size() && input[i] == input[i - 1]) {
            count++;
        } else {
            result += input[i - 1];
            if (count > 1) {
                result += to_string(count);
            }
            count = 1;
        }
    }
    return result;
}

string specialCipher(const string& input, int rotation) {
    string caesared = caesarCipher(input, rotation);
    return runLengthEncode(caesared);
}

int main() {
    string input;
    cin>>input;
    int rotation;
    cin>>rotation;
    cout << specialCipher(input, rotation) << endl;  // Output: D2EF3
    return 0;
}
