#include <iostream>
#include <vector>
using namespace std;

/**
 * the matrix follows below rules
 *
 *     Each row is sorted in non-decreasing order.
 *     The first integer of each row is greater than the last integer of the previous row.
 */

bool searchMatrix(vector<vector<int>> &matrix, int target) {
    int m=matrix.size();
    int n=matrix[0].size();
    int total = m*n;

    int low=0;
    int high=total-1;
    int mid = (low+high)/2;
    // how would you binary search inside a matrix ??
    //
    int i=0;
    bool flag=false;
    while (i<m) {
        int low =0;
        int high = n-1;
        while (low<=high) {
            int mid = (low+high)/2;
            if (matrix[i][mid]==target) {
                flag=true;
                break;
            }else if (matrix[i][mid]<target) {
                low=mid+1;
            }else {
                high=mid-1;
            }
        }
        if (flag) {
            return true;
        }else {
            i++;
        }
    }
    return !(i==m);
}

int main(int argc, char *argv[])
{
    vector<vector<int>>mat={{1,3,5,7},{10,11,16,20},{23,30,34,60}};
    int target=234;
cout << searchMatrix(mat, target) << "\n";


    return 0;
}
