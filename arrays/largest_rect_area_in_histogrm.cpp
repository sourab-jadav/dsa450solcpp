#include <algorithm>
#include <functional>
#include <iostream>
#include <utility>
#include <vector>
#include <queue>
#include <stack>


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

/**
 * solution using stacks put first comes last
 * if we know the smaller element on it's left
 * and smaller element on it's right we can get the count
 * let's create two functions
 * one calculate prev smaller
 * another calculate next smaller
 */
void printarr(vector<int> arr) {
    for (auto val : arr) {
        cout << val << " ";
    }
    cout<<endl;
}
int sol3usingstacks(vector<int> &heights) {
    int n=heights.size();
    vector<int>ps(n,-1);
    vector<int>ns(n,-1);

    // [60, 20, 50, 40, 10, 50, 60]
    // get nearest bar on the left that is smaller than current
    // get nearest bar on the right that is smaller than current
    // we maintain a stack that keeps track of smaller element from left

    stack<int>stk;
    // we keep on popping out the elements from stack
    // until heights[stk.top()] <= heights[i]
    //
    // now that we have the element which is closest smaller on left
    // if stk is not empty do ps[i]=stk.top;
    //
    for (int i = 0; i < n; i++) {
        while (!stk.empty() && heights[stk.top()] > heights[i]) {
            stk.pop();
        }
        if (!stk.empty()) {
            ps[i]=stk.top();
        }
        stk.push(i);
    }
    while (!stk.empty()) {
        stk.pop();
    }

    // next smaller element
    // you are going from left to right
    // you arrive at an element which is smaller than the element
    // which you already visited
    // instead of complicating it can we traverse from right to left
    for (int i = n - 1; i >= 0; i--) {
        while (!stk.empty() && heights[stk.top()]> heights[i]) {
            stk.pop();
        }
        if (!stk.empty()) {
            ns[i]=stk.top();
        }
        stk.push(i);
    }
    int result{};
    printarr(ps);
    printarr(ns);
    for (int i = 0; i < n; i++) {
        int lc{},rc{};
        // exclude the current element when adding the lc and rc
        if (ps[i]==-1) {
            lc+=i-0;
        } else {
            lc+=i-1-ps[i];
        }
        if (ns[i]==-1) {
            rc+=n-1-i;
        }else{
            rc+=ns[i]-i-1;
        }
        cout << "for i = "<<i << " "<<lc+rc<<endl;

        result=max(result,(lc+rc+1)*heights[i]);
    }
    return result;
}

int main(int argc, char *argv[])
{
    // vector<int>vec= {60, 20, 50, 40, 10, 50, 60};//test case passed
    // vector<int>heights={3,5,1,7,5,9};
    // vector<int>heights={2,1,5,6,2,3}; // passed
    vector<int>heights={1,1}; //failed
    // cout << sol2usingfor_loop(heights) << "\n";
    cout<<sol3usingstacks(heights);





    return 0;
}
