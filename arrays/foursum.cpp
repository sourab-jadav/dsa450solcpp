#include <iostream>
#include <algorithm>


#include <set>
#include <vector>



using namespace std;

// print quadrapule who's sum is equal to target
// the quadraple should be internally sorted

// 2026-11-21T13:46:42+05:30

// Input: arr[] = [0, 0, 2, 1, 1], target = 3
// Output: [[0, 0, 1, 2]]
// Explanation: Sum of 0, 0, 1, 2 is equal to 3.

// idea 1
// sort the input array first, and get the quadraple using 4 nested loops
// quad - 4 numbers are needed
// so frist loop i=0 i<=n-4(more intuitive) or i=0 i<n-3
// inner loop j=i+1 j<=n-3
// 3 inner k=j+1 k<=n-2
// 4 inner l=k+1 l<=n-1



class Solution {
public:
  vector<vector<int>> fourSum(vector<int> &nums, int target) {
      vector<vector<int>>result;
      std::set<vector<int>>set;
      int n = nums.size();
      sort(nums.begin(), nums.end());
      vector<vector<int>> output;
      for(int i=0;i<n-3;i++){
        for (int j = i + 1; j < n - 2; j++) {
            for(int k=j+1;k<n-1;k++){
                for(int l=k+1;l<n;l++){
                      if ((long long)nums[i] + nums[j] + nums[k] + nums[l] == target) { // in cpp addition is left associative
                                                                                        // so making the leftmost element long long
                                                                                        // makes all other operands on the right long long
                          set.insert({nums[i], nums[j], nums[k], nums[l]});
                      }
                  }
              }
          }
      }
      for(auto it:set){
          result.push_back(it);
      }
      return result;
    }
};

int main(int argc, char *argv[])
{


    return 0;
}
