#include <iostream>
#include <vector>

using namespace std;
void printMatrix(vector<vector<int>> &mat, int m, int n) {
    cout << "---- ----"
         << "\n";

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; ++j) {
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }
    cout << "---- ----"
         << "\n";
}

void printSpiral(vector<vector<int>> &mat, int m, int n) {

    // spiral of a matrix
    int top = 0;
    int bottom = m - 1;
    int left = 0;
    int right = n - 1;

    while (top < bottom) {
        for (int i = top; i < right; i++) {
            cout << mat[top][i] << " ";
        }
        cout << endl;

        // loop through all rows in column
        for (int j = top; j < bottom; j++) {
            cout << mat[j][right] << " ";
        }
        cout << endl;

        for (int k = right; k > left; k--) {
            cout << mat[bottom][k] << " ";
        }
        cout << endl;

        for (int l = bottom; l > top; l--) {
            cout << mat[l][left] << " ";
        }
        cout << endl;
        top++;
        bottom--;
        right--;
        left++;
    }
}

int main(int argc, char *argv[]) {
    vector<vector<int>> mat = {
        {1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}, {13, 14, 15, 16}};

    // spiral traversal of a matrix
    int m = mat.size();
    int n = mat[0].size();
    printMatrix(mat, m, n);
    cout << endl;
    cout << endl;
    //    j              n
    // i[[1,   2,   3,   4],
    //  [5,    6,   7,   8],
    //  [9,   10,  11,  12],
    // m[13,  14,  15,  16]]
    printSpiral(mat, m, n);

    return 0;
}
