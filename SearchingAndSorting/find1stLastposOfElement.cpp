#include <iostream>
using namespace std;

int main(int argc, char *argv[])
{
    int arr[]={1, 3, 5, 5, 5, 5, 67, 123, 125};
    int n = sizeof(arr) / sizeof(arr[0]);

    // to find the first and last occurence
    // we can make use of binary search in the array here

    // let's find the first occurence using the binary search
    int low =0;
    int high=n-1;
    int x=5;
    int lo=-1;
    while (low<=high) {
        int mid=(low+high)/2;
        if (arr[mid]==x) {
            lo=mid;
            high=mid-1;
        }else if (arr[mid]>x) {
            high=mid-1;
        } else {
            low=mid+1;
        }
    }
    if (lo==-1) {
        return -1;
    }
    low=lo;
    high=n-1;
    int ho=lo;
    while (low<=high) {
        int mid=(low+high)/2;
        if (arr[mid]==x) {
            ho=mid;
            low=mid+1;
        } else if (arr[mid] > x) {
            high=mid-1;
        } else {
            low=mid+1;
        }
    }
    cout << ho << "\n";

    return 0;
}
