#include <iostream>
#include <type_traits>
#include <vector>

using namespace std;
/**
 * the task is to partition the given range such that the array is
 * divided into 3 parts
 * 1. all elements smaller than element a come first
 * 2. all element in range a and b come next
 * 3. all element greater than b appear at the end
 */
/**
 * using one loop
 */
void solution(vector<int> vec, int a, int b) {
  int n = vec.size();
  int start =0;
  int end=n-1;
  for(int i=0;i<n;){
      if (vec[i]<a) {
          if (i==start) {
              i++;
              start++;
          }
          else {
              swap(vec[start++],vec[i++]);
          }
      }
      // if the current element is greater than range
      // put it on next available greater position
      else if (vec[i]>b) {
          swap( vec[i],vec[end--]);
      }else {
          i++;
      }
    }
}

/**
 * one solution is
 * make two unnested loops
 * first loop swaps with all elements <a
 * second loop swaps all the elements in rang a and b
 * this two loops auto adjusts the third part
 * this solution passed all the test cases
 */
int main(int argc, char *argv[])
{

  // vector<int> arr = {1, 4, 3, 6, 2, 1};
  // int a = 1, b = 3  ;
  vector<int> arr = {1, 2, 3, 3, 4};

  int a=1,b=2;
  int n= arr.size();
  cout << n << "\n";

  // maybe we have to maintain 3 pointers
  // k tracks elements less than a
  // l tracks elements in range a and b
  // m tracks elements greater than b

  int i=0;
  for (int j = 0; j < n; j++) {
      if (arr[j]<a) {
          swap(arr[j],arr[i++]);
      }
  }
  for (int k = i; k < n; k++) {
      if (arr[k]>=a && arr[k]<=b) {
          swap(arr[k],arr[i++]);
      }
  }
  for (int i = 0; i < n; i++) {
      cout << arr[i] << " ";
  }
  cout<<endl;

    return 0;
}
