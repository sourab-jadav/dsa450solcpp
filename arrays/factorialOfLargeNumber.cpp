#include <iostream>
#include <cstring>


using namespace std;
/**
 * finding factorial of a large number
 * logic:
 * x1  [1,0,0,0,]
 * x2  [2,0,0,0...]
 * x3  [6,0,0,..]
 * x4  [4,2,0,0..]
 *
 *
 */
int main(int argc, char *argv[])
{
  int factorial = 4;
  int arr[99]; // this makes all 0 to 98 indices
               // initialized to value 0
  memset(arr, -1, sizeof(arr));
  arr[0] = 1;
  int result_size=1;
  for (int i = 2; i <= factorial; ++i) {
    int j = 0;
    int carry = 0;
    while (arr[j]!=-1) {
      int val = i * arr[j]+carry;
      carry = val / 10;
      arr[j] = val % 10;
      j++;
    }
    while (carry) {
      arr[j] = carry % 10;
      carry = carry / 10;
      j++;
    }
    result_size=j;
  }
  for (int i=result_size-1; i>=0; --i) {
      cout<<arr[i]<<" ";
  }


  cout<<endl;
    return 0;
}
