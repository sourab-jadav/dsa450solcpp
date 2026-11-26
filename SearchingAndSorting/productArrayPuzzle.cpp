// https://www.geeksforgeeks.org/problems/product-array-puzzle4525/1


// Given an array, arr[], construct a product array, res[] where each
// element in res[i] is the product of all elements in arr[] except
// arr[i]. Return this resultant array, res[].  Note: Each element is
// res[] lies inside the 32-bit integer range.

// Input: arr[] = [10, 3, 5, 6, 2]
// Output: [180, 600, 360, 300, 900]
// Explanation: For i=0, res[i] = 3 * 5 * 6 * 2 is 180.
// For i = 1, res[i] = 10 * 5 * 6 * 2 is 600.
// For i = 2, res[i] = 10 * 3 * 6 * 2 is 360.
// For i = 3, res[i] = 10 * 3 * 5 * 2 is 300.
// For i = 4, res[i] = 10 * 3 * 5 * 6 is 900.


#include <bits/stdc++.h>
#include <ratio>
#include <vector>

using namespace std;

// tip: whenever the question says product consider the case 0 especially
class Solution {
  public:
    vector<int> productExceptSelf(vector<int>& arr) {
        // one conclusion is that if there are two zeros then it is definately all zeros
        int n=arr.size();
        int count=0;
        int total=1;
        for(int i=0;i<n;i++){
            if (arr[i]==0) {
                count++;
                continue;
            }
            total*=arr[i];
        }
        if (count>=2) {
            return vector<int>(arr.size(),0);
        }
        vector<int>result;

        // control comes here if there is only one zero
        for(int i=0;i<n;i++){
            if (arr[i]==0) {
                result.push_back(total);
            }else{
                if (count>=1) {
                    result.push_back(0);
                }else{
                    result.push_back(total/arr[i]);
                }
            }
        }
        return result;


    }
};


int main(int argc, char *argv[])
{
    vector<int>arr{12,0};
    Solution s;
    vector<int>result=s.productExceptSelf(arr);

    for (auto x : result) {
        cout << x << " ";
    }



    return 0;
}
