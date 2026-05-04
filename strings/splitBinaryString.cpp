#include <iostream>
#include <string>

using namespace std;

int method1(string s) {
    int n=s.size();
    if (n%2!=0) {
        return -1;
    }
    int ocount={};
    int zcount={};
    int result{};
    int cnt{};
    for (int i = 0; i < n; i++) {
        if (s[i]=='1') {
            ocount++;
        }else {
            zcount++;
        }
        if (ocount==zcount) {
            result++;
            cnt+=ocount*2;
            ocount=0;
            zcount=0;
        }
    }
    if (cnt==n) {
        return result;
    }else{
        return -1;
    }
  }

int main(int argc, char *argv[])
{
    // string str = "00000000000"; //passed
    // string str="0111100010";    // failed
    // string str="001110010";
    string str = "101000101101010011";
    cout << str.size() << "\n";

cout<<method1(str)<<endl;

    return 0;
}
