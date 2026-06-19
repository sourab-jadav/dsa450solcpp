#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{

    int n=10;
    int i=1;
    int count=0;
    while (i*i<n) {
        count++;
        i++;
    }
    cout << count << "\n";




    return 0;
}
