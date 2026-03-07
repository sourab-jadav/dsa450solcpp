#include <algorithm>
#include <iostream>
#include <iterator>
#include <type_traits>
/**
   next permutation or you can say finding next greater number
   // this example cleared me how to think
   9 8 7 6
   9 7 8 6 3 8 4 2 5

   // think if all the numbers are in decreasing order then next
number cannot be found using the existing number of digits

   // next number can only be found if there is an ascending pattern
   9 7 8 6 3 8 4 2 5
   9 7 8 6 3 8 4 5 3 2  --> if we start from right here there is asc
   pattern at 4 5

             8 4 6 5 3 2  --> asc at 4 6
             (look for the num just above 4 - here it is 5)

             (swap 4 with 5)
             8 5 6 4 3 2 ( after the swap point(4) )
             all the numbers after 5 will be in desc
             to make it smallest reverse the array after 5
   
 */
using namespace std;
void reverse(int arr[], int low, int high) {
        while (low<high) {
            swap(arr[low], arr[high]);
            low++;
            high--;            
        }
}
void printArray(int arr[], int n) {
    cout<<"array elements"<<endl;
    for (int i = 0; i < n; i++) {
        cout<<arr[i]<<" "    ;
    }
    cout<<endl;
        
}
int main() {
    int arr[]{9, 7, 8, 6, 3, 8, 4, 2, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    printArray(arr, n);
    // find index i from the left where asc starts
    int i;    
    for ( i=n-2; i>=0; i--) {
        if (arr[i]<arr[i+1]) {
            break;
        }
    }
    cout<<"i value is "<<i<<endl;
    if (i < 0) {
        reverse(arr, 0, n-1);
    }else {
        for (int j = n - 1; j >= 0; j--) {
            if (arr[j] > arr[i]) {
              swap(arr[j], arr[i]);
              cout << "values after swap" << endl;
              reverse(arr, i + 1, n - 1);
              break;
            }
        }
    }
    printArray(arr, n);

    return 0;  
}
