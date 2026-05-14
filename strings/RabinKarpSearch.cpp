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
          return j+1;
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
    string text ="aabaacaadaabaaba";
    string pattern="aaba";
    //
    // we need to find this pattern in the above text
    int n=text.size();
    int m=pattern.size();
    for (int i = 0; i <= n-m; ) {
        // the goal is o n time
        if (text[i]==pattern[0]) {
            int t=check(text, pattern, i);
            if (t==i) {
                cout << t << "\n";
                i+=i+m;
            } else {
                i=t;
            }
        }else{
            i++;
        }
    }
    return 0;
}
