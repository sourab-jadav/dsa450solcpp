#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool check(vector<string> &dictionary, string s,int j) {
    if (j==s.size()) {
        return true;
    }
    // given a array of words
    // you need to check if you can make a string out of
    // it who's value is equal to provided s
    for (auto dict : dictionary) {
        if (dict==s.substr(j,dict.size()) && check(dictionary, s, j+dict.size())) {
            return true;
        }
    }
    return false;
}
int main(int argc, char *argv[])
{
    // string s="ilikedic";
    string s = "xkfkobbnsmbnsm";
    vector<string>dic{    "xkfko","b","bnsm","jg"};
    // vector<string>dic{"i","like","gfg"};
    cout << check(dic,s,0) << "\n";


    return 0;
}
