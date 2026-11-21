#include <algorithm>
#include <bits/stdc++.h>
#include <vector>

using namespace std;
class Solution {
public:
  vector<vector<int>> threeSum(vector<int> &nums) {
    int n = nums.size();
    sort(nums.begin(), nums.end());
    vector<vector<int>> result;
    for (int i = 0; i < n - 2; i++) {
      int low = i + 1;
      int high = n - 1;
      while (low < high) {
        if (nums[i] + nums[low] + nums[high] > 0) {
          high--;
        } else if (nums[i] + nums[low] + nums[high] < 0) {
          low++;
        } else {
          int l1 = low;
          int l2 = high;
          result.push_back({nums[i], nums[low], nums[high]});
          while (low < high && nums[low] == nums[l1]) {
            low++;
          }
          while (low < high && nums[high] == nums[l2]) {
            high--;
          }
        }
      }
      while (i + 1 < n && nums[i] == nums[i + 1]) {
        i++;
      }
    }
  }
};
int main(int argc, char *argv[]) {
  vector<int> vec{-1, 0, 1, 2, -1, -4};
  Solution s;
  s.threeSum(vec);

  return 0;
}
