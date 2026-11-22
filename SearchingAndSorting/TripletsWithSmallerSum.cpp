#include <iostream>
#include <vector>

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

    int n = arr.size();
    int count{};
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
          for (int k = j + 1; k < n; k++) {
              if (arr[i]+arr[j]+arr[k]<sum) {
                  count++;
              }
            }
          }
    }
    return count;
  }
};


int main(int argc, char *argv[]) {
  // vector<int> vec{-2, 0, 1, 3};
  vector<int> vec{5, 1, 3, 4, 7};
  Solution s;
  cout << s.countTriplets(12, vec) << "\n";

  return 0;
}
