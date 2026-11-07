#include <iostream>
#include <utility>
#include <vector>
#include <unordered_map>
#include <queue>
using namespace std;
/**inventory management system

given an array of product id's
[101,204,101,105]

and changes in to each product
[4,2,-4,3]

we want to written an array which keeps track of
latest max available stock of particular item
from left to right
 */

vector<int> solution(vector<int> products, vector<int> changes) {
  vector<int> result;
  // to keep track of max_stock of a type available let's matain a max heap
  // with first item being the stock value and second item being stock id

  // we might also need a unordered_map with each element mapping to it's value
  unordered_map<int, int> stock;
  int n=products.size();

  priority_queue<pair<int, int>> max_heap;
  result.reserve(n);

  for(int i=0;i<n;i++){
    int prod = products[i];
    int change = changes[i];
    int current_qty = stock[prod] + change;
    stock[prod] = current_qty;

    max_heap.push({current_qty, prod});

    // now by push for every index we are also pushing into the max heap
    // old changes
    // lazy deletion removing stale entries ,entries who's max value is no longer valid
    while (!max_heap.empty()) {
      auto [top_qty, top_prod] = max_heap.top();
      if(stock[top_prod]!=top_qty){
          max_heap.pop();
      } else {
          break;
      }
    }
    if (max_heap.empty()) {
        result.push_back(0);
    } else {
        result.push_back(max_heap.top().first);
    }
  }
  return result;

}


int main() {
    vector<int>products ={101,204,101,105};
    vector<int>changes ={4,2,-4,3};
    vector<int> result = solution(products, changes);
    for (auto x : result) {
        cout << x << "\n";

            }


}
