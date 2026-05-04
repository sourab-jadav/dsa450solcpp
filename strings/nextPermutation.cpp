#include <iostream>
#include <iterator>
#include <vector>

using namespace std;


/**
 * we need to find the next permutation means
 * next greater element
 * starting from right most element
 * look for the element which is smaller than the current element
 */
void reverse(vector<int> &vec, int low, int high) {
    while (low<high) {
        swap(vec[low],vec[high]);
        low++;
        high--;
    }
}
void printvector(vector<int> &vec) {
    for (auto val : vec) {
        cout << val << " ";
    }
    cout<<endl;
}
void nextGreater(vector<int> &arr) {
    int n = arr.size();
    // if all the elements are in ascending order
    // 1 2 3 4 5
    // 1 2 4 3 5
    // 5 2 4 3 1
    int i;
    for (i = n - 2; i >= 0; i--) {
      if (arr[i]<arr[i+1]) {
          break;
      }
    }
    if (i<0) {
        reverse(arr, 0, n-1);
        return;
    }
    int j;
    for (j = n - 1; j >= 0; j--) {
        if (arr[j]>arr[i]) {
            break;
        }
    }
    swap(arr[i],arr[j]);
    reverse(arr, i+1, n-1);
}

int main(int argc, char *argv[])
{
    vector<int>vec{2,4,1,7,5,0};
    printvector(vec);
    // we need to find the next permutation
    nextGreater(vec);
    printvector(vec);
    return 0;
}
