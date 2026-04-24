#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;
/**
 * each row and column is sorted in non-decreasing order
 * find kth smallest element in the matrix
 *
 * it is sorted row-wise and column wise
 *     means value at 0,0 is least and value at n-1,n-1 is max
 *
 * from 0,0 you can go to 0,1 1,1, 1,0
 * second least value will be between 0,1 and 1,0
 *
 *
 */
int main(int argc, char *argv[])
{
  // vector<vector<int>> mat {
  //     {10,20,30,40},
  //     {15,25,35,45},
  //     {24,29,37,48},
  //     {32,33,39,50}
  // };

  // vector<vector<int>>mat {{16, 28, 60, 64},
  //                         {22, 41, 63, 91},
  //                         {27, 50, 87, 93},
  //                         {36, 78, 87, 94}};

  vector<vector<int>>mat{{10, 20, 30, 40},
                         {15, 25, 35, 45},
                          {24, 29, 37, 48},
                          {32, 33, 39, 50}};
  int hr=0;
  int hc=1;
  int vr=1;
  int vc=0;
  int count=1;
  int rq=7;
  int smallest=mat[0][0];
  if (rq==1) {
      cout<<mat[0][0]<<endl;
  }
  while (count<rq) {
      if (mat[vr][vc]<mat[hr][hc]) {
          smallest=mat[vr][vc];
          cout << "vr vc value is at "<< vr<< vc << "\n";
          if (mat[vr+1][vc]<mat[vr][vc+1]) {
              vr=vr+1;
          }else {
              vc=vc+1;
          }


      } else {
          cout << "hr hc value is at "<<hr<<hc << "\n";
          smallest=mat[hr][hc];
          if (mat[hr+1][hc]<mat[hr][hc+1]) {
              hr=hr+1;
          } else {
              hc=hc+1;
          }

      }
      if (++count==rq) {
          cout<<"smallest is "<<smallest<<endl;
          break;
      }
  }



    return 0;
}
