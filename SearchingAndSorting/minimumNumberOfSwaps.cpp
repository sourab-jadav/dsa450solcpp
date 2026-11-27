

#include <algorithm>            // has sort
#include <unordered_map>
#include <utility>              // has pair<>
#include <iostream>
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
        int n=arr.size();
        vector<pair<int, int>>vp;

        for(int i=0;i<n;i++){
            vp.push_back({arr[i],i});
        }

        // o(nlogn) time uses introsort
        sort(vp.begin(),vp.end(),[](auto p1,auto p2){
            return p1.first<p2.first;
        });

        vector<bool>visited(n,false);

        int result{};
        // o(n) total for both loops(inner+outer)
        for(int i=0;i<n;i++){
            if (visited[vp[i].second] || arr[i] == vp[i].first) {
                continue;
            }

            // we need to get the index of arr[i]
            int index=vp[i].second;
            visited[index]=true;
            int count{};
            while (index!=i) {
                index=vp[index].second;
                visited[index]=true;
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
