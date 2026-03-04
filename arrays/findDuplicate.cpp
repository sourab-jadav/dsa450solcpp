#include <iostream>
using namespace std;
/**
   given n+1 integers
   where each integer is within a range from [1,n]
   n is the size of the array
   at a given index the array may or maynot have the value in the range



   you need to find the repeating number

   using slow and fast pointer:
   since fast moves twice as slow
   once fast enters the cycle it will reach slow
   skipping the no. of steps that have taken to reach the cycle entry point
   let's say the steps are x

   hence fast will catch slow at a point where after x steps there is
   a cycle entry point.
 */
int main() {
int nums[] = {1, 3, 4, 2, 2};
  //
  //
  // find the repeating number
  //    int nums[] ={1,3,6,5,3,4};
  
  int slow = 0;
  int fast = 0;
  do {
    slow = nums[slow];
    fast = nums[nums[fast]];
    cout<<"slow is "<<slow<<" fast is "<<fast<<endl;
  } while (slow != fast);

  slow = 0;
  while (slow != fast) {
    slow = nums[slow];
    fast = nums[fast];
    cout << "after " << endl;
    cout<<"slow is "<<slow<<" fast is "<<fast<<endl;    
  }  
  cout << "the repeating element is " << slow << endl;

  
}
