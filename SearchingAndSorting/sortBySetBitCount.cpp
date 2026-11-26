// https://www.geeksforgeeks.org/problems/sort-by-set-bit-count1153/1


// Given an array arr[] of integers, sort the array (in descending
// order) according to count of set bits in binary representation of
// array elements.

// Note: For integers having same number of set bits in their binary
// representation, sort according to their position in the original
// array i.e., a stable sort.


// Input: arr[] = [5, 2, 3, 9, 4, 6, 7, 15, 32]
// Output: [15, 7, 5, 3, 9, 6, 2, 4, 32]
// Explanation: The integers in their binary representation are:
// 15 - 1111
// 7  - 0111
// 5  - 0101
// 3  - 0011
// 9  - 1001
// 6  - 0110
// 2  - 0010
// 4  - 0100
// 32 - 10000
// hence the non-increasing sorted order is: [15], [7], [5, 3, 9, 6], [2, 4, 32]


#include <algorithm>
#include <bits/stdc++.h>

using namespace std;
class Solution {
  public:

    unsigned int countSetBits(int num) {
        // the aim is  to count the number of setbits
        // first thought is use unordered map
        // map each element to it's setbit count
        // and do the sorting but a plain unordered map won't preserve the origianl order

        // hence we use a stable_sort with a custom comparator that compares set bit count in descending order
        // to count the number of setbits we can make use of brian kernighan's trick
        // why brian kernighan's trick is more efficient than checking each LSB and doing >>


        // shift method take floor(log2(x))+1 steps
        // brains method runs only one's per set bit
        // eg: for x=32 shift takes 6 iterations, brains only take 1 iteration

        // worst-case tie: all 32 bits are set both takes 32
        // iterations
        //
        // In big-O terms for a value $V$, shifting is
        // O(log V) and Brian Kernighan's is O(set bits)
        //  O(log V)—so they share the same worst-case
        // asymptotic class, while Brian Kernighan's does less work
        // whenever there are fewer 1 bits than bit positions.
        unsigned int x = static_cast<unsigned int>(num);
        int bits=0;
        while (x>0) {
            x&=(x-1);
            bits++;
        }

        return bits;
    }
     vector<int> sortBySetBitCount(vector<int>& arr) {
         stable_sort(arr.begin(),arr.end(),[this](int a,int b){ // you have to pass the context inside []
             return countSetBits(a) > countSetBits(b);          // else this function it caannot know where is this function
         });
         return arr;


    }
};
int main(int argc, char *argv[])
{



    return 0;
}
