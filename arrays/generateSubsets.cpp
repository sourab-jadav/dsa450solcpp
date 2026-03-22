#include <iostream>
#include <vector>
using namespace std;

/**
 * given an array we have to generate all possible subsets from it
 *
 */
void generatesubsets(int arr[], int n, vector<vector<int>> &result,
                     vector<int> &vec) {

    if (n == 0) {
        result.push_back(vec);
        return;
    }

    vec.push_back(arr[n - 1]);
    generatesubsets(arr, n - 1, result, vec);
    vec.pop_back();
    generatesubsets(arr, n - 1, result, vec);
}

int main(int argc, char *argv[]) {
    int arr[] = {2, 4, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    vector<vector<int>> subsets;
    vector<int> vec;
    generatesubsets(arr, n, subsets, vec);
    for (auto vec : subsets) {
        for (auto ele : vec) {
            cout << ele << " ";
        }
        cout << endl;
    }

    cout << "something"
         << "\n";

    return 0;
}
