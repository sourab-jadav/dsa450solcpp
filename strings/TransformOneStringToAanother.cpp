#include <iostream>
#include <unordered_map>
using namespace std;
int TransformString(string s1, string s2) {
    int n1=s1.length();
    int n2=s2.length();

    if (n1!=n2) {
        return -1;
    }

    /**
     * since if a character does not match
     * we move it to the front let's start matching from the end
     * i=n-1;
     * j=n-1;
     * if s1[i]==s2[j] do i--;j--;
     * if s1[i]!=s2[j] then this character i must be moved to the front hence this count under operation
     *
     * s1 = "GeeksForGeeks", se2 = "ForGeeksGeeks"
     *      "rGeeksFoGeeks"
     *      "orGeeksFGeeks"
     *      "ForGeeksGeeks"
     *      "ForGeeksGeeks"
     *     string s1="EACBD";
     *              ="BEACD"
     *              ="ABECD"
     *              ="EABCD"
     *     string s2="EABCD";
     *
     *     s1 = YUZKxQReJATCsD
     *     s2 = seCJQKZRTADUxY
     */

    unordered_map<char, int>freq;
    for (int i = 0; i < n1; i++) {
        freq[s1[i]]++;
        freq[s2[i]]--;
    }
    for (auto const& [key, value] : freq) {
        if (value!=0) {
            return -1;
        }
    }
    int i=n1-1;
    int j=n1-1;
    int operations=0;
    while (i>=0) {
        if (s1[i]==s2[j]) {
            i--;
            j--;
        } else {
            i--;
            operations++;
        }
    }
    return operations;
}
int main(int argc, char *argv[])
{
    string s1="EACBD";
    string s2="EABCD";


    // the only allowed action in transformation is
    // picking a char in s1 and placing infront of it

    // for the above case if you pick b in s1 and put it in front
    // it will convert into s2
    cout<<TransformString(s1,s2);
    return 0;
}
