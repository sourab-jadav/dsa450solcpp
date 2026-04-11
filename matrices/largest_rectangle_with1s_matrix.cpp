#include <iostream>
#include <vector>
using namespace std;

/**
 * how do we select the base
 *   the tricky part here is
 *   traverse through each row considering it as a base create a heights
 *   array
 *   now if a cell in base has value 0 then then that column cannot be
 *   considered to form a rectangle
 *
 *   after creating the heights array for each row call the
 *   largest rectangle in histogram passing this heights array
 */

int main(int argc, char *argv[])
{
    vector<vector<int>>vec= {{0, 1, 1, 0},
                             {1, 1, 1, 1},
                             {1, 1, 1, 1},
                             {1, 1, 0, 0}};

    int m=vec.size();
    int n=vec[0].size();



    return 0;
}
