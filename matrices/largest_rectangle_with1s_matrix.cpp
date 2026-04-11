#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;


// dp solution
/**
 * bit difficult to think
 * we need width and height to create an area
 * as we traverse rowwise from left to right
 * we will store width possible to that i,j from the left(j=0)
 *
 * for every i,j we compute the height
 * we go upwards from that cell and see which cell has the min width
 * area is (min_width*height)
 */
int dp(vector<vector<int>>mat){
    int m=mat.size();
    int n=mat[0].size();
    vector<vector<int>>memo(m,vector<int>(n,0));
    int ans=0;

    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
          if (mat[i][j]==0) {
              continue;
          }
          /**
           * this below line of using previous width value is important
           */
          memo[i][j]=(j==0)?1:memo[i][j-1]+1;
          // we have set width of a rectangle
          //
          int width=memo[i][j];
          for (int k = i; k >= 0; k--) {
              width=min(width,memo[k][j]);
              int area = width * (i-k+1);
              ans=max(ans,area);
          }
      }
    }
    return ans;
}

/**
 * how do we select the base
 *   the tricky part here is
 *   traverse through each row considering it as a base create a heights
 *   array
 *   now if a cell in base has value 0 then then that column cannot be
 *   considered to form a rectangle
 *
 *   after creating the heights array for each row call the
 *   largest rectangle in histogram passing this heights array
 */

int main(int argc, char *argv[])
{
    vector<vector<int>>vec= {{0, 1, 1, 0},
                             {1, 1, 1, 1},
                             {1, 1, 1, 1},
                             {1, 1, 0, 0}};

    int m=vec.size();
    int n=vec[0].size();



    return 0;
}
