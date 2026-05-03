#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

/**
 * we need to find
 * longest repeating sequence which repeats atleast 2 times
 * given a string
 * there is a subsequence which repeats we need to find that subseq
 *
 * The two identified subsequences A and B can use the same ith character from
 * string s if and only if that ith character has different indices in A and B.
 * For example, A = "xax" and B = "xax" then the index of the first "x" must be
 * different in the original string for A and B.
 */
int method1(string &s, int i, int j) {
    if (i < 0 || j < 0) {
        return 0;
    }
    if (s[i] == s[j] && i != j) {
        return 1 + method1(s, i - 1, j - 1);
    }
    return max(method1(s, i - 1, j), method1(s, i, j - 1));
}

int dp(string &s) {

    int n = s.size();
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (s[i - 1] == s[j - 1] && i != j) {
                dp[i][j] = 1 + dp[i - 1][j - 1];
            } else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    // for (auto v : dp) {
    //     for (auto  x : v) {
    //         cout << x << " ";
    //     }
    //     cout<<endl;
    // }
    return dp[n][n];
}

int main(int argc, char *argv[]) {
    // string s="axxzxy";          // passed
    // string s="pfoslsszfx";      // failed
    // expected is 2 got 3
    string s = "AABEBCDD";
    int n = s.size();

    // cout << method1(s, n-1, n-1) << "\n";
    cout << dp(s) << "\n";

    return 0;
}
