#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;

// Bishu went to fight for Coding Club. There were N soldiers with
// various powers. There will be Q rounds to fight and in each round,
// Bishu's power will be varied. With power M, Bishu can kill all the
// soldiers whose power is less than or equal to M(<=M). After each
// round, All the soldiers who are dead in the previous round will
// reborn. Such that in each round there will be N soldiers to
// fight. As Bishu is weak in mathematics, help him to count the
// number of soldiers that he can kill in each round and the total sum
// of their powers.

// N soldiers
// Q rounds
// with power M can kill all whose power <=M



// The first line of the input contains N, the number of soldiers.

// The second line contains an array of N numbers denoting the power of each soldier

// This third line contains Q, which denotes the number of rounds.

// Q lines follow, each line having one number denoting the power of Bishu.

// sample input
// 7
// 1 2 3 4 5 6 7
// 3
// 3
// 10
// 2

// sample output
// 3 6
// 7 28
// 2 3

// output
// There are 7 soldiers, each with the indicated power.

// There are 3 rounds.

// In the first round, Bishu's power is 3, which is greater than 3 soldiers, with the cumulative power of 6. Hence, the answer is 3 6

// Similarly for the next round.

void solve(){
    int num{};
    cin>>num;
    vector<int>vec;
    for(int i=0;i<num;i++){
        int x;
        cin>>x;
        vec.push_back(x);
    }
    sort(vec.begin(),vec.end());
    int rounds{};
    cin>>rounds;
    for(int i=0;i<rounds;i++){
        int bpower={};
        cin>>bpower;
        int count{};
        int cp{};

        int j{};
        while (j<num && vec[j]<=bpower) {
            cp+=vec[j];
            count++;
            j++;
        }
        cout << count<<" "<<cp << "\n";

    }

}
int main(int argc, char *argv[])
{

    solve();

    return 0;
}
