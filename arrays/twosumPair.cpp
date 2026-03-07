#include <iostream>
#include <utility>
#include <vector>
#include <set>
#include <unordered_map>

using namespace std;

int main(){
  cout << "hello world" << endl;
  vector<int> arr = {-1, 0, 1, 2, -1, -4};
  // find all unique pairs so that their sum is 0

  // the idea here is to use unordered map

  vector<vector<int>> result;
  unordered_map<int, vector<int>> mp;
  int n=arr.size();
  for (int i = 0; i < n; i++) {

      if(mp.find(-arr[i])!=mp.end())    {
          for(int idx:mp[-arr[i]]){
              result.push_back({idx,i});
            }
      }
      mp[arr[i]].push_back(i);
  }
  for (int i = 0; i < result.size(); i++) {
      for (int j = 0; j < result[i].size(); j++) {
          cout<<result[i][j]<<" ";
      }
      cout<<endl;      
  }  
  
  
  return 0;  
}
