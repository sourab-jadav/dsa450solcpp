#include <iostream>

using namespace std;
 int minFlips(string& s) {
        // code here
        // we need to minimize the number of flips
     int n=s.size();
     bool isZero=true;
     bool isOne=true;
     int zerocount=0;
     int oneCount=0;
     for (int i = 0; i < n; i++) {
         if (isZero && s[i]!='0') {
             zerocount++;
         } else if(!isZero && s[i]!='1') {
             zerocount++;
         }

         if (isOne && s[i]!='1') {
             oneCount++;
         }else if (!isOne && s[i]!='0') {
             oneCount++;
         }
         isZero=!isZero;
         isOne=!isOne;
     }
     return min(zerocount,oneCount);
 }
int main(int argc, char *argv[])
{
    // we can flip either zeroes or we can flip either 1's
    string s="001";
    cout << minFlips(s) << "\n";

    return 0;
}
