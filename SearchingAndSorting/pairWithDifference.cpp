#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>



using namespace std;
/**
 * two sum problem
 * we need to find a pair who's diff is x
 * if we sort the array
 * hence lower values will be on the left side
 * in difference we do higher-lower = x
 * so we check for the lower on the left side
 * i.e we check for value equal to higher-x
 */
 bool findPair(vector<int> &arr, int x) {
        // code here
        sort(arr.begin(),arr.end());
        int n=arr.size();
        unordered_set<int> s;
        for(int i=0;i<n;i++){
            if(s.find(arr[i]-x)!=s.end()){
                return true;
            }else{
                s.insert(arr[i]);
            }
        }
        return false;
    }
int main(int argc, char *argv[])
{


    return 0;
}
