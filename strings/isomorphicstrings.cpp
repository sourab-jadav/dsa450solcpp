#include <iostream>
#include <unordered_map>
#include <unordered_set>


using namespace std;

bool isIsomorphic(string s1,string s2){
    unordered_map<char, char>mp;
    unordered_set<char>st;

    if (s1.length()!=s2.length()) {
        return false;
    }


    int n=s1.length();
    for (int i = 0; i < n; i++) {
        if (mp.find(s1[i])!=mp.end()) {
            char c1=mp[s1[i]];
            char c2=s2[i];
            if (c1==c2) {
                continue;
            } else {
                return false;
            }
        } else {
            // this below logic is to satisfy the condition:
            // no two characters may map to the same character
            if (st.find(s2[i])!=st.end()) {
                return false;
            } else {
                mp[s1[i]]=s2[i];
                st.insert(s2[i]);
            }
        }
    }
    return true;
}
int main(int argc, char *argv[])
{
    string s1="aab";
    string s2="xxy";
    // a character may map to itself
    // but no two character may map to the same character
    // the idea is to create char -> char mapping from s1 -> s2

    unordered_map<char, char>mp;


    if (s1.length()!=s2.length()) {
        return false;
    }

    int n=s1.length();
    for (int i = 0; i < n; i++) {
        if (mp.find(s1[i])!=mp.end()) {
            char c1=mp[s1[i]];
            char c2=s2[i];
            if (c1==c2) {
                continue;
            } else {
                return false;
            }
        } else {
            mp[s1[i]]=s2[i];
        }
    }




    cout<<endl;

    return 0;
}
