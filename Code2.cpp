#include <iostream>
#include <string>
#include <cctype>
#include <regex>
using namespace std;

string GeneratePattern(string str) {
    string pattern = "";
    int i = 0;

    while (i < str.length()) {
        char currentChar = str[i];

        if (currentChar == '+') {
            pattern += "[A-Za-z]";
        } else if (currentChar == '$') {
            pattern += "[1-9]";
        } else if (currentChar == '*') {
            int repeatCount = 3;

            if (i + 1 < str.length() && str[i + 1] == '{') {
                int j = i + 2;
                while (j < str.length() && isdigit(str[j])) {
                    j++;
                }
                repeatCount = stoi(str.substr(i + 2, j - i - 2));
                i = j;
            }

            pattern += "[A-Za-z]{" + to_string(repeatCount) + "}";
        }

        i++;
    }

    return pattern;
}

string StringChallenge(string str) {
    size_t spacePos = str.find(" ");

    if (spacePos == string::npos) {
        return "false"; // Invalid input format
    }

    string pattern = "^" + GeneratePattern(str.substr(0, spacePos)) + "$";
    string secondStr = str.substr(spacePos + 1);

    return regex_match(secondStr, regex(pattern)) ? "true" : "false";
}

int main(void) {
    // Example inputs
    cout << StringChallenge("+++++* abcdehhhhhh") << endl; // Output: false
    cout << StringChallenge("$**+*{2} 9mmmrrrkbb") << endl; // Output: true

    return 0;
}
