#include <algorithm>
#include <iostream>
#include <vector>
#include <climits>



using namespace std;
/**
 * Given an array arr[] of n integers where arr[i] represents the
 * number of chocolates in ith packet. Each packet can have a variable
 * number of chocolates. There are m students, the task is to
 * distribute chocolate packets such that:

    Each student gets exactly one packet.  The difference between the
    maximum and minimum number of chocolates in the packets given to
    the students is minimized.
 */
int main(int argc, char *argv[])
{
    int arr[] = {7, 3, 2, 4, 9, 12, 56};
    int n = sizeof(arr) / sizeof(arr[0]);
    sort(arr,arr+n);


    int m = 3;
    // one way is to sort the array and pick first m elements
    // 1 7 13 14 15 16 and m =3 the sorting will not working here
    // after sorting we can do sliding window here

    /**
     * idea of n-m
     * it's zero based indexing or something else
     * the length remains fixed if you remove m items
     * from total length will get all windows except the last window
     */
    int result = INT_MAX;
    for (int i = 0; i <= n - m; i++) {
        result=min(result,arr[i+m-1]-arr[i]);
    }
    cout<<endl;

    cout<<result<<endl;


    return 0;
}
