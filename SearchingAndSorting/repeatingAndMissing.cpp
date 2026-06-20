#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(int argc, char *argv[])
{
/**
 * given an unsorted array
 * containing elements in range 1..n
 * it is known that one number is missing and
 * and another occurs twice you have to find
 * these two numbers
 */
    int arr[]{4,3,6,2,1,1};
    int n=sizeof(arr)/sizeof(arr[0]);

    // simple idea is to sort the array
    // and do one traversal to find out the numbers

    // we can find the sum of elements
    // how do i find the one that is repeating
    // you can find using the count array
    vector<int>count(n,0);
    int arr_total{};
    int repeating_element=-1;
    for(int i=0;i<n;i++){
        if (count[arr[i]-1]==0) {
            count[arr[i]-1]++;
            arr_total+=arr[i];
        }
      }
    int total=(n*(n+1))/2;
    int missing_element=total-arr_total;

    return 0;
}
