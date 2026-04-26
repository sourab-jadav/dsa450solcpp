#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;
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
int main(int argc, char *argv[])
{
  // vector<vector<int>> mat {
  //     {10,20,30,40},
  //     {15,25,35,45},
  //     {24,29,37,48},
  //     {32,33,39,50}
  // };

  // vector<vector<int>>mat {{16, 28, 60, 64},
  //                         {22, 41, 63, 91},
  //                         {27, 50, 87, 93},
  //                         {36, 78, 87, 94}};

  vector<vector<int>>mat{{10, 20, 30, 40},
                         {15, 25, 35, 45},
                          {24, 29, 37, 48},
                          {32, 33, 39, 50}};
  int n=mat.size();
  // say we want 7th element
  // if you observe the diagonal
  // top left most diagonal element will be the smallest
  // and bottom right most diagonal element will be the largest

  // say we want 7th smallest then
  // 1*1 will have 1 element smallest to largest
  // 2*2 will have 4 elements smallest to largest
  // 3*3 will have 9 elements smallest to largest

  // since we want 7th
  // it will be between 2*2 and 3*3
  // 3*3 th element is the 9th element
  // on the 9th element check along it's top and left
  // see which is largest and count it accordingly
  int rc=7;
 int i=1;
  while (i*i<rc) {
      i++;
  }

  int result{};
  int count=i*i;
  if (count==rc) {
      cout << mat[i][i] << "\n";
  }
  i=i-1;
  int j1=i-1;
  int j2=i-1;
  while (j1>=0 && j2>=0) {
      if (mat[i][j1]>mat[j2][i]) {
          count--;
          if (count==rc) {
              result=mat[i][j1];
              break;
          }
          j1--;
      }else if (mat[j2][i]>mat[i][j1]) {
          count--;
          if (count==rc) {
              result=mat[j2][i];
              break;
          }
          j2--;
      }else {
          count-=2;
          if (count<=rc) {
              result=mat[i][j1];
              break;
          }
          j1--;
          j2--;
      }
  }
  return result;

}
