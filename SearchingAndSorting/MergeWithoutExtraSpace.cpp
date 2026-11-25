#include <algorithm>
#include <bits/stdc++.h>
#include <iostream>
#include <shared_mutex>
#include <vector>


using namespace std;

// Given two sorted arrays a[] and b[] of size n and m respectively,
// the task is to merge them in sorted order without using any extra
// space. Modify a[] so that it contains the first n elements and
// modify b[] so that it contains the last m elements.

// Input: a[] = [2, 4, 7, 10], b[] = [2, 3]
// Output: a[] = [2, 2, 3, 4], b[] = [7, 10]
// Explanation: After merging the two non-decreasing arrays, we get, [2, 2, 3, 4, 7, 10]

class Solution {
  public:
    // Compare the largest element of a (a[n1 - 1]) with the smallest
    // element of b (b[0]). Move backwards through a and forwards
    // through b while a[left] > b[right], swapping them, and then
    // sort both a and b.
    void printArrays(vector<int> &a, vector<int> &b) {
       // cout << "after rearring a values are "
       //     << "\n";
      for (auto x : a) {
        cout << x << " ";
      }
      cout << endl;
      for (auto x : b) {
        cout << x << " ";
      }
      cout << endl;
    }
    void mergeArrays(vector<int>&a ,vector<int>&b){
        int n1 = static_cast<int>(a.size());
    int n2 = static_cast<int>(b.size());
    if (n1 == 0 || n2 == 0) return;

    int left = n1 - 1;
    int right = 0;

    while (left >= 0 && right < n2) {
        if (a[left] > b[right]) {
            swap(a[left], b[right]);
            left--;
            right++;
        } else {
            break;
        }
    }

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    }

};
void printArrays(vector<int>vec1,vector<int>vec2){
    int n1=vec1.size();
    for(int i=0;i<n1;i++){
        cout << vec1[i] << " ";
    }
    cout<<endl;
    int n2=vec2.size();
    for(int i=0;i<n2;i++){
        cout << vec2[i] << " ";

    }
}

int main(int argc, char *argv[])
{
    // vector<int>a{2,4,7,10};


    vector<int>a{2, 2, 3, 5, 6, 7};
    vector<int>b    {0, 0, 0, 1, 2, 3, 4, 7, 7, 8, 9};


    Solution s;
    cout << "bfore" << "\n";
    printArrays(a, b);

    s.mergeArrays(a, b);
    cout << "after" << "\n";

    printArrays(a, b);
    return 0;
}
