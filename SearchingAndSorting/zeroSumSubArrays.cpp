#include <bits/stdc++.h>
#include <unordered_set>
#include <vector>

using namespace std;

// You are given an array arr[] of integers. Find the total count of
// subarrays with their sum equal to 0.

// Input: arr[] = [0, 0, 5, 5, 0, 0]
// Output: 6
// Explanation: The 6 subarrays are [0], [0], [0], [0], [0,0], and [0,0].
class Solution {
  public:
    int findSubarray(vector<int> &arr) {
      int n = arr.size();
      int count = 0;
      for (int i = 0; i < n; i++) {
        int sum = 0;
        for (int j = i; j < n; j++) {
          sum += arr[j];
          if (sum == 0) {
            count += 1;
          }
        }
      }
      return count;
    }
};
int main(){


}
