#include <iostream>
#include <vector>

using namespace std;
/**
 * nice solution but TLE ;)
 */
bool areRotations(string &s1, string &s2) {
    if (s1.size() != s2.size()) {
        return false;
    }
    int n = s1.size();
    for (int i = 0; i < n; i++) {
        int count = 0;
        for (int j = 0; j < n; j++) {
            if (s1[j] == s2[(i + j) % n]) {
                count++;
            } else {
                break;
            }
        }
        if (count == n) {
            return true;
        }
    }
    return false;
}

/**
 * another solution for the same problem
 * count the occurences of the first character
 *
 * traverse through the second string that many times
 * this works but has worst case tc of o(n^2)
 * this happens when string has many repeating characters
 * causing you to check every possible starting index multiple times
 *
 * the most common way to optimize it is concatination trick
 */
bool areRotationsByFirstCharCount(string &s1, string &s2) {
    if (s1.size()!=s2.size()) {
        return false;
    }
    int n=s1.size();
    string combined = s1+s1;
    return (combined.find(s2)!=string::npos);
}

int main(int argc, char *argv[]) {
    // string s1="abcd";
    // string s1="geeksforgeeks";
    // string s2="forgeeksgeeks";

    string s1="labdbfvxigw";
    string s2="abdbfvxigwl";
    cout << areRotationsByFirstCharCount(s1, s2) << "\n";


    return 0;
}
