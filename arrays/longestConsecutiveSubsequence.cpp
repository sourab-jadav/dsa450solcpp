
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
void printarray(vector<int> &vec) {
    for (auto x : vec) {
        cout << x << " ";
    }
    cout << endl;
}
int main(int argc, char *argv[]) {
    vector<int> arr{2, 6, 1, 9, 4, 5, 3};
    int n = arr.size();
    /**
     * longest consecutive subsequence
     * one way to solve it is:
     * sort the array
     * now find biggest subarray where arr[i]=arr[i-1];
     *
     */
    sort(arr.begin(), arr.end());
    printarray(arr);
    int result = 1;
    int subresult = 1;
    for (int i = 1; i < n; ++i) {
        if (arr[i]==arr[i-1]) {
            continue;           // handling repitations
        }
        if (arr[i] == arr[i - 1] + 1) {
            subresult++;
            result = max(result, subresult);
        } else {
            subresult = 1;
        }
    }
    cout << result << "\n";

    return 0;
}
