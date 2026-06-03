#include <iostream>
#include <stack>


using namespace std;
int minimumNumberOfSwaps(string &s) {
    //
    // minimum number of swaps to make the string balanced
    // the greedy approach that you can take is
    //
    // a closing bracket cannot appear before opening bracket
    //
    // if the string till i is unbalanced and a closing bracket
    // appears first
    //
    // opening bracket is always safe
    // when opening bracket appears see if prev is closing bracket
    // if yes if the closing and opening bracket count matched so far
    //  if not then swap the current opneing bracket with the previous

    bool flag=false;
    int c{},o{};
    int i=0;
    int fcount{};
    int n=s.length();
    for (int j = 0; j < n; j++) {
      for (int i = 0; i < n; i++) {
          if (s[i]=='[') {
              if (i==0 || o>=c) {
                  o++;
              }else if (s[i-1]==']') {
                  cout << "i-1 == ] hence " << "\n";

                  swap(s[i], s[i - 1]);
                  cout << s << "\n";

                  flag=true;
                  fcount+=1;
                  c--;
              }
          }else{
              c++;
          }
        }

      if (!flag) {
          return fcount;
      }
      flag=false;
        c=0;
        o=0;
    }
    return 0;
}
int main(int argc, char *argv[])
{
    // a swap is necessary when closing first and opening second appears
    // string s="[]][][";
    // string s="[]][][]][[";      // failing for this input
                                // []][][]][[
                                // [][]][]][[ 1 swap
                                // [][][]]][[ +1
                                // [][][]][][ +1
                                // [][][][]][ +1
                                // [][][][][] +1
                                // total no. of swaps is 5

    string s="]]]][[][[[";  // expected is 13 got is 15
    cout<<minimumNumberOfSwaps(s);

    return 0;
}
