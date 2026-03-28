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

/**
 * another way is using prefix sum and binary search
 * create a prefix sum array
 * in a prefix sum array
 *
 * from value at index i+1 to n-1
 *     look for the value at j where prefix[j] > prefix[i]+x
 *     whatever i you pass you should include that i
 */
int binarySearch(vector<int> prefix, int x, int i) {
    cout << "i value is " << i << "\n";
    cout << "x value is " << x << "\n";

    int low = i;
    int n = prefix.size();
    int high = n - 1;
    int result = INT_MAX;
    while (low <= high) {
        int mid = (low + high) / 2;
        cout << "mid value is " << mid << "\n";
        if ((i == 0 && prefix[mid] > x) || prefix[mid] > prefix[i - 1] + x) {
            cout << "inside mid at " << mid << "\n";
            result = mid;
            high = mid - 1;
        } else if (prefix[mid] <= prefix[i] + x) {
            low = mid + 1;
        }
    }
    return result;
}
/**
 * this is working solution with all test cases passed
 */
int smallestSubWithSumUsingBS(int x, vector<int> &arr) {
  int sum{};
  vector<int> prefix;
  for (auto val : arr) {
    sum += val;
    prefix.push_back(sum);
  }
  cout << "prefix array is "
       << "\n";
  for (auto x : prefix) {
    cout << x << " ";
  }
  cout << endl;
  int n = prefix.size();
  int minval = INT_MAX;
  for (int i = 0; i < n - 1; i++) {
    int temp = binarySearch(prefix, x, i);

    if (temp != INT_MAX) {
      cout << "temp value is " << temp << "\n";
      minval = min(minval, temp - i + 1);
    }
  }
  return minval;
}

        if (temp != INT_MAX) {
            cout << "temp value is " << temp << "\n";
            minval = min(minval, temp - i + 1);
        }
    }
    return minval;
}

int main(int argc, char *argv[]) {

    vector<int> arr = {6829, 3917, 171, 3654};
    int x = 12829;

    cout << "the array values are "
         << "\n";

    for (auto x : arr) {
        cout << x << " ";
    }
    cout << endl;

    cout << smallestSubWithSum(x, arr);

    return 0;
}
