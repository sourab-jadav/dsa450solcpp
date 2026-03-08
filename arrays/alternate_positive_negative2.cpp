#include <iostream>
#include <type_traits>
#include <vector>

using namespace std;
void print(std::vector<int> arr) {
  int n = arr.size();
  cout<<endl;
  for (auto it = arr.begin(); it != arr.end(); ++it) {
      cout << *it << " ";
  }
  cout <<endl;
}

int main(int argc, char *argv[])
{
    //  std::vector<int> arr = {-2, 3, 4, -1};
    std::vector<int> arr={-5, 3, 4, 5, -6, -2, 8, 9, -1, -4};
  /**
   * rearrange array in alternative positive and negative values
   * o(1) extra space
   * makesure every positive number is followed by negative number
   * means first positive number should come and then neg number
   * (+ - + - +)
   */
  // logic ////////////////////////////////////////////////////////////////////
    /**
     * count positives and negatives
     * move all negatives to the end
     *
     * swap odd places with negative numbers which are present towards end
     */
    cout << "initital array"
         << "\n";
    print(arr);

  int n = arr.size();
  int i = 0, j = n - 1;
  while (i<j) {
      while (i<n && arr[i]>=0) {
          i++;
      }
      while (j >= 0 && arr[j] < 0) {
          j--;
      }
      if (i<j) {
          swap(arr[i],arr[j]);
        }
  }
cout << "after seperation " << "\n";

  print(arr)  ;
  // we have the elements divided
  // cout << "value of i is " << i << " ";
  // cout<<endl;
  // cout << "value of j is " << j << " ";

  // one corner case could be
  // all the elements could be positive or
  // all the elements could be negative let's cover this case

  if (i == 0 || i == n - 1) {
      return 0;
  }
  int k = 0;
  while (k<n && i<n) {
      swap(arr[k], arr[i]);
      i++;
      k+=2;
  }
cout << "final result" << "\n";

  print(arr);

    return 0;
}
