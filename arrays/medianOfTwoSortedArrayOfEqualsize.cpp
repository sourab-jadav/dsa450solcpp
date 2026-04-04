#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

/**
 * median of an array
 */
int medianOfSimpleArray(int arr[], int n) {
    return (n-1)/2;
}

/**
 * median of two sorted array
 */
double medianOfTwoSortedArray(vector<int> nums1, vector<int> nums2) {
    int n1=nums1.size();
    int n2 = nums2.size();
    int n=n1+n2;

    int m1=0;
    int m2=0;
    int i=0;
    int j=0;

    for (int count=0; count<=(n/2); ++count) {
        m2=m1;

        // if both the arrays have remaining elements
        if (i!=n1 && j!=n2) {
            m1=(nums1[i]>nums2[j])?nums2[j++]:nums1[i++];
        }else if (i<n1) {
            m1=nums1[i++];
        }else {
            m1=nums2[j++];
        }
    }
    if ((n1+n2)%2==1) {
        return m1;
    }else {
        return (m1+m2)/2.0;
    }

}

int main(int argc, char *argv[])
{
    // cout << "hello world what are we doing here" << "\n";
    // int arr[]{90,100,78,89,67,23};
    // int n=sizeof(arr)/sizeof(arr[0]);
    // cout << n << "\n";

    // sort(arr,arr+n);

    // cout << medianOfSimpleArray(arr, n) << "\n";
    vector<int>vec1{-5, 3, 6, 12, 15};
    vector<int>vec2{-12, -10, -6, -3, 4, 10};
    vector<int>vec3(vec1.begin(),vec1.end());
    vec3.insert(vec3.end(),vec2.begin(),vec2.end());
    sort(vec3.begin(),vec3.end());
    cout << "vec1 size is "<<vec1.size() << "\n";
    cout << "vec2 size is "<<vec2.size() << "\n";

    cout << "vec3 size is "<<vec3.size() << "\n";

    for (auto val : vec1) {
        cout << val << " ";
    }
            cout<<endl;
    for (auto val : vec2) {
        cout << val << " ";
    }
            cout<<endl;
    for (auto val : vec3) {
        cout << val << " ";
    }
            cout<<endl;




    cout <<     medianOfTwoSortedArray(vec1, vec2);
    return 0;
}
