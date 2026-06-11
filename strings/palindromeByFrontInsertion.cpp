#include <iostream>
using namespace std;

int main(int argc, char *argv[])
{
    cout << "palindrome by front insertion" << "\n";
    string s="abc";
    cout << s << "\n";

    // can we solve it using lps

    int n=s.length();
    int result=n-1;
    for(int i=0;i<n;i++){
      for (int j = i + 1; j < n; j++) {
          if (s[i]==s[j] && (j-i+1 ==2 || j-i+1 ==3)) {
              int k=i;
              int l=j;
              while (k>=0 && l<n && s[k]==s[l]) {
                  k--;
                  l++;
              }
              if (k<0) {
                  result=min(result,n-l);
              }
          }
        }
    }
    cout <<result  << "\n";

    return 0;
}
