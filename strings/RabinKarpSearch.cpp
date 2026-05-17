#include <algorithm>
#include <iostream>
#include <utility>
#include <vector>

using namespace std;

/**
 * given string text
 * rabinkarp is a pattern finding algorithm
 * find all zero-based starting indices pattern occurs as substring in a text
 * can we compute a hashfunction out of it
 *
 */



pair<bool,int> check(string txt,string pat,int i){
    // checking if the window matches the pat
    // if yes also finding the longest suffix which is a prefix say l
    // and moving the j by l characters for the next match
    int m=pat.length();
    int cnt{};
    bool flag=false;
    pair<bool, int>p;
    for (int j = 0; j < m; j++) {
        if (txt[i+j]!=pat[j]) {
            return {false,-1};
        }
        if (j!=0 && txt[i+j]==pat[0]) {
            string sf=txt.substr(i+j,m-j);
            string pf=pat.substr(0,m-j);
            if (sf==pf && !flag) {
                p.first=true;
                flag=true;
                p.second=pf.size();
                cout << sf<<" == "<<pf <<" for i "<<i<<" j is "<<j<< "\n";
            }
        }
    }
    if (flag) {
        return p;
    }else{
        return {false,i};
    }
}


// focus on writing clean code
vector<int> kmpSearch(string &txt,string &pat){

    // we have to find where pat is present in txt
    int n=txt.length();
    int m =pat.length();

    int j{};
    int cnt={};
    int k=-1;
    vector<int>result;
    for (int i = 0; i < n; ) {
        pair<bool, int>t=check(txt, pat, i);
        if (t.second!=-1) {
            result.push_back(i);
            if (t.first) {
                // partially matched
                int o=i+m;
                int k=o;
                cout << "k is "<<k <<" for "<<i << "\n";

                int j{};
                for ( j = t.second; j < m; j++) {
                    cout << "for i "<<i<<" j value is "<<j << "\n";

                    if (k<n && j<m && pat[j]!=txt[k]) {

                        i=o+1;
                        break;
                    } else {
                        k++;
                    }
                }
                cout << "for i "<<i<<" j value is "<<j << "\n";

                if (j==m) {
                    result.push_back(k-m);
                    --k;
                    i=k;
                }
            } else {
                i=i+m;
            }
        } else {
            i=i+1;
        }
    }
    return result;
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
    vector<int>res=kmpSearch(txt, pat);

    // we need to find a way so that we can loop an index over the pattern
    for (auto val : res) {
        cout << val << " ";
    }
    cout<<endl;






    return 0;
}
