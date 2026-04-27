#include <iostream>

using namespace std;

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

int main(int argc, char *argv[]) {


    return 0;
}
