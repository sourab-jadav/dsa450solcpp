
#include <algorithm>
#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;
void printarray(vector<int> &vec) {
    for (auto x : vec) {
        cout << x << " ";
    }
    cout << endl;
}

int methodOneUsingSorting(vector<int> &arr) {
    int n = arr.size();
    /**
     * longest consecutive subsequence
     * one way to solve it is:
     * sort the array
     * now find biggest subarray where arr[i]=arr[i-1];
     *
     */
    sort(arr.begin(), arr.end());
    printarray(arr);
    int result = 1;
    int subresult = 1;
    for (int i = 1; i < n; ++i) {
        if (arr[i]==arr[i-1]) {
            continue;           // handling repitations
        }
        if (arr[i] == arr[i - 1] + 1) {
            subresult++;
            result = max(result, subresult);
        } else {
            subresult = 1;
        }
    }
    cout << result << "\n";

    return result;
}

int main(int argc, char *argv[]) {
    // vector<int> arr{2, 6, 1, 9, 4, 5, 3}; //passed
    // vector<int> arr{1, 9, 3, 10, 4, 20, 2}; //passed
    vector<int> arr{15, 13, 12, 14, 11, 10, 9}; //passed

    // method 2 : hashing /////////////////////////////////////////////////////

    /**
     * 1 idea is to put everything into the hashset
     * traverse arr elements one by one
     *     look for element with value arr[i]-1 until it becomes 0
     *         if you found element in set do result++
     */

    int n=arr.size();
    unordered_set<int>s(arr.begin(),arr.end());
    int result=1;
    for (int i=0; i<n; ++i) {
        int subresult=1;
        int temp=arr[i];
        while (--temp>=0 && s.find(temp)!=s.end()) {
            subresult++;
        }
        temp=arr[i];
        while (s.find(++temp)!=s.end()) {
            subresult++;
        }
        if (subresult>=n/2) {
            result = subresult;
            break;
        }else {
            result=max(result,subresult);
        }
    }
    sort(arr.begin(), arr.end());
    printarray(arr);
    cout << "result is "<<result << "\n";


    return 0;
}
