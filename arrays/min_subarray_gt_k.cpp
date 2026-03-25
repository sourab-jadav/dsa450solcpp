#include <algorithm>
#include <climits>
#include <iostream>
#include <vector>

using namespace std;

/**
 * Given an array arr[] of integers and a number x, the task is to
 * find the smallest subarray with a sum strictly greater than x.
 */

/**
 * one idea would be to get all the subsets
 * see which subset has the least length and satisfies sum > x
 *
 * idea 2 i think will be to keep adding sum
 * if the sum becomes > x or = x keep removing the elements from left
 *
 * eg 2
 */
// working solution but getting the runtime error
int smallestSubWithSum(int x, vector<int> &arr) {
  int result = INT_MAX;
  int n = arr.size();
  int sum{};
  for (int i = 0; i < n; i++) {
    if (arr[i] > x) {
      return 1;
    }
    sum += arr[i];
    if (sum > x) {
      int csum = sum;
      int j = 0;
      while (j < i && csum > x) {
        csum -= arr[j];
        result = min(result, i - j + 1);
        j++;
      }
    }
    if (i == n - 1 && sum <= x) {
      return 0;
    }
  }
  return result;
}

int main(int argc, char *argv[]) {

  // vector<int>arr = {1, 4, 45, 6, 0, 19};
  vector<int> arr = {1, 10, 5, 2, 7};
  int x = 51;

  cout << smallestSubWithSum(x, arr);

  return 0;
}
