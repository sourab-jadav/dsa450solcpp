#include <algorithm>
#include <climits>
#include <iostream>
#include <vector>
using namespace std;
/**
 * how
 * minimum number of swaps to bring elements less than k
 * together
 * the idea is to first count no. of elements <=k
 * now maintain a window of size count
 * slide this window over the array and calculate the no. of swaps
 *
 */
int main(int argc, char *argv[]) {
    // int arr[] = { 2, 7, 9, 8, 5, 7, 4 };
    // vector<int>arr{2,1,5,6,3}  ;
    vector<int> arr{1, 10, 2, 3, 20, 4, 5};
    // int n=sizeof(arr)/sizeof(arr[0]);
    int n = arr.size();
    int k = 5;
    int good{};
    for (int i = 0; i < n; i++) {
        if (arr[i] <= k) {
            good++;
        }
    }
    int sp = 0;
    for (int i = 0; i < good; i++) {
        if (arr[i] > k) {
            sp++;
        }
    }
    cout << "good value is " << good << "\n";

    cout << "swaps we need for leftmost window " << sp << endl;
    int result = INT_MAX;

    // now at current element i
    // we need to check if it is greater than k
    // if it is <= k we decrease the swap count if arr[i-k] was part of swap
    // but we don't know the leftmost part of the window is part of swap or not
    //
    result = sp;
    for (int i = good; i < n; i++) {
        if (arr[i - good] > k) {
            if (arr[i] <= k) {
                sp--;
            }
        } else {
            if (arr[i] > k) {
                sp++;
            }
        }
        result=min(result,sp);
    }

    cout << result << "\n";

    return 0;
}
