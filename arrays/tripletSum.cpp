#include <iostream>
#include <vector>

using namespace std;

/**
 * finding a triplet that sums up to a given value
 * approach one
 * o(n3) solution (naive solution)
 *
 * maintain a hashset s
 * like unordered_set<int>st;
 * taking any two values at a time and check if a third value exist in a set
 *
 * two pointer approach
 * sort the whole array
 * for a value at given i index
 *     run the two pointer from one pointing to i+1 and other pointing to n-1
 *     looking for a sum = triplet - value at i
 *
 */
int main(int argc, char *argv[])
{
    cout << "hello world" << "\n";

    return 0;
}
