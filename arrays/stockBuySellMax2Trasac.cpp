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
