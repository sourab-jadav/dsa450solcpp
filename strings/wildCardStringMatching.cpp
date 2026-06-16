#include <iostream>
#include <string>
using namespace std;

bool match(string wild, string pattern,int m,int n,int i,int j) {
        // code here
    /**
     * wild=ge*ks
     * pat=geeks;
     *
     */
    if (i==m-1 && wild[i]=='*') {
         return true;
    }
    if ((i==m && j<n)||(j==n && i<m)) {
        return false;
    }


    if (i==m && j==n) {
        return true;
    }

    if (wild[i]==pattern[j] || wild[i]=='?' ) {
        return match(wild, pattern, m, n, i+1, j+1);
    } else if (wild[i] == '*') {
        if (i==m-1) {
            return true;
        } else {
            return match(wild, pattern, m, n, i, j+1) || match(wild,pattern,m,n,i+1,j);
        }
    }else{
        return false;
    }
        // logic around *
        // if we encounter a ?
        // we just do j+1

        // if we encounter a *
        // we do j+1 until pattern[j+1]==wild[i+1]
        // even if j+1 i+1 are equal
        // there is a possibility that j+1th value was supposed to be
        // included as part of wild card matching
        // e.g ge*ks
        //     geekdks

}

int main(int argc, char *argv[])
{
    // string wild="ge*kssdf";
    // string pattern="mississippi";
    // string wild="m*iss*iss*p*";
    // string wild="m*isia*pi";

    string wild="*abc???de*";
    string pattern="abcabczzzde";
    string pwild="";
    pwild+=wild[0];
    for (int i = 1; i < wild.length(); i++) {
        if (wild[i]=='*' && wild[i]==wild[i-1]) {
            continue;
        }
        pwild+=wild[i];
    }
    cout << "pwild is "<<pwild << "\n";

    int m=wild.length();
    int n=pattern.length();
    cout <<match(wild, pattern, m, n, 0, 0)  << "\n";
    return 0;
}
