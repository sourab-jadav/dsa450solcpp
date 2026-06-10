#include <iostream>
#include <string>
#include <utility>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <queue>





using namespace std;


string rearrangeChar(string &s) {
    priority_queue<pair<int, int>>pq;
    unordered_map<char, int>mp;
    int n=s.size();
    for (auto v : s) {
        mp[v]++;
    }
    for (auto t : mp) {
        pq.push({t.second,t.first});
    }
    string res="";
    pair<int, int>prev={-1,'#'};
    while (!pq.empty()) {
        pair<int, int>p=pq.top();
        pq.pop();
        res.push_back(p.second);

        if (prev.first>0) {
            pq.push(prev);
        }
        p.first--;
        prev=p;
    }
    if (res.size()!=n) {
        return "";
    }
    return res;
}

int main(int argc, char *argv[])
{
    // string s = "aaabc";
    // string s=  "aaaabc";
    string s="aaabb";

    // string s = "acbcbcc";
    int n=s.length();
    unordered_map<char, int>mp;

    rearrangeChar(s);

    return 0;
}
