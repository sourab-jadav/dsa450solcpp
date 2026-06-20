#include <cmath>
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

    // first finding the repeated element
    int repeating{};
    for (int i = 0; i < n; i++) {
        int val=abs(arr[i]);
        if (arr[val-1]>0) {
            arr[val-1]=-arr[val-1];
        } else {
            repeating=val;
        }
    }
    int remaining{};
    // now if arr[i] is +ve means i+1th element is not visited
    // if an element is not visited then it must not be present in the array
    // since we have already visited all the array elements
    for (int i = 0; i < n; i++) {
        if (arr[i]>0) {
            remaining=i+1;
        }
    }
    return 0;
}
