#include <iostream>
#include <string>
#include <sstream>

using namespace std;

int main() {
    string text;
    cout << "Enter a string: ";
    getline(cin, text);

    stringstream ss(text);
    string word;
    string result = "";

    while (ss >> word) {
        char first = word[0];
        if (first >= 'A' && first <= 'Z') first += 32;
        if (string("aeiouy").find(first) == string::npos) {
            result += word + " ";
        }
    }

    cout << "Result: [" << result << "]" << endl;
    return 0;
}