
#include <algorithm>
#include <iostream>
#include <utility>
#include <vector>

using namespace std;

int main() {
  vector<pair<int, int>> intervals = {{1, 3}, {2, 6}, {15, 18}, {8, 10}};

  // if we can sort the intervals based on their start value
  // once that is sorted
  // we start with index 1 see if it's start value is less than
  // previous intervals end value
  //   if it is less than for the previous value end we pick the
  //   max(currentinterval_end,previous_interval_end)

  int n = intervals.size();
  sort(
      intervals.begin(), intervals.end(),
      [](pair<int, int> p1, pair<int, int> p2) { return p2.first > p1.first; });


  vector<pair<int, int>> result;
  result.push_back(intervals[0]);

  for(int i=1;i<n;i++){

    pair<int, int>& last = result.back();
    pair<int, int>& curr = intervals[i];

    if (curr.first <= last.second) {
      last.second = max(curr.second, last.second);
    } else {
        result.push_back(curr);
    }
}  
  


}
