#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <vector>
using namespace std;


int majorityElement(vector<int> &arr) {
    // code here
        unordered_map<int,int> mp;
        int n=arr.size();
        for(int i=0;i<n;i++){
            int cnt=++mp[arr[i]];
            if(cnt>n/2){
                return arr[i];
            }
        }
        return -1;
}
int main(int argc, char *argv[])
{

    int arr[]{1,1,2,1,3,5,1};
    int n=sizeof(arr)/sizeof(arr[0]);
    // first approach is to use hashmap if the count > n/2 return the element


    return 0;
}
