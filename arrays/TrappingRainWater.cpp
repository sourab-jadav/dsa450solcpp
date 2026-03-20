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
    int n=vec.size();
    for (int i = 0; i < n; i++) {
        cout << vec[i] << " ";
    }
    cout << "\n";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout<<endl;
}

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
    leftmax[0] = vec[0];
    rightmax[n - 1] = vec[n - 1];    // edge cases now are handled

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
        int temp{};
        if (leftmax[i] > rightmax[i]) {
            temp =
                ((leftmax[i] - (leftmax[i] - rightmax[i])) - vec[i]);
        } else {
            temp =
                ((rightmax[i] - (rightmax[i] - leftmax[i])) - vec[i]);
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
