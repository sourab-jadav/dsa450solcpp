#include <iostream>
#include <vector>

using namespace std;

/**
 * given string text
 * rabinkarp is a pattern finding algorithm
 * find all zero-based starting indices pattern occurs as substring in a text
 * can we compute a hashfunction out of it
 *
 */

vector<int> usingRabitKarpHash(string txt,string pat){
    int n=txt.size();
    int m=pat.size();

    // for rabinhash
    // we need a multiplier (choose a number which represents the range of alphanumeric character)
    // we need a quotient (choose a prime number like 101 to avoid collisions)
    //

    int p{};
    int h=1;
    int d=256;
    int q=101;
    int t{};
    vector<int>result;
    for(int i=0;i<m-1;i++){
        h=(h*d)%q;
      }
    for (int i = 0; i < m; i++) {
        p=((p*d)+pat[i])%q;
        t=((t*d)+txt[i])%q;
    }

    // we have caculated hash value for current window
    // the challege is using this value we have to calculate for the
    // next window
    for (int i = 0; i <= n - m; i++) {
        if (p==t) {
            int j;
            for( j=0;j<m;j++){
                if (txt[i+j]!=pat[j]) {
                    break;
                }
            }
            if (j==m) {
                result.push_back(i);
            }
        }
        if (i<n-m) {
            t=(d*(t-txt[i]*h)+txt[i+m])%q;
            if (t<0) {
                t=(t+q);
            }
        }
    }
    return result;
}


int main(int argc, char *argv[]) {

string txt = "geeksforgeeks";
    string pat = "geeks";
    vector<int> res = usingRabitKarpHash(txt, pat);
    for (auto it : res)
    {
        cout << it << " ";
    }
    cout << "\n";
    return 0;
}
