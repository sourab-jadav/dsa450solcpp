#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
/**
 * given a matrix which is sorted row wise
 * you need to find the median of the matrix
 */
int median(vector<vector<int>> &mat) {
    int m = mat.size();
    int n = mat[0].size();

    vector<int> result;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            result.push_back(mat[i][j]);
        }
    }
    sort(result.begin(), result.end());
    int median{};
    int total = m * n;
    if (total % 2 != 0) {
        total = (total - 1) / 2;
        median = result[total];
    } else {
        total = (total) / 2;
        median = (result[total] + result[total - 1]) / 2;
    }
    return median;
}
int main(int argc, char *argv[]) {
    vector<vector<int>> mat = {{1, 3, 5}, {2, 6, 9}, {3, 6, 9}};

    cout << median(mat) << "\n";



    return 0;
}
