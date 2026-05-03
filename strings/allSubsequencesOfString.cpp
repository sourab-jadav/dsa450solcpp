#include <iostream>
using namespace std;

void method1(string &str, string &curr, int i) {
    if (i == str.size()) {
        if (curr == "") {
            cout << "empty"
                 << "\n";
        }
        cout << curr << " ";

        return;
    }
    method1(str, curr += str[i], i + 1);
    curr = curr.substr(0, curr.size() - 1);
    method1(str, curr, i + 1);
}
int main(int argc, char *argv[]) {
    string str = "geeks";
    string curr = "";
    method1(str, curr, 0);
    return 0;
}
