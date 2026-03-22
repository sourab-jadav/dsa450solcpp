#include <algorithm>
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
void printArray(vector<int> &vec, int arr[]) {
    int n = vec.size();
    for (int i = 0; i < n; i++) {
        cout << vec[i] << " ";
    }
    cout << "\n";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}
void prefixSuffixmethod(vector<int> &vec) {
    // vector<int> vec{3, 0, 1, 0, 4, 0, 2};
    // vector<int>vec = {3, 0, 2, 0, 4}; // passed
    int n = vec.size();
    int leftmax[n];
    int rightmax[n];
    memset(leftmax, -1, sizeof(leftmax));
    memset(rightmax, -1, sizeof(rightmax));

    /**
     * there is a need to handle the edge cases
     *
     */
    leftmax[0] = vec[0];
    rightmax[n - 1] = vec[n - 1]; // edge cases now are handled

    for (int i = 1; i < n; i++) {
        if (vec[i] > leftmax[i - 1]) {
            leftmax[i] = vec[i];
        } else {
            leftmax[i] = leftmax[i - 1];
        }
    }
    printArray(vec, leftmax);

    for (int i = n - 2; i >= 0; i--) {
        if (vec[i] > rightmax[i + 1]) {
            rightmax[i] = vec[i];
        } else {
            rightmax[i] = rightmax[i + 1];
        }
    }
    cout << endl;
    cout << "===================================" << endl;
    printArray(vec, rightmax);
    int result{};
    cout << endl;
    for (int i = 1; i <= n - 2; i++) {
        int minval = min(leftmax[i], rightmax[i]);
        result += minval - vec[i];
    }
    cout << endl;
    cout << result;
}

int usingTwoPointer(vector<int> &vec) {

    // two pointer approach
    /**
     * we maintain two pointers
     * left and right
     * leftmax and rightmax
     *
     */
    int n = vec.size();
    int left = 1;
    int right = n - 2;
    int leftmax = vec.at(0);
    int rightmax = vec.at(n - 1);
    int result{};

    /**
     * at any given time whichever is the lowest we consider that value
     * either leftmax or rightmax
     */
    while (left <= right) {
        /**
         * here even if both lmax and rmax equal
         * we only move left pointer
         * it is working what if we move both left and right
         * to move both
         *     we need a comparision of valut at left on leftmax
         *     and value at right on rightmax
         *     since both any ways converging
         *     let's not handle lmax = rmax sepeartely
         */
        if (leftmax <= rightmax) {
            if (vec[left] < leftmax) {
                result += leftmax - vec[left];
            } else {
                leftmax = vec[left];
            }
            left++;
        } else if (rightmax < leftmax) {
            if (vec[right] < rightmax) {
                result += rightmax - vec[right];
            } else {
                rightmax = vec[right];
            }
            right--;
        }
    }
    return result;
}

int main(int argc, char *argv[]) {
    vector<int> vec = {1, 2, 3, 4};
    vector<int> arr = {2, 1, 5, 3, 1, 0, 4};
    cout << usingTwoPointer(arr) << endl;
    // prefixSuffixmethod(vec);

    return 0;
}
