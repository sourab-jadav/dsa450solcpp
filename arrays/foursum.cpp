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



// class Solution {
// public:
//   vector<vector<int>> fourSum(vector<int> &nums, int target) {
//       vector<vector<int>>result;
//       std::set<vector<int>>set;
//       int n = nums.size();
//       sort(nums.begin(), nums.end());
//       vector<vector<int>> output;
//       for(int i=0;i<n-3;i++){
//         for (int j = i + 1; j < n - 2; j++) {
//             for(int k=j+1;k<n-1;k++){
//                 for(int l=k+1;l<n;l++){
//                       if ((long long)nums[i] + nums[j] + nums[k] + nums[l] == target) { // in cpp addition is left associative
//                                                                                         // so making the leftmost element long long
//                                                                                         // makes all other operands on the right long long
//                           set.insert({nums[i], nums[j], nums[k], nums[l]});
//                       }
//                   }
//               }
//           }
//       }
//       for(auto it:set){
//           result.push_back(it);
//       }
//       return result;
//     }
// };


// efficient solutoin

// class Solution {
// public:
//     vector<vector<int>> fourSum(vector<int>& nums, int target) {
//       // solved using 3 nexted loops + sorting + hashtable
//       // the optimization here is
//       // since it is sorted we can pick the last two elements using binary
//       // search
//          int n = nums.size();
//         sort(nums.begin(), nums.end());
//         set<vector<int>> set;
//         vector<vector<int>> output;
//         for(int i=0; i<n-3; i++){
//             for(int j=i+1; j<n-2; j++){
//                 long long newTarget = (long long)target - nums[i] - nums[j];
//                 int low = j+1, high = n-1;
//                 while(low < high){
//                     if(nums[low] + nums[high] < newTarget){
//                         low++;
//                     }
//                     else if(nums[low] + nums[high] > newTarget){
//                         high--;
//                     }
//                     else{
//                         set.insert({nums[i], nums[j], nums[low], nums[high]});
//                         low++; high--;
//                     }
//                 }
//             }
//         }
//         for(auto it : set){
//             output.push_back(it);
//         }
//         return output;
//     }
// };


// previous solution didicn't take care of duplicate arrays efficiently instead it relied on the set
class Solution {

public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
         int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<vector<int>> output;
        for(int i=0; i<n-3; i++){
            for(int j=i+1; j<n-2; j++){
                long long newTarget = (long long)target - nums[i] - nums[j];
                int low = j+1, high = n-1;
                while(low < high){
                    if(nums[low] + nums[high] < newTarget){
                        low++;
                    }
                    else if(nums[low] + nums[high] > newTarget){
                        high--;
                    }
                    else{
                        output.push_back({nums[i], nums[j], nums[low], nums[high]});
                        int tempIndex1 = low, tempIndex2 = high;
                        while(low < high && nums[low] == nums[tempIndex1]) low++; // exluding duplicates of k
                        while(low < high && nums[high] == nums[tempIndex2]) high--; // exluding duplicates of l
                    }
                }
                while(j+1 < n && nums[j] == nums[j+1]) j++; // exluding duplicates of i
            }
            while(i+1 < n && nums[i] == nums[i+1]) i++; // exluding duplicates of j
        }
        return output;
    }
};



int main(int argc, char *argv[])
{


    return 0;
}
