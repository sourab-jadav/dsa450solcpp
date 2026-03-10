#include <algorithm>
#include <climits>
#include <iostream>

#include <vector>

using namespace std;


int main(int argc, char *argv[])
{

    // vector<int> arr{-2, 6, -3, -10, 0, 2}; //passed
    // vector<int> arr{-1, -3, -10, 0, 6}; //passed
    vector<int> arr{2, 3, 4} ;  // now it's passed
    /**
     * one thought is maintain two products
     * positive product
     * negative product
     *
     * if we come across 0
     * then we reset the max pos and max neg to 1
     *
     */
    if (arr.size() > 0) {
    int max_pos = arr[0];
    int max_neg = arr[0];
    int result = arr[0];
    for (int i=1; i<arr.size(); ++i) {
        if (arr[i]==0) {
            max_pos=1;
            max_neg=1;
        }else{
            max_pos=max(arr[i],max_pos*arr[i]);
            // we have max pos and max negative
            //
            int subresult = max(max_pos, max_neg * arr[i]);
            result=max(result,subresult);
            max_neg=min(arr[i],max_neg*arr[i]);
            }
    }
    cout << result << "\n";

    }








    return 0;
}
