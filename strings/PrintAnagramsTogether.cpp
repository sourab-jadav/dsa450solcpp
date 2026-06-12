#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;



int main(int argc, char *argv[])
{

    vector<string>arr{"act", "god", "cat", "dog", "tac"};
    int n=arr.size();
    unordered_map<string, vector<string>>mp;
    for (auto s : arr) {

        vector<int>count(26,0);
        for (auto c : s) {
            count[c-'a']++;
        }
        string res="";
        for (auto v  : count) {
            res+=to_string(v)+"#";
        }
        mp[res].push_back(s);
    }
    vector<vector<string>>res;
    for (auto t : mp) {
        res.push_back(t.second);
    }

    return 0;
}
