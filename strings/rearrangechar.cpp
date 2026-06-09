#include <iostream>
#include <string>
#include <utility>
#include <vector>
#include <unordered_map>
#include <algorithm>




using namespace std;

int main(int argc, char *argv[])
{
    // string s = "aaabc";
    // string s=  "aaaabc";
    // string s="aaabb";

    string s = "acbcbcc";
    int n=s.length();
    unordered_map<char, int>mp;
    for (auto va : s) {
        mp[va]++;
    }
    vector<pair<char, int>>vec(mp.begin(),mp.end());

    sort(vec.begin(), vec.end(), [](pair<char, int> &a, pair<char, int> &b) {
        return a.second>b.second;
    });

    for (auto t : vec) {
        cout << t.first <<" "<<t.second << "\n";
    }

    int m=vec.size();
    string temp = "";
    int i=0;
    int j=1;
    // we have to fill the temp with mp values
    // alternatively
    // a 3
    // b 1
    // c 1  => a b a c a
    while (j<m) {
        if (j<m && vec[j].second!=0) {
            temp.push_back(vec[i].first);
            vec[i].second-=1;
            temp.push_back(vec[j].first);
            vec[j].second-=1;
        } else {
            if (vec[i].second==0) {
                i=j+1;
                j=i+1;
            }else{
                j=j+1;
            }
        }
    }
    while (vec[i].second!=0 ) {
        temp.push_back(vec[i].first);
        vec[i].second-=1;
    }

    cout << temp << "\n";








    return 0;
}
