#include <iostream>
#include <stack>
#include <unordered_map>

using namespace std;

bool balancedParenthisis(string &s) {
    int n=s.size();
    stack<char>stk;
    int i=0;
    unordered_map<char, char>mp;
    mp[']']='[';
    mp['}']='{';
    mp[')']='(';
    for (int i = 0; i < n; i++) {
        if (s[i]=='[' || s[i]=='{' || s[i]=='(') {
        cout << s[i] << " ";
            stk.push(s[i]);
        } else {
            if (stk.empty()||stk.top()!=mp[s[i]]) {
                return false;
            }else{
                stk.pop();
            }
        }
    }
    return stk.empty();
}
int main(int argc, char *argv[])
{
    // string s="}";
    string s="[{()}]";
    cout << balancedParenthisis(s) << "\n";
    return 0;
}
