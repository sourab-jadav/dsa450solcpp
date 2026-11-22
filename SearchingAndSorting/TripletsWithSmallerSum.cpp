#include <iostream>
#include <vector>
#include <algorithm>


// 2026-11-22

// Given an array arr[] of distinct integers and an integer sum, count
// the number of unique triplets of elements whose sum is strictly
// less than sum. A triplet is identified only by the three elements
// it contains, so different permutations of the same three elements
// are counted as one triplet.

// Input: sum = 2, arr[] = [-2, 0, 1, 3]
// Output:  2
// Explanation: Triplets with sum less than 2 are (-2, 0, 1) and (-2, 0, 3).

using namespace std;
// class Solution {
// public:
//   int solve(int sum, vector<int> vec, int curr, int count, int i) {
//     int n = vec.size();
//     if (count == 3 && curr < sum) {
//       return 1;
//     }
//     if (i == vec.size() || curr > sum) {
//       return 0;
//     }

//     return solve(sum, vec, curr + vec[i], count + 1, i + 1) +
//            solve(sum, vec, curr, count, i + 1);
//   }

//   int countTriplets(int sum, vector<int> &arr) {

//     return solve(sum, arr, 0, 0, 0);
//   }
// };


/* optimization over recursiion*/
class Solution {
public:
  int countTriplets(int sum, vector<int> &arr) {
      // one optimal approach is to fix the current element
      // as part of the triplet and find the next two elements by binary search
      int n = arr.size();
      int count{};
      sort(arr.begin(), arr.end());

      int i = 0;
      while (i <= n - 3) {
        int low = i + 1;
        int high = n - 1;
        while (low < high) {
          long long result = (long long)arr[i] + arr[low] + arr[high];
          if (result < sum) {

            count += high - low;
            low++;
            while (arr[high] == arr[high - 1]) {
              high--;
            }
            while (arr[low] == arr[low + 1]) {
              low++;
            }

          } else if (result >= sum) {
            high--;
          }
        }
        if (i + 1 < n && arr[i] == arr[i + 1]) {
          while (i + 1 < n && arr[i] == arr[i + 1]) {
            i++;
          }
        } else {
          i++;
        }
      }
      return count;
  }
};


int main(int argc, char *argv[]) {
  vector<int> vec{-2, 0, 1, 3};
  // vector<int> vec{5, 1, 3, 4, 7};
  Solution s;
  cout << s.countTriplets(2, vec) << "\n";

  return 0;
}
