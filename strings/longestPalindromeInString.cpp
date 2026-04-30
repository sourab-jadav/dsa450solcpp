#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

// the question is to find longest palindrome substring within s
// say s="geeks"
// longest palindrome is "ee"

/**
 * one method is to use recursive solution
 * the smallest palindrome will of size 1(each char itself)
 *
 * assume each character as the middle point of palindrome
 * traverse and towards right and left and compare until leftmost
 * and rightmost character do not match
 */
 string longestPalindrome(string s, int i, int j) {
    if (i<0 || j>=s.size() || s[i] !=s[j]) {
        return s.substr(i+1,(j-i-1));
    }
    int n=s.size();
    return longestPalindrome(s, i-1, j+1);
}

string solve(string s){
    int n=s.size();
    int result=1;
    string str=to_string(s[0]);


    for (int i = 1; i < n; i++) {
        if (s[i]==s[i-1]) {
            string got=longestPalindrome(s, i-1, i);
            if (got.size()>result) {
                str=got;
                result=got.size();
            }
        }
        if (i+1 <n && s[i-1]==s[i+1]) {
            string got = longestPalindrome(s, i-1, i+1);
            if (got.size()>result) {
                str=got;
                result=got.size();
            }
        }
    }
    return str;
}


int main(int argc, char *argv[])
{
    // string s = "forgeeksskeegfor";
    string s="abacdfgdcaba";
    string res="geeksskeeg"    ;
    cout << solve(s) << "\n";




    return 0;
}
