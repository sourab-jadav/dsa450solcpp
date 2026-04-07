#include <iostream>
#include <vector>
using namespace std;

/**
 * row with max 1's
 * [[1,1,1,1,1,1,1,1,1],[0,0,0,0,0,1,1,1,1],[0,0,1,1,1,1,1,1,1],[0,0,0,0,0,0,1,1,1],[0,0,0,1,1,1,1,1,1],[0,0,0,0,0,0,0,0,1],[0,1,1,1,1,1,1,1,1],[0,0,0,0,0,0,0,0,0],[0,0,0,0,0,0,0,0,0],[0,0,0,1,1,1,1,1,1]...
 */
 int rowWithMax1s(vector<vector<int>> &arr) {
     int m=arr.size();
     int n = arr[0].size();
     /**
      * one idea would be to perform binary search of value
      * =1 columnwise
      */
     // this solution resulted in time limit exceeded
     int j=0;
     int result=-1;
     while (j<n) {
       for (int i = 0; i < m; i++) {
           if (arr[i][j]==1) {
               return i;
           }
         }
     }
     return result;

 }
int main(int argc, char *argv[])
{
    vector<vector<int>>mat={{0,1,1,1}, {0,0,1,1}, {1,1,1,1}, {0,0,0,0}};
    cout << rowWithMax1s(mat) << "\n";


    return 0;
}
