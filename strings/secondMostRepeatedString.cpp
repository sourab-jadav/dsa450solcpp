#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>


using namespace std;
int secFrequent(vector<string> &arr) {
        // code here
    unordered_map<string, int>mp;
    for (auto str : arr) {
        mp[str]++;
    }
    int max=-1;
    int secondMax=-1;
    for (auto t : mp) {
        if (t.second > max) {
            secondMax=max;
            max=t.second;
        }else if (t.second > secondMax && t.second < max) {
            secondMax=t.second;
        }
    }

    return secondMax;

    }
int main(int argc, char *argv[])
{
    vector<string> arr={"aaa", "bbb", "ccc", "bbb", "aaa", "aaa"};

    cout<<secFrequent(arr);


    return 0;
}
