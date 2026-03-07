#include <iostream>

using namespace std;
void printArray(int arr[], int n) {
    cout << endl;
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}
// one idea for counting inversions is
// starting from right
// we need a hashmap
// countinversion for element at n-1 is 0
// mp[arr[n-1]]=0;
// for n-2
// traverse through the map elements see any value is greater than
// current value
//   if it is greater then get it's result and add one to it
int countInversions(int arr[], int low, int high) {
    if (low<high) {
        int mid = (low + high) / 2;
        int result{};
        result += countInversions(arr, low, mid);
        result += countInversions(arr, mid+1, high);
        int leftsize = mid - low + 1;
        int rightsize = high - mid;
        int left[leftsize];
        int right[rightsize];
        for (int k = low; k <= mid; k++) {
            left[k - low] = arr[k];
        }
        for (int l = mid + 1; l <= high; l++) {
            right[l - (mid + 1)] = arr[l];
        }
        int i = 0;
        int j = 0;
        int k=low;
        while (i<leftsize && j<rightsize) {
            if (left[i]>right[j]) {
              arr[k++] = right[j++];
              result+=leftsize-i;
            } else if (left[i] < right[j]) {
                arr[k++] = left[i++];
            } else {
                arr[k++] = left[i++];
                j++;
            }
        }
        while (i < leftsize) {
            arr[k++]=left[i++];
        }
        while (j<rightsize) {
            arr[k++] = right[j++];
        }
        return result;
    }    
        return 0;
}
int main() {

    int arr[]{2, 4, 1, 3, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    int result = countInversions(arr, 0, n - 1);
    cout<<result;

    return 0;
}
