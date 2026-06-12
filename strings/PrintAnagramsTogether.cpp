#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

int computeHash(string &str) {
    int n=str.length();
    int result=0;
    for (auto c : str) {
        result+=c;
    }
    return result;
}

int main(int argc, char *argv[])
{
    cout << "printing anagrams" << "\n";
    vector<string>arr{"act", "god", "cat", "dog", "tac"};
    int n=arr.size();
    unordered_map<int, vector<string>>mp;
    for (auto s : arr) {
        int x=computeHash(s);
        mp[x].push_back(s);
    }
    vector<vector<string>>res;
    for (auto t : mp) {
        res.push_back(t.second);
    }

    return 0;
}
