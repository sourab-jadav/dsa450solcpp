#include <algorithm>
#include <functional>
#include <iostream>
#include <utility>
#include <vector>
#include <queue>


using namespace std;
/**
 *
 * given an array of heights
 * we need to find largest rectuangular area possible
 * the rectangle must be formed using contigous bars
 *
 *
 */

/**
 * one working idea is to
 * create a minheap mapping each element with it's index
 * sort the map values based on their key's increasing order
 * take each key associated index and traverse contigously
 * towards left and right until the condition arr[i] <= key is matched
 * count the pillars which satisfies the condition
 * get the max value of (count*key) for each element
 */
int sol1usingmin_heap(vector<int>&heights){
    int n=heights.size();
/**
 * the inbuilt version of minheap in c++ is priority_queue
 * by default it's a max heap to turn it into minheap you have to provide
 * three template literals
 */
    priority_queue<pair<int, int>,vector<pair<int, int>>,greater<pair<int, int>>>minheap;

    for (int i=0; i<n; i++) {
        minheap.push(make_pair(heights[i], i));
            }
    int result{};
    while (!minheap.empty()) {
        pair<int, int>p=minheap.top();
        int value=p.first;
        int index=p.second;
        int k=index;
        int current{};
        while (k<n) {
            if (heights[k]>=value) {
                current+=value;
            }else {
                break;
            }
            k++;
        }
        k=index-1;
        while (k>=0) {
            if (heights[k]>=value) {
                current+=value;
            }else {
                break;
            }
            k--;
        }
        result=max(result,current);
        minheap.pop();
    }
    return result;
}


/**
 * another solution would be
 * for each element move towards it's left and right
 * and calculate the max key*count
 */
int sol2usingfor_loop(vector<int> &heights) {
    int n=heights.size();
    int result{};
    for (int i = 0; i < n; i++) {
        int val=heights[i];
        int j=i-1;
        int count =1;
        while (j>=0 && heights[j]>=val) {
            j--;
            count++;
        }
        j=i+1;
        while (j<n && heights[j]>=val) {
            j++;
            count++;
        }
        result=max(result,val*count);
    }
    return result;
}


int main(int argc, char *argv[])
{
    // vector<int>vec= {60, 20, 50, 40, 10, 50, 60};//test case passed
    vector<int>heights={3,5,1,7,5,9};
    cout << sol2usingfor_loop(heights) << "\n";



    return 0;
}
