#include <bits/stdc++.h>
#include <climits>
#include <cstring>
using namespace std;

int minJumps(vector<int> &nums, int l)
{
    if (l >= nums.size() - 1)
        return 0;
    int jumps = INT_MAX;
    for (int i = l + 1; i <= l + nums[l]; i++)
        jumps = min(jumps, 1 + minJumps(nums, i));
    return jumps;
}

// using dp solution
int dp(vector<int> &nums) {
    int n = nums.size();
    int dp[n];
    memset(dp, 0, sizeof(dp));
    // dp[n-1] is 0
    int jumps=INT_MAX;
    for (int i=n-2; i>=0; i--) {
        for (int j = i + 1; j <= i + nums[i] && j<n; j++) {
            dp[i]=min(jumps,1+dp[j]);
        }
    }
    return dp[0];
}
int main()
{
    // vector<int> nums{2, 3, 1, 1, 2, 4, 2, 0, 1, 1};
    //    vector<int> nums{2, 3, 1, 1, 4}; 
    vector<int> nums = { 1, 3, 5, 8, 9, 2, 6, 7, 6, 8, 9 };

    //    cout << minJumps(nums, 0);
    cout<<    dp(nums)    ;
}
