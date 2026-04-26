#include <algorithm>
#include <iostream>
#include <utility>
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

  // vector<vector<int>>mat{{10, 20, 30, 40},
  //                        {15, 25, 35, 45},
  //                         {24, 29, 37, 48},
  //                         {32, 33, 39, 50}};
    vector<vector<int>>mat
        {
            {
                8,12
            },
            {
                10,18
            }
        };

  int n=mat.size();
  // another idea is
  // we have the most smallest element for sure
  vector<pair<int, int>>indices;
  indices.push_back(make_pair(0, 0));
  vector<vector<bool>>visited(n,vector<bool>(n,false));
  visited[0][0]=true;
  int rq=4;
  while (indices.size()!=rq) {
      vector<pair<int, int>>temp;
      for (auto indice : indices) {
          int i=indice.first;
          int j=indice.second;
          if (i+1<n && visited[i+1][j]==false) {
              temp.push_back(make_pair(i+1, j));
          }
          if (j+1<n && visited[i][j+1]==false) {
              temp.push_back(make_pair(i, j+1));
          }
      }
      pair<int, int>smallest
          {
              -1,-1
          };
      for (auto p : temp) {
          int i=p.first;
          int j=p.second;
          if (smallest.first==-1 || mat[i][j] < mat[smallest.first][smallest.second]) {
              smallest=
                  {
                      i,j
                  };
          }
      }
      visited[smallest.first][smallest.second]=true;
      indices.push_back(smallest);
      cout << "the smallest value is "<<smallest.first <<" "<<smallest.second << "\n";
  }

  int result=mat[indices.back().first][indices.back().second];
cout << result << "\n";


}
