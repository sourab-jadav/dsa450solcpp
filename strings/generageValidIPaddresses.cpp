#include <iostream>
#include <string>
#include <vector>
using namespace std;


/**
 * we use backtracking and pruning to solve this problem
 * start bractracking from the beginning of the string and try forming segments
 * choose a segment length of 1 2 or 3 digits since a valid ip part cannot exceed 3 digits
 * if the segment is valid place a dot and recursively process the remaining string
 * if the segmenet is invalid prune the recursion
 */

bool validateSegment(string &s) {
    if (s.size()>1 && s[0]=='0') {
        return false;
    }
    int val=stoi(s);
    return val<=255;
}
void solve(string &s,int index,string curr,int cnt,vector<string>&result) {
    if (index>=s.size()) {
        return ;
    }
    if (cnt==3) {
        string t=s.substr(index);
        if (t.size()<=3 && validateSegment(t)) {
            result.push_back(curr+t);
        }
        return;
    }
    string segment="";
    for(int i=index;i<min(index+3,(int)s.size());i++){
        segment+=s[i];
        if (validateSegment(segment)) {
            solve(s, i+1, curr+segment+".", cnt+1, result);
        }
    }

}
int main(int argc, char *argv[])
{
    // string s ="255678166";
    string s="255678166";
    // you have to generate all the possible valid ip addresses
//     Input: s = "255678166"
// Output: [“25.56.78.166”, “255.6.78.166”, "255.67.8.166", "255.67.81.66"]

    // observations
    // "25505011535"
    //

    // this is the first line of action
    vector<string>result;
    cout << "hello world" << "\n";

    solve(s, 0, "", 0, result);
    for (auto val : result) {
        cout << val << "\n";
    }

    return 0;
}
