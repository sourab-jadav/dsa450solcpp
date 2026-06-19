#include <iostream>
using namespace std;

int searchInRotatedSortedArray(int nums[], int n,int target) {
    // the idea is to first find the low index
    // since the array shifts towards left
    // to find the actual low index
    // we start from the end and move until
    // the condition arr[i]<arr[i-1] matches
    int i=n-1;
    while (i>0 && nums[i]>nums[i-1]) {
        i--;
    }
    int low=i;
    int high=i+n-1;
    while (low<=high) {
        int mid=(low+high)/2;

        if (nums[mid%n]==target) {
            return mid%n;
        } else if (nums[mid%n] < target) {
            low=mid+1;
        } else {
            high=mid-1;
        }
    }
    return -1;
}
int main(int argc, char *argv[])
{
    int arr[]{4,5,6,7,0,1,2};
    int n=sizeof(arr)/sizeof(arr[0]);
    int target=0;
    cout<<searchInRotatedSortedArray(arr, n,target);
    return 0;
}
