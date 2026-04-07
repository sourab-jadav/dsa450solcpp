#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
/**
 * EASY q:given a matrix
 * sort the matrix overall
 *
 */
 vector<vector<int>> sortedMatrix(int N, vector<vector<int>> Mat) {
        // code here
        int n=N*N;
        vector<int> result;
        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++){
                result.push_back(Mat[i][j]);
            }
        }
        sort(result.begin(),result.end());
        vector<vector<int>> fresult;
        int i=0;
        while(i<n){
            vector<int> temp;
            for(int k=1;k<=N;k++){
                temp.push_back(result[i]);
                i++;
            }
            fresult.push_back(temp);
        }
        return fresult;
    }

int main(int argc, char *argv[])
{
  vector<vector<int>> mapt = {
    {10, 20, 30, 40},
    {15,25,35,45},
    {27,29,37,48} ,
    {32,33,39,50}
  };
  int N=mapt.size();
  sortedMatrix(N, mapt);

    return 0;
}
