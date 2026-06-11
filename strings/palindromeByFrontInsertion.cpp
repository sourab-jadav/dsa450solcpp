#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;
vector<int> constructLPS(string &s) {
    int n=s.size();
    vector<int>lps(n,-1);
    lps[0]=0;
    int len=0;
    // constructing lps array
    // if(str[i]==str[len])
    int i=1;
    while (i<n) {
        if (s[i]==s[len]) {
            lps[i]=++len;
            i++;
        } else {
            if (len!=0) {       // if s[i] does not match with s[len]
                                // instead of checking from start of pattern again
                                // check if it matches with previous char
                // 1 <- p
                //      s -> 1
                // len -> prefix
                // i   -> suffix // basically it's two pointer problem
                len=lps[len-1];
            } else {
                lps[i]=0;
                len=0;
                i++;
            }
        }
    }
    return lps;
}
 int minChar(string &s) {
        // code here
    string rev = s;
    int n=s.length();
     reverse(rev.begin(),rev.end());
     s=s+"$"+rev;
     vector<int>lps=constructLPS(s);
     return n-lps.back();

    }
int main(int argc, char *argv[])
{
    cout << "palindrome by front insertion" << "\n";
    string s="abc";
    int n=s.length();
    int result=n-1;


    return 0;
}
