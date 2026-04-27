#include <iostream>
#include <queue>
#include <vector>

using namespace std;
void printmat(vector<vector<int>> &mat) {
    int n;
    for (auto row : mat) {
        for (auto v : row) {
            cout << v << " ";
        }
        cout << endl;
    }
}
/**
 * each row and column is sorted in non-decreasing order
 * find kth smallest element in the matrix
 *
 * it is sorted row-wise and column wise
 *     means value at 0,0 is least and value at n-1,n-1 is max
 *
 * from 0,0 you can go to 0,1 1,1, 1,0
 * second least value will be between 0,1 and 1,0
 *
 *
 */
// method 1 using min_heap
int usingMinHeap(vector<vector<int>> mat) {
    int n = mat.size();
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>,
                   greater<pair<int, pair<int, int>>>>
        pq;
    vector<vector<bool>> visited(n, vector<bool>(n, false));
    pq.push({mat[0][0], {0, 0}});
    visited[0][0] = true;

    // we have the visited vector and

    // now we will get the minimum element in the blink of an eye
    int k = 5;

    for (int i = 0; i < k - 1; i++) {
        auto curr = pq.top();
        pq.pop();

        int r = curr.second.first;
        int c = curr.second.second;

        if (r + 1 < n && !visited[r + 1][c]) {
            pq.push({mat[r + 1][c], {r + 1, c}});
            visited[r + 1][c] = true;
        }
        if (c + 1 < n && !visited[r][c + 1]) {
            pq.push({mat[r][c + 1], {r, c + 1}});
            visited[r][c + 1] = true;
        }
    }

    return pq.top().first;
}

/**
 * the most efficient approach here will be
 * to do binary search
 * you have the minimum and maximum value
 * get the mid of it
 * see how many elements are smaller than mid
 * if it is less than or equal k then you have to
 *   then do ans=mid and low=mid+1;
 * else high=mid-1;
 */
/**
 * we need to count elements <= mid more efficiently
 * from top to bottom if
 * the bottommost element is <= mid then all elements above it
 * will be <=mid
 * make use of this idea and traverse all the columns from left to right
 * and get the count
 */
int countLessEqual(vector<vector<int>>&mat,int mid)
{
    int n=mat.size();
    int row=n-1;
    int col = 0;
    int count{};
    while (row>=0 && col<n) {
        if (mat[row][col]<=mid) {
            count+=(row+1);
            col++;

        }else
            {
                row--;
            }

    }
    return count;
}
int usingBinarySearch(vector<vector<int>> &mat, int k) {

    int n = mat.size();
    int low = mat[0][0];
    int high = mat[n - 1][n - 1];
    int result{};

    while (low <= high) {
        int mid = (low + high) / 2;
        int count = 0;
        if (countLessEqual(mat, mid)>=k) {
            result=mid;
            high=mid-1;
        }else {
            low=mid+1;
        }
    }

    return result;
}
int main(int argc, char *argv[]) {

    // vector<vector<int>>mat{{10, 20, 30, 40},
    //                        {15, 25, 35, 45},
    //                         {24, 29, 37, 48},
    //                         {32, 33, 39, 50}};
    vector<vector<int>> mat{

        {16, 28, 60, 64}, {22, 41, 63, 91}, {27, 50, 87, 93}, {36, 78, 87, 94}};

    // the previous approaches are correct
    // but to find the min element you can make use min_heap
    // since heap by default provides max_heap you need to convert it to
    // min heap using greater function
    // usingMinHeap(mat);
    int k = 5;
    cout << "printing matrix" << endl;
    printmat(mat);
    cout << "===================================" << endl;

    cout<<usingBinarySearch(mat, k);
}
