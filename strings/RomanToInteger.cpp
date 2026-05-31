#include <iostream>
#include <unordered_map>

using namespace std;
 int romanToDecimal(string &s) {
        // code here
    unordered_map<char, int>mp{
        {'I', 1}, {'X', 10}, {'L', 50}, {'C', 100},{'D',500},{'M',1000},{'V',5}
    };
    int total{};
     int n=s.length();
     for (int i = n - 1; i >= 0; i--) {
         if (i==n-1) {
             total+=mp[s[i]];
         } else {
             if (mp[s[i]]<mp[s[i+1]]) {
                 total-=mp[s[i]];
             } else {
                 total+=mp[s[i]];
             }
         }
     }
     return total;
 }
int main(int argc, char *argv[])
{
    // string s="IX";
    // string s ="XL";
    string s="MCMIV";
    cout<<romanToDecimal(s);


    return 0;
}
