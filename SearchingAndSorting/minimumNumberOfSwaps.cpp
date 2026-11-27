

#include <algorithm>
#include <bits/stdc++.h>
#include <unordered_map>
#include <vector>

using namespace std;

// Given an array arr[] of distinct elements. Find the minimum number
// of swaps required to sort the array in strictly increasing order.

// Input: arr[] = [2, 8, 5, 4]
// Output: 1
// Explanation: Swap 8 with 4 to get the sorted array.

// [[id:8e2b2fe7-e51a-49a6-b78d-40b93f6f73b4]]
class Solution {
  public:

    // TC: o(n)+o(nlogn)+o(n)+o(n)=o(nlogn)
    // SC: temp+mp+mp_to_index => o(n)+o(n)+o(n)=o(n)

    // the golden rule: cycle of size k always takes k-1 swaps
    int minSwaps(vector<int>& arr) {

        // o(n) space and o(n) for copying n elements
        vector<int>temp=arr;

        // o(nlogn) time uses introsort
        sort(temp.begin(),temp.end());

        unordered_map<int, bool>mp;
        unordered_map<int, int>mp_to_index;
        int n=arr.size();

        // o(n) average case o(n^2) worst case
        for(int i=0;i<n;i++){
            if (temp[i]==arr[i]) {
                continue;
            }else{
                // o(1) average case o(n) worst case
                mp_to_index[temp[i]]=i;
            }
        }


        int result{};

        // o(n) total for both loops(inner+outer)
        for(int i=0;i<n;i++){
            if (mp[i] || arr[i] == temp[i]) {
                continue;
            }

            // we need to get the index of arr[i]
            int index=mp_to_index[arr[i]];
            mp[index]=1;
            int count{};
            while (index!=i) {
                index=mp_to_index[arr[index]];
                mp[index]=1;
                count+=1;
            }
            result+=count;
        }
        return result;
    }
};



int main(int argc, char *argv[])
{
    Solution s;
    vector<int>v{10, 19, 6, 3, 5};
    cout<<s.minSwaps(v)<<endl;

    return 0;
}
