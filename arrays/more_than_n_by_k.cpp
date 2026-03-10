#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

int main(int argc, char *argv[])
{
  vector<int> arr{3, 4, 2, 2, 1, 2, 3, 3};
  /**
   * 1 method is to use hashing (easier to think)
   *
   */
  unordered_map<int, int>mp;
  int n = arr.size();
  int k = 4;

  int x = n / k;

  for (int i=0; i<n; ++i) {
      mp[arr[i]]++;
 }

  for (auto i : mp) {
      if (i.second>x) {
          cout << i.first << " ";

    }
 }
  cout<<endl;

    return 0;
}
