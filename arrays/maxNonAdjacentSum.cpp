#include <bits/stdc++.h>

using namespace std;

// Input: arr[] = [6, 7, 1, 3, 8, 2, 4]
// Output: 19
// Explanation: Maximum amount he can get by looting 1st, 3rd, 5th and 7th house, which is 6 + 1 + 8 + 4 = 19.

// the constraint is you have to pick the numbers in such a way that
// if you pick a number at i you must not pick a number at index i-1 or i+1
// in that manner what is the max sum possible
//
// anology:
// Stickler the thief wants to loot money from the houses arranged in
// a line. He cannot loot two consecutive houses and aims to maximize
// his total loot. Given an array, arr[] where arr[i] represents the
// amount of money in the i-th house. Find the maximum amount he can
// loot.

// dp solution easiest
class Solution {
public:
  int findMaxSum(vector<int> &arr) {
    int n = arr.size();

    int dp[n + 1];
    memset(dp, 0, sizeof(dp));

    if (n == 1) {
      return arr[0];
    } else if (n == 2) {
      return max(arr[0], arr[1]);
    }
    dp[0] = 0;                  // if there are no houses then sum will be 0
    dp[1] = arr[0];             // if there is only house
    dp[2] = max(arr[1], arr[0]); // if there are two house you pick the max one

    // if there are three houses
    // you either include the current house value and solution of prev to prev value
    // or you do dp[i-1]

    for (int i = 3; i <= n; i++) { // i represents number of houses
      dp[i] = max(arr[i - 1] + dp[i - 2], dp[i - 1]);
    }

    return dp[n];
  }
};
