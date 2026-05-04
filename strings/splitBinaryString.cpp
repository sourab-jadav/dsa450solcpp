#include <iostream>
#include <string>

using namespace std;

int method1(string s) {
    int n = s.size();
    int i=0;
    int result{};
    while (i<n) {
        char ch=s[i];
        int count=1;
        if (ch=='0') {
            int j=++i;
            while (j<n && s[j]=='0') {
                count++;
                j++;
            }
            while (count>0 && j<n && s[j]=='1') {
                count--;
                j++;
            }
            if (count>0) {
                return -1;
            }else {
                result++;
            }
            i=j;
        }else if(ch=='1'){
            int j=++i;
            while (j<n && s[j]=='1') {
                count++;
                j++;
            }
            while (count>0 && j<n && s[j]=='0') {
                count--;
                j++;
            }
            if (count>0) {
                return -1;
            } else {
                result++;
            }
            i=j;
        }
    }
    return result;
}

int main(int argc, char *argv[])
{
    // string str = "00000000000"; //passed
    // string str="0111100010";    // failed
    // string str="001110010";
    string str="101000101101010011"; // failed
                                     // expected 6 got -1;
cout<<method1(str)<<endl;

    return 0;
}
