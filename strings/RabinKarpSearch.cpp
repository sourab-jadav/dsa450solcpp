#include <iostream>

using namespace std;

/**
 * given string text
 * rabinkarp is a pattern finding algorithm
 * find all zero-based starting indices pattern occurs as substring in a text
 */
int check(string &text, string &pattern,int i) {
  for (int j = i, k = 0; j < i + pattern.size(); j++, k++) {
      if (text[j]!=pattern[k]) {
          return i+1;
      }
    }
  return i;
}

int main(int argc, char *argv[])
{
    // string text ="geeksforgeeks";
    // string pattern="geeks";     // tc passed ;)
    // string text= "abesdu" ;
    // string pattern = " edu";
    // string txt ="aabaacaadaabaaba"; // what if there is a pattern
    //                                  // inside the found pattern
    // // string text ="aabaaba";          // like this
    // string pat="aaba";

    string txt="vxqxxqxqxc";
    string pat="xqx";
    // we need to find this pattern in the above text
    int n=txt.size();
    int m=pat.size();
    for (int i = 0; i <= n-m; ) {
        // the goal is o n time
        if (txt[i]==pat[0]) {
            int t=check(txt, pat, i);
            if (t==i) {
                cout << t << "\n";
                i=t+1;
            } else {
                i=t;
            }
        }else{
            i++;
        }
    }
    return 0;
}
