#include <iostream>
#include <string>

using namespace std;


// given an input number you need to get
// count and say of it
//
// say if the number is 4
//
// c and s of 1 is 1
// c and s of 2 is RLE(run-length encoding) of 1 -> 11
// c and s of 3 is RLE of cs(2) -> 21
// c and s of 4 is RLE of cs(3) -> 1211
string RLE(string& str) {
    int n=str.size();
    string rle="";
    if (n>1) {
        int count=1;
      for (int i = 1; i < n; i++) {
          if (str[i]!=str[i-1]) {
              rle+=to_string(count)+str[i-1];
              count=1;
          }else {
              count++;
          }
      }
      // edge case will be for the last element
      // n-1 and n-2 are same
      if (str[n-1]==str[n-2]) {
          rle+=to_string(count)+str[n-1];
      }else {
          rle+=to_string(1)+str[n-1];
      }
    }else {
        rle+=to_string(1)+str[0];
    }
    return rle;
}
string method1(int n) {
    if (n==1) {
        return "1";
    }else {
        string x=method1(n-1);
        return RLE(x);
    }
}
int main(int argc, char *argv[])
{
    cout << method1(4) << "\n";


    return 0;
}
