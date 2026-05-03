#include <algorithm>
#include <iostream>
#include <string>
#include <type_traits>
#include <utility>
#include <vector>
#include <set>

using namespace std;
void printPermutations(string s,int i,int n,vector<string>&vec) {
    if (i==n) {
      if (find(vec.begin(), vec.end(), s) == vec.end()) {
          vec.push_back(s);
        }
    }

    for (int j = i; j < n; j++) {
        swap(s[i],s[j]);
        printPermutations(s, i+1, n,vec);
        swap(s[i],s[j]);
    }
}
int main(int argc, char *argv[])
{
    string s="AAA";
    int n=s.size();
    vector<string>vec;
    printPermutations(s, 0, n,vec);
    set<string>result(vec.begin(),vec.end());
    vec.clear();


    return 0;
}
