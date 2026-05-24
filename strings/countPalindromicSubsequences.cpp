#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;
bool checkPalindrome(string &str) {
    int i = 0;
    int j = str.length() - 1;
    while (i < j) {
        if (str[i] != str[j]) {
            return false;
        }
        i++;
        j--;
    }
    return true;
}
int solve(string &s, int i, string curr) {
    if (i == s.length()) {
        if (curr != "" && checkPalindrome(curr)) {
            return 1;
        } else {
            return 0;
        }
    }
    curr += s[i];
    int res1 = solve(s, i + 1, curr);
    curr.pop_back();
    int res2 = solve(s, i + 1, curr);
    return res1 + res2;

    // for a given index
}

int main(int argc, char *argv[]) {
    string s = "abcd";
    int n = s.length();

    cout << solve(s, 0, "") << "\n";

    return 0;
}
