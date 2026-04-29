#include <iostream>
using namespace std;


/**
 * method1:
 * check if one string is a valid shuffle of two other strings
 * 1 condiation can be
 * len of result= len of first+ len of second;
 *
 *
 */
bool method1(string &s1,string &s2,string &result){
    if (result.size()==(s1.size()+s2.size())) {
        return false;
    }
    // on strings you can do
    // concatination
    // sorting
    // converting string to char array
    // converting char array back to string
    //
    // sort s1 s2 annd result string
    //
    //  apply three pointer approach
    //  if something that is found in s1 but not in result we return false

  }
int main(int argc, char *argv[])
{
    cout << "this is the world we live in" << "\n";

    return 0;
}
