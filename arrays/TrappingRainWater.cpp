#include <cstring>
#include <iostream>
#include <vector>

using namespace std;
/**
 * given an array with non-negative nummbers
 * if the width of each block is 1 compute how much water can be
 * trapped in each block
 */
/**
 * maintain two array
 * one has the index of left max
 * another stores of index of right max
 * instead of index here we can easily solve with the left max
 * and the right max value so far
 */

int main(int argc, char *argv[]) {
    // vector<int> vec{3, 0, 1, 0, 4, 0, 2};
    // vector<int>vec = {3, 0, 2, 0, 4}; // passed
    vector<int> vec = {1, 2, 3, 4};
    int n = vec.size();

    int leftmax[n];
    int rightmax[n];
    memset(leftmax, -1, sizeof(leftmax));
    memset(rightmax, -1, sizeof(rightmax));

    /**
     * there is a need to handle the edge cases
     *
     */
    leftmax[0] = 0;
    rightmax[n - 1] = n - 1;    // edge cases now are handled

    for (int i = 1; i < n; i++) {
        if (vec[i] > vec[leftmax[i - 1]]) {
            leftmax[i] = i;
        } else {
            leftmax[i] = leftmax[i - 1];
        }
    }
    for (int i = 0; i < n; i++) {
        cout << vec[i] << " ";
    }
    cout << "\n";
    for (int i = 0; i < n; i++) {
        cout << vec[leftmax[i]] << " ";
    }

    for (int i = n - 2; i >= 0; i--) {
        if (vec[i] > vec[rightmax[i + 1]]) {
            rightmax[i] = i;
        } else {
            rightmax[i] = rightmax[i + 1];
        }
    }
    cout << endl;
    cout << "===================================" << endl;
    for (int i = 0; i < n; i++) {
        cout << vec[i] << " ";
    }
    cout << "\n";
    for (int i = 0; i < n; i++) {
        cout << vec[rightmax[i]] << " ";
    }
    int result{};
    cout << endl;
    for (int i = 1; i <= n - 2; i++) {
        int temp{};
        if (vec[leftmax[i]] > vec[rightmax[i]]) {
            temp =
                ((vec[leftmax[i]] - (vec[leftmax[i]] - vec[rightmax[i]])) - vec[i]);
        } else {
            temp =
                ((vec[rightmax[i]] - (vec[rightmax[i]] - vec[leftmax[i]])) - vec[i]);
        }
        cout << temp << " ";
        result += temp;
    }
    cout << endl;
    cout << result;
    cout << "someting"
         << "\n";

    return 0;
}
