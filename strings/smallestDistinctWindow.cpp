#include <algorithm>
#include <iostream>
using namespace std;
#include <set>
#include <unordered_map>
#include <climits>


int main(int argc, char *argv[])
{
    set<char>s;
    // string str="aabcbcdbca";
    // string str = "geeksforgeeks"; // eksforg
    // string str="aabcbcdbca";
    string str = "geeksforgeeks";
    int n=str.length();
    s.insert(str.begin(),str.end());
    int wsize=s.size();
    cout << wsize << "\n";
    // we have unique character of length
    unordered_map<char, int>mp;
    int start=0;
    int end=0;
    int result=n;
    while (end<n) {
        mp[str[end]]++;
        end++;
        while (start<end && mp.size()==s.size()) {
            cout << "inside start and end "<<start<<" "<<end << "\n";
            cout << " mp size is "<<mp.size()<< " s size is "<<s.size() << "\n";

            result=min(result,end-start);
            mp[str[start]]--;
            if (mp[str[start]]==0) {
                cout << str[start]<< " became zero" << "\n";

                mp.erase(str[start]);
            }
            start++;


        }


    }


    cout << "result is "<<result << "\n";



      // we need a start pointer and end pointer
      // if we have a start pointer we move forward






    return 0;
}
