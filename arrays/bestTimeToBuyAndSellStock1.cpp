#include <iostream>

using namespace std;

int main() {
  int arr[]{7, 1, 5, 3, 6, 4};
  int n = sizeof(arr) / sizeof(arr[0]);

  // the task is to maximize the profit
  // by choosing a single day to buy one stock
  // and choosing a different day in the future to sell the stock
  int max_profit{};
  for (int i = 0; i < n - 1; i++) {
    if (arr[i] < arr[i + 1]) {
      max_profit += (arr[i + 1] - arr[i]);
      cout<<arr[i]<<" "<<arr[i+1]<<endl;
      }
  }
  cout<<max_profit;  
  return 0;  
}
