#include <algorithm>
#include <cstring>
#include <iostream>
#include <vector>

using namespace std;
int solve(vector<int> &vec, int k, int i,
          int j) { // k refers to no. of transacs
    if (k == 0) {
        return 0;
    }
    int result = 0;
    for (int l = i; l <= j; l++) {
        for (int m = l + 1; m <= j; ++m) {
            if (vec[m] - vec[l] > 0) {
                result = max(result, (vec[m] - vec[l]) + solve(vec, k - 1, m + 1, j));
            }
        }
    }
    return result;
}
/**
 * for max 1 transaction allowed
 *     as we move from left to right we keep track of current minimum
 *     if arr[i] < current minimum we update the minimum
 *     else we compare existing result with arr[i]-current_minimum
 *
 * for max 2 transactions
 *     as we move from left to right we keep track of current_min
 *     and do max(result,arr[i]-current_min) and call for
 *     max 1 transaction for i+1 to n-1;
 *
 *     (another efficient solution)
 *     as we keep track of current min can we keep track of current-max
 *     from the right
 */
int twoTransactions(vector<int> &vec) {
    int n = vec.size();
    if (n > 0) {
        // we have data to work with
        int current_min = vec[0];
        int left_profit[n];
        int right_profit[n];
        memset(left_profit, 0, sizeof(left_profit));
        memset(right_profit, 0, sizeof(right_profit));
        int result{};
        for (int i = 1; i < n; i++) {
            if (vec[i] < current_min) {
                current_min = vec[i];
            } else {
                result = max(result, vec[i] - current_min);
            }
            left_profit[i] = result;
        }
        result = 0;
        int currentmax = vec[n - 1];
        right_profit[n - 1] = 0;
        for (int i = n - 2; i >= 0; i--) {
            if (vec[i] > currentmax) {
                currentmax = vec[i];
            } else {
                result = max(result, currentmax - vec[i]);
            }
            right_profit[i] = result;
        }
        result = 0;
        for (int i = 0; i < n; i++) {
            result = max(result, left_profit[i] + right_profit[i]);
        }
        return result;
    }
}

int main(int argc, char *argv[]) {
    // vector<int> vec = {10, 22, 5, 75, 65, 80}; // test passed
    // vector<int> vec =  {100, 30, 15, 10, 8, 25, 80}; //test passed
    vector<int> vec = {90, 80, 70, 60, 50}; // test passed
    /**
     * constraints:
     * max 2 transactions allowed
     * cannot hold more than one stock
     *
     */
    std::cout << solve(vec, 2, 0, vec.size() - 1) << std::endl;

    return 0;
}
