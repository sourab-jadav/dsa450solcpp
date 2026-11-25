#include <algorithm>
#include <bits/stdc++.h>
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
        // applying the insertion method of insertion sort

        int n1=a.size();
        int n2=b.size();

        // n1 > n2

        int i=0,j=0;
        while (i<n1 && j<n2) {
            // if the control goes out of this loap then one of the arrray is sorted

            // since filling starts from a skip the elements of a while a[i] < b[j]
            while (a[i]<=b[j]) {
                i++;
            }

            if (i<n1) {
                // we have to bring the value of b[j]
                int btemp = b[j];
                int k= j-1;
                while (k>=0) {
                    b[k+1]=b[k];
                    k--;
                }
                b[0]=a[n1-1];
                int l=i;
                // while (l+1<n1) {  // wrong logic
                //     a[l+1]=a[l];
                //     l++;
                // }
                for(int k=n1-2;k>=i;k--){
                    a[k+1]=a[k];
                }
                cout << "btemp value at i = "<<i<<" is "<<btemp << "\n";
                printArrays(a, b);

                a[i]=btemp;
                i++;
                j++;

            }else {
                cout << "at i "<<i<<" and j is "<<j<<" a[i] "<<a[i]<<" we are going into break" << "\n";

                break;
            }

        }
        if (j==n2) {
            return;
        }else {
            // apply insertion sort from i = 0 to i = j
            // now the question is how do you array
            // element from index 0 to index j to their correct positions
            sort(b.begin(),b.end());
        }
    }

};
void printArrays(vector<int>vec1,vector<int>vec2){
    int n1=vec1.size();
    for(int i=0;i<n1;i++){
        cout << vec1[i] << "\n";
    }
    cout<<endl;
    int n2=vec2.size();
    for(int i=0;i<n2;i++){
        cout << vec2[i] << "\n";

    }
}

int main(int argc, char *argv[])
{
    // vector<int>a{2,4,7,10};
    vector<int>a{1,5,9,10,15,20};
    vector<int>b{2,3,8,13};

    Solution s;
    s.mergeArrays(a, b);
    printArrays(a, b);
    return 0;
}
