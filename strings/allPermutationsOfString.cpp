#include <algorithm>
#include <iostream>
#include <string>
#include <type_traits>
#include <utility>
#include <vector>
#include <set>
#include <unordered_map>


using namespace std;
void findUniquePermuatations( unordered_map<char, int> mp, int i,string curr,
                              int n,vector<string>&res) {
    if (i==n) {
        res.push_back(curr);
        return;
    }
    for (auto p : mp) {
        char c= p.first;
        int cnt=p.second;
        if (cnt==0) {
            continue;
        }
        curr.push_back(c);
        mp[c]--;
        findUniquePermuatations(mp, i+1, curr, n, res);
        curr.pop_back();
        mp[c]++;
    }
}
vector<string> findPermutations(string &s) {
    // we need to find only unique permutations
    // if we have considered a particular character as part of
    // permutation
    // then we can skip the iteration of that character

    /**
     * you need
     * unordered_map<char,int> mp;
     *
     */
    unordered_map<char, int>mp;
    for (auto c : s) {
        mp[c]+=1;
    }
    int n=s.size();
    vector<string>result;
    findUniquePermuatations(mp, 0, "", n, result);
    return result;
}
int main(int argc, char *argv[])
{
    string s="ABC";
    vector<string>result=findPermutations(s);
    for (auto str : result) {
        cout << str << " ";
    }
    cout<<endl;

    // the idea is to use cnt map of each character



    return 0;
}
