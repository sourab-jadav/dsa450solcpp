#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

/**
 * given a k value 1 indicating the step value by which
 * each element can increment or decrement by k to form the next element
 * and x value , it's a search item.
 * binary search will not work here since it is a step array
 * the array can be either decreasing or increasing order
 * choosing the right path is impossible.
 */
int findStepKeyIndex(vector<int> &arr, int k, int x) {
    int n=arr.size();
    int i=0;
    while (i<n) {
        if (arr[i]==x) {
            return i;
        }
        int steps=max(1,abs((arr[i]-x)/k));
        i=i+steps;
    }
}
int main(int argc, char *argv[])
{
    vector<int>vec{20,40,50};

    // if a value has incremented means the lesser value must exist
    // and our aim is to find the first occurence in array
    // if the value at mid is > x then do high =mid-1;
    cout<<findStepKeyIndex(vec, 1, 6);
    return 0;
}
