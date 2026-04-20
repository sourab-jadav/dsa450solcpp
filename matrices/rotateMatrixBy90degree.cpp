#include <iostream>
#include <type_traits>
#include <utility>
#include <vector>
using namespace std;
void printMatrix(vector<vector<int>> vec) {
    int n = vec.size();
    for (int i = 0; i < n; i++) {
        for(int j=0;j<n;j++){
            cout << vec[i][j] << " ";
          }
        cout<<endl;
    }
    cout<<"end of the matrix "<<endl;
}

/**
 * matrix =
[[5,1,9,11],[2,4,8,10],[13,3,6,7],[15,14,12,16]]
Output
[[15,13,2,5],[14,4,8,1],[12,3,6,9],[16,7,10,11]]
Expected
[[15,13,2,5],[14,3,4,1],[12,6,8,9],[16,7,10,11]]
// failed for above input matrix
 */
int main(int argc, char *argv[])
{
 // vector<vector<int>>matrix = {{1, 2, 3},
 //                             {4, 5, 6},
 //                             {7, 8, 9}};
    vector<vector<int>> matrix = {
        {5,1,9,11},
        {2,4,8,10},
        {13,3,6,7},

        {15,14,12,16}
    };
 // we need to rotate matrix
 // the matrix will be square matrix
 // printMatrix(vec);
 /**
  * the idea is
  * 1. diagnal swap across the right diagonal
  * 2. reverse the right most column
  * 3. swap top and bottom row until j-2 columns
  * 4. diagonal swap across the left diagonal
  * 5. reverse the top row from j=1 to n-2 [index]
  *
  *
  * second idea is
  * 1. swap top and bottom row
  * 2. swap bottom row and left most elements
  * 3. swap top row and right most elements
  * 4. now leftmost and right most columns are correctly placed
  * 5. reverse top and bottom row from j=1 to j=n-2 [index]
  */
 // 2.1
 int n=matrix.size();
 // printMatrix(matrix);
 // cout<<"==============="<<endl;
 for(int i=0;i<=n-2;i++){
     for(int j=i;j<n-i;j++){
         swap(matrix[i][j],matrix[n-1-i][j]);
     }
     // cout<<"swapping top and bottom row"<<endl;
     // printMatrix(matrix);
     for (int k = i; k < n - i; k++) {
         swap(matrix[n-1-i][k],matrix[k][n-1-i]);
     }
     // cout<<"after swapping bottom row and right row "<<endl;
     // printMatrix(matrix);

     for(int l=i;l<n-i-1;l++){
         swap(matrix[i][l],matrix[l][i]);
     }
     // cout<<"after swapping top row and left column "<<endl;
     // printMatrix(matrix);

     int low=i+1;
     int high=n-2-i;
     while (low<high) {
         swap(matrix[i][low],matrix[i][high]);
         swap(matrix[n-1-i][low],matrix[n-1-i][high]);
         low++;
         high--;
     }
     // cout<<"============="<<endl;

 }
 // cout << "final" << endl;
 // printMatrix(matrix) ;


    return 0;
}
