#include <algorithm>
#include <iostream>
#include <utility>
#include <vector>

using namespace std;


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


void kmpSearch(string &txt,string &pat){
    int n=txt.size();
    int m=pat.size();
    vector<int>result;
    // here we are doing sliding window shifting by +m
    // in every iteration
    // we we found a proper prefix of pattern which is
    // present as suffix in the current window
    //
    // then we shift the j by l for next match
    // and for i we do i+(m-l);
    //
    int l{};
    int j{};
    for (int i = 0; i <= n - m; ) {
        bool flag=false;
        for(int c=0;c<m-l;c++){
            cout << "for i "<<i<<" j value is "<<j << "\n";
            if (txt[i+j]!=pat[j]) {
                cout << txt[i+j]<<" !=="<<pat[j] << "\n";
                flag=true;
                break;
            } else {
                cout << txt[i+j]<<" ===="<<pat[j] << "\n";

            }
            j=(j+1)%m;
        }
        if (!flag) {
            cout<<"catched for " << i << " ";
            cout<<endl;
        } else {
            j=0;
        }
        l=longestProperPrefixSuffix(txt, pat, i+m-1);
        cout << "l value at "<<i <<" is "<<l << "\n";

        if (l>0) {
            i+=m-l;
            j=(j+l)%m;
        } else {
            i+=m;
        }
    }
}

int main(int argc, char *argv[]) {


    // string txt="aabaacaadaabaaba";
    // string pat = "aaba";

    // string txt = "abesdu", pat = "edu";;
    // string txt = "geeksforgeeks", pat = "geek";
    // string txt=    "nncaulpsjyyyymo";
    // string pat=    "yy";        // expected [9,10,11]
                                // got [9,10] fixed!!
    // string txt="fccccinvr"; // expected [ 1 2 ]
    // string pat="ccc";      // got [1] fixed!!
    string txt="chohfhohohfhppj";
    string pat="hohfh";
    cout << txt << "\n";
    cout << pat << "\n";


    // string txt = "geeksforgeeks", pat = "geek";
kmpSearch(txt, pat);

    // we need to find a way so that we can loop an index over the pattern
    // for (auto val : res) {
    //     cout << val << " ";
    // }
    cout<<endl;






    return 0;
}
