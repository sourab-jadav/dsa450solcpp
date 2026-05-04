#include <iostream>
#include <vector>
#include <climits>

using namespace std;


/**
 * given an array
 * each value in array represents word size
 * given a k value which is max line length
 *
 * if you include more than one word in a line
 * say two words: then k-w1size-w2size-1space(b/w w1 & s2)
 * will be the reduntant amount of spaces
 * and it's result will be considered for total_cost calculation
 */
int method1(vector<int>&vec,int n,int k,int i,vector<int>&memo){

    int result=INT_MAX;
    int consider=0;
    int cost{};
    if (memo[i]!=-1) {
        return memo[i];
    }

  for (int j = i; j < n; j++) {

      if (consider==0) {
          consider+=vec[j];
      } else {
          consider+=vec[j]+1;
      }

      if (consider<=k) {
          cost=(k-consider);
          cost=cost*cost;
          result=min(result,cost+method1(vec, n, k, j+1,memo));
      }else{
          break;
      }
      if (j==n-1) {
          return 0;
      }
    }
  return memo[i]=result;
}

int main(int argc, char *argv[])
{
    vector<int>vec{3,2,2,5};
    int n=vec.size();
    int k=6;
    vector<int>memo(n,-1);
    cout << method1(vec, n, k, 0,memo) << "\n";

    // objective is to minimize the total cost

    return 0;
}
