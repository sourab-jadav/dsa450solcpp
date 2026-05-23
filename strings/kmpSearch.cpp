#include <algorithm>
#include <iostream>
#include <utility>
#include <vector>

using namespace std;

// this can be optimized further
// using an lps array
// construct a dp based solution for finding the longestproperprefix
// proper prefix which is suffix ending with given element
//
int longestProperPrefixSuffix(string &txt,string &pat,int i) {
    int j=pat.size()-2;

    // in kmp we need to find proper prefix of pattern
    // which is present as suffix in the window

    for (int k = j; k >= 0;k-- ) {
        if (pat[k]==txt[i]) {
            int t=k;
            int l=i;
            while (t>=0) {
                if (pat[t]!=txt[l]) {
                    break;
                }
                t--;
                l--;
            }
            if (t<0) {
                return k+1;
            }
        }
    }
    return 0;
}


// optimized lps area implimentation
void optimizedLPS(vector<int> &lps, string &pat) {
    int n=pat.length();


    // for length 1 lps is always 0
    // for length 2 if both equal then lps is 1
    // for length 3
    //     if str[lps[length-1]]==str[n-1]
    //         lsp[i]=lps[length-1]+1;
    //
    // for length 4
    //
    // k=0
    // if lps[i-1]=0 and str[i]==str[k] then lps[i]=1 k++;
    //
    // if lps[i-1]!=0 and str[i]==str[k] then lps[i]=lps[i-1]+1;
    //
    //
    //
    int len=0;
    lps[0]=0;
    // aabaacaadaabaaba
    // abcdabca
    // 00001231
    for (int i = 1; i < n; i++) {
        if (pat[i]==pat[len]) {
            lps[i]=++len;
        } else {
            if (pat[i]==pat[i-1]) {
                lps[i]=lps[i-1];
            } else {
                lps[i]=0;
                len=0;
            }
        }
    }
    for (auto va : lps) {
        cout << va << " ";
    }
    cout<<endl;
}



int main(int argc, char *argv[]) {


    string txt="aabaacaadaabaaba";
    string pat = "aaba";

    // string txt = "abesdu", pat = "edu";;
    // string txt = "geeksforgeeks", pat = "geek";
    // string txt=    "nncaulpsjyyyymo";
    // string pat=    "yy";        // expected [9,10,11]
                                // got [9,10] fixed!!
    // string txt="fccccinvr"; // expected [ 1 2 ]
    // string pat="ccc";      // got [1] fixed!!
    // string txt="chohfhohohfhppj";
    // string pat="hohfh";
    // cout << txt << "\n";
    // cout << pat << "\n";

    // string txt="aabaaac";
    // string pat="";
    vector<int>lps(txt.length(),0);
    // string txt="ABCDE";
    optimizedLPS(lps, pat);
    cout << "lps array is :" << "\n";

    for (auto v : lps) {
        cout << v << " ";
    }
    cout<<endl;

    int i=0;
    int j=0;
    int n=txt.length();
    int m=pat.length();

    while (i<n) {

        if (txt[i]==pat[j]) {
            i++;
            j++;
        }
        if (j==m) {
            cout << i-m << "\n";
            j=lps[j-1];
        }else if (i<n && txt[i]!=pat[j]) {
            if (j!=0) {
                j=lps[j-1];
            } else {
                i++;
            }
        }

    }







    return 0;
}
