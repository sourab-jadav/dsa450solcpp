#include <iostream>
#include <stdio.h>
#include <vector>
using namespace std;

int main() {

  vector<int> nums1 = {1, 2, 3, 0, 0, 0};
  int m = 3;
  vector<int> nums2 = {2, 5, 6};
  int n = 3;

  // we want to merge it without extra space
  // we need to put the values in here in num1

  // thought1: maintain 2 pointers
  // 1 pointing to the nums1
  // 2 pointing to the nums2
  // while 2 not reaches the end
  //   if value at 2 less than or equal to value at 1
  //     right shift values by 1 place and put value at 2 at 1
  //     move pointer 2 forward
  //   else move pointer 1 forward 
  //

  // the thought was right but has to be executed from right to left

  int i = m - 1;
  int j = n - 1;
  int k = m + n - 1;

  while (j>=0) {
      // if nums2[j] is greater than nums1[i]
      if (i >= 0 && nums1[i] > nums2[j]) {
          nums1[k--] = nums1[i--];
      } else {
          nums1[k--]=nums2[j--];
      }
  }
}
