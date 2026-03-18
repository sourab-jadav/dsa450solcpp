#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

/**
 * finding if an array is subset of another array
 * better approach is to sort arrays and use two pointer with (mlogm+nlogn) time
 * TC analysis
 *
 * sorting both arrays = mlogm + nlogn
 *
 * 2 pointer traversal
 *     pointer i moves atmost m times
 *     pointer j moves atmost n times
 *     0(n+m)
 *
 * final TC
 * o(nlogn+mlogm+n+m) =>since sorting dominates
 * it should be o(nlogn+mlogm)
 *
 * conclusion:-
 * it is better than brute force
 * slightly worse than hashing
 *  works well when sorting is acceptable
 */
bool usingSorting(vector<int> &vec1, vector<int> &vec2) {
    sort(vec1.begin(),vec1.end());
    sort(vec2.begin(),vec2.end());

    int m = vec1.size();
    int n = vec2.size();

    int i=0,j=0;
    while (i<m && j<n) {
        if (vec1[i]<vec2[j]) {
            i++;
        }
        else if (vec1[i]==vec2[j]) {
            i++;
            j++;
        }else {
            return false;
        }
    }
    return (j == n);
}


/**
 * using hashing
 * o(m+n) time and o(m) space
 *
 * create a hashset insert all the elements of array m
 * multiset is implemented using red black tree with tc logn
 * for insert search and delete
 *
 */
bool isSubset(vector<int> a, vector<int> b) {
    multiset<int  >hashSet(a.begin(),a.end());
    // in multiset duplicates are allowed

for (auto val : hashSet) {
    if (hashSet.find(val)==hashSet.end()) {
        return false;
    }
    hashSet.erase(hashSet.find(val));
 }
 return true;
}

int main(int argc, char *argv[])
{
    cout << "something something" << "\n";

    return 0;
}
