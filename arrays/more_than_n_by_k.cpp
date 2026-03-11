#include <cstring>
#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

/**
 * 1 method is to use hashing (easier to think)
 *
 */
void usingHashMap(vector<int> &arr) {
  unordered_map<int, int> mp;
  int n = arr.size();
  int k = 4;

  int x = n / k;

  for (int i = 0; i < n; ++i) {
    mp[arr[i]]++;
  }

  for (auto i : mp) {
    if (i.second > x) {
      cout << i.first << " ";
    }
  }
  cout << endl;
}

int main(int argc, char *argv[]) {
  vector<int> arr{3, 4, 2, 2, 1, 2, 3, 3};

  // method2 ////////////////////////////////////////////////////////////////
  // using moore's voting algorithm

  /**
   * when you read more than n/k times
   *     think about it?
   *     it is possible for k elements to appearing n/k times
   *     i.e k*(n/k) = n (fills the entire array)
   *
   *     if x*(n/k) where x=k+1
   *     (k+1)*(n/k)
   *     n+1  (exceeds the size of array)
   *     which cannot be possible
   *
   *     hence x has to be <=k-1
   */
  int k = 4;
  int n = arr.size();
  int x = n / k;
  int result[k - 1];
  memset(result, 0, sizeof(result)); // defined in <cstring>

  // for each element we also need to keep track of it's value and count
  // let's create a struct which stores
  // element value and
  // element count
  //
  //

  struct eleCount {
    int e;
    int c;
  };
  vector<eleCount> temp(k - 1);
  for (int i = 0; i < n; i++) {
    // for each element traverse through all the possible elements
    int j;
    for (j = 0; j < k - 1; j++) {
      if (temp[i].e == arr[i]) {
        temp[i].c += 1;
        break;
      }
    }
    // the element is not found
    if (j == k - 1) {
      int l;
      // see if all the positions are already full
      for (l = 0; l < k - 1; l++) {
        if (temp[l].c == 0) {
          temp[l].e = arr[i];
          temp[l].c = 1;
          break;
        }
      }
      if (l==k-1) {
        for (l = 0; l < k - 1; l++) {
            temp[l].c-=1;
          }
      }
    }
  }
  // we need to verify the count of values in temp is actually
  // greater than n/k

  for (int i = 0; i < k - 1; i++) { // for each value in temp
      int ac=0;
      for(int j=0;j<n;j++){     // check how many values exist in arr
          if (arr[j]==temp[i].e) {
              ac++;
          }
      }
      if (ac>n/k) {
          std::cout << temp[i].e << " ";
      }
  }
  return 0;
}
