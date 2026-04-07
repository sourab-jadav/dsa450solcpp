#include <iostream>
#include <vector>
using namespace std;

/**
 * row with max 1's
 * a matrix contains only 0's and 1's sorted row wise
 * you need to find indice of first row that contains
 * max number of 1's
 */
 int rowWithMax1s(vector<vector<int>> &arr) {
     int m=arr.size();
     int n = arr[0].size();
     int result=-1;
     int low=0;
     int high=n-1;
     /**
      * the idea is to do binary search
      * column wise
      * for a specific column traverse from left to right
      * looking for thee value 1
      * if the value is found add that row index to result
      * and move left side to solve further
      */
     while (low<=high) {
         int mid=(low+high)/2;
         bool flag=false;
       for (int i = 0; i < m; i++) {
           if (arr[i][mid]==1) {
               flag=true;
               result=i;
               break;
           }
         }
         if(flag){
             high=mid-1;
         }else{
             low=mid+1;
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
