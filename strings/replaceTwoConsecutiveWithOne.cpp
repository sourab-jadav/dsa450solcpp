#include <iostream>

using namespace std;
string removeDuplicates(string& s) {
    int n=s.length();
    string result="";

    if(n>=1){
        result+=s[0];
        for(int i=1;i<n;i++){
            if(s[i]==s[i-1]){
                continue;
            }else{
                result+=s[i];
            }
        }
    }
    return result;
}
int main(int argc, char *argv[])
{
    string s = "aabb";
    cout << removeDuplicates(s) << "\n";


    return 0;
}
