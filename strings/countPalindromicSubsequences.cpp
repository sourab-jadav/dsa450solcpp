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


/**
 * try using memoization technique to solve the problem
 * if we maintain two pointers i and j mapping to 0 and n-1
 * if s[i]==s[j] then we count this as palindrome of size 2
 * and we recursively check for i j-1 and i+1 j
 *
 */
int countPSUtil(string &s,int i,int j, vector<vector<int>>&memo){
    if (i>j) {
        return 0;
    }

    if (i==j) {
        return 1;
    }

    if (memo[i][j]!=-1) {
        return memo[i][j];
    }

    /**
     * here you want to count the total number of palindromic subsequences
     * in the substring of s[i..j] to do this we look into two major subproblems
     *
     * WHEN S[i] != S[j] :
     *
     * 1. s[i+1..j]
     * 2. s[i..j-1]
     *
     * both of the subproblems will contain smaller subproblems s[i+1,j-1] excluding both the characters
     * since you are double counting the middle part s[i+1,j-1] you must subtract the overlapp
     * total=s[i+1..j]+s[i..j-1]-s[i+1,j-1];
     *
     * WHEN S[i] == S[j] :
     * you still have palindromes from the smaller problems. which still double counts the overlap
     * so your baseline formula is still:
     * count(i+1,j)+count(i,j-1)-count(i+1,j-1);
     *
     * additionally every single palindrome inside the middle overlap(s[i+1,j-1]) can be wrapped by
     * s[i] and s[j] to form a brand new longer palindrome
     * + s[i] and s[j] themselves together form 1 new palindrome bythemselves(or via empty inner string)
     *
     * newpalindrome = count(i+1,j-1)+1
     * total= count(i+1,j)+count(i,j-1)-count(i+1,j-1)+count(i+1,j-1)+1;
     * => count(i+1,j)+count(i,j-1)+1;
     *
     *
     */
    if (s[i]==s[j]) {
         memo[i][j]= 1+countPSUtil(s, i+1, j, memo)+countPSUtil(s, i, j-1, memo);
    } else {
         memo[i][j] = countPSUtil(s, i + 1, j, memo) +
                      countPSUtil(s, i, j - 1, memo) -
                      countPSUtil(s, i + 1, j - 1, memo);
    }
    return memo[i][j];
}

int main(int argc, char *argv[]) {
    string s = "abcd";
    int n = s.length();

    cout << solve(s, 0, "") << "\n";

    return 0;
}
