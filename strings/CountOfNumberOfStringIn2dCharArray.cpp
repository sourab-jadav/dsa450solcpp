#include <iostream>
#include <utility>
#include <vector>

using namespace std;

int findOccurrence(vector<vector<char>> &mat, string target) {
    int m=mat.size();
    int n=mat[0].size();
    int t=target.size();
    vector<pair<int, int>>p;
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
          if (mat[i][j]==target[0]) {
              p.push_back({i,j});
          }
        }
    }
    for (auto v : p) {
        cout << v.first<<" "<<v.second << "\n";


    }

    int count{};
    for (auto v : p) {
        int i=v.first;
        int j=v.second;
        if (i+t-1<m) {
            // bottom
            int k=i+1;
            int l=1;
            while (k<m && l<=t && target[l]==mat[k][j]) {
                l++;
                k++;
            }
            if (l==target.size()) {
                count++;
            }
        }
        // top
        if (i-t+1>=0) {
            int l=1;
            int k=i-1;
            while (k>=0 && l<=t && target[l]==mat[k][j]) {
                l++;
                k--;
            }
            if (l==target.size()) {
                count++;
            }
        }
        // left
        if (j-t+1>=0) {
            int l=1;
            int k=j-1;
            while (k>=0 && l<=t && target[l]==mat[i][k]) {
                l++;
                k--;
            }
            if (l==target.size()) {
                count++;
            }
        }
        // right
        if (j+t-1<n) {
            int l=1;
            int k=j+1;
            while (k<n && l<=t && target[l]==mat[i][k]) {
                l++;
                k++;
            }
            if (l==target.size()) {
                count++;
            }
        }

    }
    return count;

}


int main(int argc, char *argv[])
{

    // find if a string occurs in a row or column
    string target="SNAKES";


    // vector<vector<char>>     a = {
    //         {'B','B','M','B','B','B'},
    //         {'C','B','A','B','B','B'},
    //         {'I','B','G','B','B','B'},
    //         {'G','B','I','B','B','B'},
    //         {'A','B','C','B','B','B'},
    //         {'M','C','I','G','A','M'}
    // };
    vector<vector<char>> a = {
        {'S','N','B','S','N'},
        {'B','A','K','E','A'},
        {'B','K','B','B','K'},
        {'S','E','B','S','E'},
    };
    cout << findOccurrence(a, target) << "\n";




    return 0;
}
