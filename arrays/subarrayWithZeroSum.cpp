#include <iostream>
#include <vector>
#include <unordered_set>


using namespace std;

/**
 * find if there is a subarray with zero sum
 *
 */
int main(int argc, char *argv[])
{
    unordered_set<int> s;
    int sum {};
    std::vector<int> arr = {4,2, -3, 1, 6};
    bool flag=false;
    for (auto it = arr.begin(); it != arr.end(); ++it) {
        sum += *it;
        if (s.find(sum)!=s.end()) {
            cout << "true"
                 << "\n";
            flag=true;
            break;
        }
        s.insert(sum);
    }
    if (!flag) {
        cout<<"false"<<endl;
    }

    return 0;
}
