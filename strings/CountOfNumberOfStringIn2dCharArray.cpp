#include <algorithm>
#include <iostream>
#include <utility>
#include <vector>
#include <cstring>

#define NO_OF_CHARS 256

using namespace std;

// todo write a search function which searches for a vector in 2d matrix

void search(string txt,string pat){
    // we have to write using boyer mayer's search algorithm

    // it searches from the end
    //
    // at index j txt[s+j] != pat[j]
    // the char = txt[s+j] is present on the left side of pat
    // i.e towards the lesser index(left side)
    // then we shift the window on txt towards right by the length of j-badchar[txt[s+j]];
    //
    // at index j txt[s+j] == pat[j] matched the whole window and j became <0
    // now we see where the char at index s+m in txt lies in pat
    // say that char at m in txt is present at index 3 in pat(index in pat formed towards left of j)
    // then you have to do m-3

    int m=pat.length();
    int n=txt.length();
    int badchar[NO_OF_CHARS];
    memset(badchar, -1, sizeof(badchar));
    for (int i = 0; i < m; i++) {
        badchar[pat[i]]=i;
    }
    int s=0;
    while (s<=n-m) {
        int j=m-1;
        while (j>=0 && pat[j]==txt[s+j]) {
            j--;
        }
        if (j<0) {
            // means the window starting from s matched
            cout << "matched at index "<<s << "\n";
            s+=s+m<n?m-badchar[txt[s+m]]:1;
        }else{
            // value at j in pat did not matched with value at s+j in
            // if the value at s+j is present in pat on the left side of j
            // shift the window of txt towards left by decreasing it's value
            // s+=j-badarr[txt[s+j]]
            //
            // if the value at s+j is present in pat on the right side of j
            s+=max(1,j-badchar[txt[s+j]]);
        }
    }
}




int main(int argc, char *argv[])
{

    // find if a string occurs in a row or column
    string target="SNAKES";
    return 0;
}
