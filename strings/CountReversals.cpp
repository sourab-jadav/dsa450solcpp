#include <iostream>
#include <stack>
#include <unordered_map>

using namespace std;

// this solution is based on the check balancedParanthesis problem
// we only have to worry about single bracket {
// if initially } appears we count and push { to staack
// now if } appears
// we check if the stack is not empty then we pop the top value
// if stack is empty then we push { to the stack
//

int countMinreversals(string s) {
    int n = s.length();
    if (n % 2 != 0) {
        return -1;
    }
    stack<char> stk;
    int res{};
    for (int i = 0; i < n; i++) {
        if (s[i] == '}') {
            if (stk.empty()) {
                stk.push('{');
                cout << "res inc at " << i << "\n";
                res++;
            } else {
                stk.pop();
            }
        } else { // here value is '{'

            stk.push('{');
        }
    }
    res += stk.size() / 2;
    cout << res << "\n";
    return res;
}

int main(int argc, char *argv[]) {
    cout << "minimum no. of reversals required to balance the expression"
         << "\n";
    // rules are these
    // first cannot be a closing bracket if it is just flip it

    // if s.length is odd we return -1;
    string s = "}{{}}{{{";
    countMinreversals(s);
    return 0;
}
