#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;


int solve(string s1, string s2, int n, int m,vector<vector<int>>&dp) {
    if (n==s1.size() || m==s2.size()) {
        return dp[n][m]= 0;
    }
    if(dp[n][m]!=-1){
        return dp[n][m];
    }
    if (s1[n]==s2[m]) {
        return dp[n][m]=1+solve(s1, s2, n+1, m+1,dp);
    }
    return dp[n][m]=max(solve(s1, s2, n+1, m,dp),solve(s1, s2, n, m+1,dp));
}
int lcs(string &s1, string &s2) {
    // code here
    int n=s1.size();
    int m=s2.size();
    vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
    return solve(s1,s2,0,0,dp);
}
int main(int argc, char *argv[])
{
    string s1 = "ABCDGH", s2 = "AEDFHR";



}
