#include <algorithm>
#include <iostream>
#include <vector>
#include <climits>

using namespace std;


/**
 * find max diff value of to mat value  (c,d) -(a,b)
 * such that c>a and d>b
 * (c,d) has be below (a,b) row-wise
 * (c,d) has to be after (a,b) column-wise
 * one idea is keep track of higher value so far from end of matrix
 *
 * M-1
 * why do we need a auxilary matrix here?
 * why can't we have a variable that keeps track of max variable so far
 *
 * we need an auxilary matrix to store max value of (c,d) until (a+1,b+1)
 *
 *M-2
 *we can decrease our scope from auxilary matrix to auxilary array
 *
 */
// method 1 brute force solution o(n^4) o(1)
int bruteForce(vector<vector<int>> mat, int m, int n) {
    int result=INT_MIN;
    for (int a = 0; a < m; a++) {
        for (int b=0; b<n; b++) {
            for (int c=a+1; c<m; c++) {
                for(int d=b+1;d<n;d++){
                 // if (mat[c][d]>mat[a][b]) {
                    if (mat[c][d]-mat[a][b]>result){ // better way
                     result=max(result,mat[c][d]-mat[a][b]);
                    }
                }
            }
        }
    }
    return result;
}

// method 2 :
// since mat[c][d] has to be maximum
// and to satisfy the condition c> a d>b
// we need to keep track of maximum from bottom right;
// for value at n-1 n-1 it is the maximum for itself as c,d is not possible
// for value at n-2 n-2 we need to check max value on column side
// and row side i.e i,j+1 (gives max at column)
// i+1,j (gives max at row)
int usingAuxilaryMatrix(vector<vector<int>>mat,int m,int n){
    vector<vector<int>>aux_mat(m,vector<int>(n,0));
    // the solution will only work for a square matrix
    aux_mat[n-1][n-1]=mat[n-1][n-1];
    for(int i=n-2;i>=0;i--){
        aux_mat[i][n-1]=max(mat[i][n-1],aux_mat[i+1][n-1]);
        aux_mat[n-1][i]=max(mat[n-1][i],aux_mat[n-1][i+1]);
    }
    // after fixing the the max values row wise and column wise
    for (int i = n - 2; i >= 0; i--) {
        for(int j=n-2;j>=0;j--){
            aux_mat[i][j]=max(mat[i][j],max(aux_mat[i][j+1],aux_mat[i+1][j]));
        }
    }
    cout<<"aux matrix is "<<endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << aux_mat[i][j] << " ";
        }
        cout<<endl;
    }
    int result{};
    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < n-1; j++) {
            if (aux_mat[i][j]>mat[i][j]) {
                cout << aux_mat[i][j]<< "  "<<mat[i][j] << "\n";
                result=max(result,aux_mat[i][j]-mat[i][j]);
            }
        }
    }
    return result;
}


int main(int argc, char *argv[])
{
vector<vector<int>>mat = {{ 1, 2, -1, -4, -20 },
             { -8, -3, 4, 2, 1 },
             { 3, 8, 6, 1, 3 },
             { -4, -1, 1, 7, -6 },
             { 0, -4, 10, -5, 1 }};
 int n=5;
 // cout<< bruteForce(mat, mat.size(), mat[0].size())<<endl;
 // cout << usingAuxilaryMatrix(mat, n, n) << "\n";
 cout <<method3_using_two_array(mat) << "\n";


    return 0;
}
