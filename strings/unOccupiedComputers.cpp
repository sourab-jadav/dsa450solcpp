#include <iostream>
#include <vector>

using namespace std;
int runCustomerSimulation(int n, string s) {


    // you are given n which tells the number of computer's available
    // seq string telling no. seq of customer comming from from left to right
    // first occurence of char represents the entering the shop
    // second occurence of char represents the exiting the shop
    //
    // if all the computers are utlised then incoming customer will have to wait
    //
    int m=s.length();
    int customers[26]{};
    int waiting[26]{};
    int res{};
    for (int i = 0; i < m; i++) {
        int count=++customers[s[i]-'A'];
        if (count==1) {
            if (n>0) {
                n--;
            } else {
                waiting[s[i]-'A']=1;
            }
        }else{
            // the customer is now going
            // it has not utilised the computers
            if (waiting[s[i]-'A']) {
                res++;
                waiting[s[i]-'A']=0;
            }else{
                n++;

            }
            customers[s[i]-'A']=0;
        }
    }
    return res;
}
int main(int argc, char *argv[])
{
    string seq="ABCBCADEED";
    int noOfComputers=1;
    cout<<runCustomerSimulation(noOfComputers, seq);

    return 0;
}
