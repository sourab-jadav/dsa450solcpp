#include <iostream>
#include <vector>
using namespace std;

/**
 * the question is given an array
 * you need to merge[sum the left end or rightend] element
 * with it's adjacent element so that the array becomes palindrome
 *
 */
int main(int argc, char *argv[])
{
    // vector<int>vec{6, 1, 4, 3};
    vector<int>vec{11, 14, 15, 99};
    int n=vec.size();
    // left end is 3
    // right end is 4
    // since it does not match we merge smaller one with it's adj
    int i=0;
    int j=n-1;
    int mrg_cnt{};
    while (i<j) {
        if (vec[j]<vec[i]) {
            vec[j-1]=vec[j]+vec[j-1];
            mrg_cnt++;
            j--;
        }else if (vec[i]<vec[j]) {
            vec[i+1]=vec[i]+vec[i+1];
            mrg_cnt++;
            i++;
        }else {
            i++;
            j--;
        }
    }
    cout << mrg_cnt << "\n";

    return 0;
}
