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
        unordered_map<long long, int> freq;
      freq[0] = 1;

      long long prefixSum = 0;
      int count = 0;

      for (int x : arr) {
        prefixSum += x;
        count += freq[prefixSum];
        freq[prefixSum]++;
      }

      return count;
    }
};
int main(){


}
