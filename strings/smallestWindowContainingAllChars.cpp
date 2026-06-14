#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

string bruteForceSolution(string &s, string &p) {
    int n = s.length();
    int m = p.length();
    string result = s;
    unordered_map<char, int> freq;
    for (int i = 0; i < m; i++) {
        freq[p[i] - 'a']++;
    }

    for (int i = 0; i < n - m; i++) {
        if (freq[s[i] - 'a'] > 0) {
            unordered_map<char, int> t = freq;
            t[s[i] - 'a']--;
            int length = 1;
            for (int j = i + 1; j < n; j++) {
                if (t[s[j] - 'a'] > 0) {
                    t[s[j] - 'a']--;
                    length++;
                    if (length == m && result.length() > j - i + 1) {
                        result = s.substr(i, j - i + 1);
                        break;
                    }
                }
            }
        }
    }
    if (result == s) {
        return "";
    } else {
        return result;
    }
}

int main(int argc, char *argv[]) {

}
