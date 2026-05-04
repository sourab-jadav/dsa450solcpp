#include <algorithm>
#include <iostream>

using namespace std;
/**
 * we need to convert s1 to s2
 * operations that can be performed are insert then next call becomes n1 n2-1
 * remove n1-1, n2;
 * replace n1-1,n2-1
 */
int method1(string s1, string s2,int i,int j) {
    if (i<0) {
        return j+1;
    }else if (j<0) {
        return i+1;
    }
    if (s1[i]==s2[j]) {
        return method1(s1, s2, i-1, j-1);
    }
    return 1+min(method1(s1, s2, i, j-1),min(method1(s1, s2, i-1, j),method1(s1, s2, i-1, j-1)));
}
int main(int argc, char *argv[])
{
  // string s1 = "gfg";
  string s1= "mdl";
  string s2="qhszmmbgi";

  int n1=s1.size();
  int n2=s2.size();
  cout<<method1(s1, s2, n1-1, n2-1)<<endl;

    return 0;
}
