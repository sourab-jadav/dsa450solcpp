#include <iostream>
#include <vector>

using namespace std;

/**
 * given string text
 * rabinkarp is a pattern finding algorithm
 * find all zero-based starting indices pattern occurs as substring in a text
 * can we compute a hashfunction out of it
 *
 */
int main(int argc, char *argv[]) {

    string txt = "vxqxxqxqxc";
    string pat = "xqx";
    vector<int> hash(txt.size(), 0);
    // we need to find this pattern in the above text
    int n = txt.size();
    int m = pat.size();
    int pat_hash{};
    for (auto x : pat) {
        pat_hash += x;
    }
    int curr_hash{};
    for (int i = 0; i < m; i++) {
        curr_hash += txt[i];
    }
    hash[0] = curr_hash;
    for (int i = 1; i <= n - m; i++) {
        curr_hash = curr_hash - txt[i - 1] + txt[i + m - 1];
        hash[i] = curr_hash;
    }
    for (int i = 0; i <= n - m; i++) {
        if (hash[i] == pat_hash) {
            int j;
            for (j = 0; j < m; j++) {
                if (txt[i+j]!=pat[j]) {
                    break;
                }
            }
            if (j==m) {
                cout << i << "\n";
            }
        }
    }
    return 0;
}
