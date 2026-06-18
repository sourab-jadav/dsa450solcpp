#include <iostream>
#include <string>
#include <vector>

using namespace std;
int count{};
void printSentences(vector<vector<string>> &l,string curr,int i) {
    if (i==l.size()) {
        cout << curr << "\n";
        return;
    }

        for (auto str : l[i]) {
            printSentences(l, curr+str+" ", i+1 );

        }

}
int main(int argc, char *argv[])
{
    cout << "word list sentences problem " << "\n";
     vector<vector<string>>l{{"you", "we"},
        {"have", "are"},
            {"sleep", "eat", "drink"}};

     printSentences(l, "", 0);


    return 0;
}
