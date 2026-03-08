#include <iostream>
#include <iterator>
#include <vector>


using namespace std;

int main(int argc, char *argv[])
{

    std::vector<int> arr{-5, -2, 5, 2, 4, 7, 1, 8, 0, -8};
    /**
     * the task is to arrange these numbers in alternative pos
     * and negative manner.
     *
     * the rearranged array should start with a positive number
     * and 0 should be considered as postive
     */

    // logic ////////////////////////////////////////////////////////////////////
    /**
     * maintain two pointers p1 o(n) time and o(n) space
     * maintain two vector's
     * one stores pos elements
     * other stores neg elements
     *
     */
    std::vector<int> pos,neg;
    for (auto it = arr.begin(); it != arr.end(); ++it) {
        if (*it>=0) {
            pos.push_back(*it);
        }else {
            neg.push_back(*it);
        }
    }
    for (auto it = pos.begin(); it != pos.end(); ++it) {
        cout << *it << " ";
    }

    for (auto it = neg.begin(); it != neg.end(); ++it) {
        cout << *it << " ";
    }

    int i{}, j{}, k{}; // or you can do int i=0,j=0;
    arr.clear();
    while (i < pos.size() && j < neg.size()) {
        if (k % 2 == 0) {
            arr.push_back(pos[i++]);
            k++;
        }else {
            arr.push_back(neg[j++]);
            k++;
        }
    }
    while (i<pos.size()) {
        arr.push_back(pos[i++]);
        k++;
    }
    while (j<neg.size()) {
        arr.push_back(neg[j++]);
        k++;
    }
    cout<<endl;
    for (auto it = arr.begin(); it != arr.end(); ++it) {
        cout << *it << " ";
    }
    cout<<endl;

    return 0;
}
