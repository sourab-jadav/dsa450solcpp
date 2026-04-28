#include <iostream>

using namespace std;
/**
 * nice solution but TLE ;)
 */
bool areRotations(string &s1, string &s2) {
    if (s1.size() != s2.size()) {
        return false;
    }
    int n = s1.size();
    for (int i = 0; i < n; i++) {
        int count = 0;
        for (int j = 0; j < n; j++) {
            if (s1[j] == s2[(i + j) % n]) {
                count++;
            } else {
                break;
            }
        }
        if (count == n) {
            return true;
        }
    }
    return false;
}

/**
 * another solution for the same problem
 * count the occurences of the first character
 *
 * traverse through the second string that many times
 */
bool areRotationsByFirstCharCount(string &s1, string &s2) {
    if (s1.size() != s2.size()) {
        return false;
    }
    int n=s1.size();
    cout << "n value "<<n << "\n";

    int count =0;
    for (int i = 0; i < n; i++) {
        if (s1[0]==s2[i]) {
            count++;
        }
    }
    cout << "count is "<<count << "\n";

    for(int i=0;i<count;i++){
        bool match=true;
        for(int j=0;j<n;j++){
            if (s1[0]==s2[j]) {
                cout << "at j value "<<j << "\n";

                int count =1;
                int k=1;
                int l=(j+1)%n;
                while (k<n && s1[k]==s2[l]) {
                    count++;
                    k++;
                    l=(l+1)%n;
                }
                if (count != n) {
                    match=false;
                }
                if (match) {
                    return true;
                }
            }
            match=true;
        }

    }
    return false;
}

int main(int argc, char *argv[]) {
    // string s1="abcd";
    // string s1="geeksforgeeks";
    // string s2="forgeeksgeeks";

    string s1="labdbfvxigw";
    string s2="abdbfvxigwl";
    cout << areRotationsByFirstCharCount(s1, s2) << "\n";


    return 0;
}
