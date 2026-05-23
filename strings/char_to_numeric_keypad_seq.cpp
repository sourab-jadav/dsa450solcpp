#include <iostream>
#include <string>

using namespace std;

int main(int argc, char *argv[]) {
    // 3*6 =18+1;
    // say the character is G

    string S = "GFG";

    string res = "";
    for (auto c : S) {
        // 1. Handle spaces FIRST to prevent negative ASCII math
        if (c == ' ') {
            res += "0";
            continue;
        }

        int k = c - 'A' + 1;
        int result = k / 3 + 1;

        // 2. Handle Keypad 7, 8, 9 (The irregular 4-letter groups)
        if (c >= 'P' && c <= 'S') {
            res += std::string((c - 'P') + 1, '7');
        } else if (c >= 'T' && c <= 'V') {
            res += std::string((c - 'T') + 1, '8');
        } else if (c >= 'W' && c <= 'Z') {
            res += std::string((c - 'W') + 1, '9');
        }
        // 3. Handle Keypad 2, 3, 4, 5, 6 securely
        else {
            if (k % 3 == 0) {
                res += std::string(3, to_string(result)[0]);
            } else {
                res += std::string(k % 3, to_string(result + 1)[0]);
            }

        }
    }
    cout << res << "\n";

    return 0;
}
