#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
#include <climits>




using namespace std;

string bruteForceSolution(string &s, string &p) {
    int n = s.length();
    int m = p.length();
    string result = s;
    unordered_map<char, int> freq;
    for (int i = 0; i < m; i++) {
        freq[p[i] - 'a']++;
    }

    for (int i = 0; i < n - m; i++) {
        if (freq[s[i] - 'a'] > 0) {
            unordered_map<char, int> t = freq;
            t[s[i] - 'a']--;
            int length = 1;
            for (int j = i + 1; j < n; j++) {
                if (t[s[j] - 'a'] > 0) {
                    t[s[j] - 'a']--;
                    length++;
                    if (length == m && result.length() > j - i + 1) {
                        result = s.substr(i, j - i + 1);
                        break;
                    }
                }
            }
        }
    }
    if (result == s) {
        return "";
    } else {
        return result;
    }
}

/**
 * the idea is to
 * maintain two pointers left and right
 * left -> to converge the window
 * right -> to expand the window
 *
 * how do we expand using right?
 * we make use of map s_freq<char,int> and p_freq[];
 * 1.construct the p_preq prior
 * 2.if p_freq of char c at i is > 0
 *     s_freq[c]++
 *     if s_freq[c] <= p_freq[c-'a']
 *         length++;
 *   right++;
 * 3. while length==m
 *     update the min_length
 *     update start index value to left
 *     if the index at left is part of pattern
 *         do s_freq[c-'a']--;
 *         if the s_freq < p_freq[c-'a']
 *             do length--;
 *
 */
string usingTwoPointers(string &s, string &p) {
    int n=s.length();
    int m=p.length();

    int left=0;
    int right=0;
    int length=0;               // this we need to increase and decrease
    int s_freq[26]{};
    int p_freq[26]{};
    int min_len=INT_MAX;
    int start_index=-1;
    for (auto v : p) {
        p_freq[v-'a']++;
    }
    // we have p freq set
    while (right<n) {
        // moving the right pointer
        if (p_freq[s[right]-'a']>0) {
            // char at index right is part of pattern
            s_freq[s[right]-'a']++;
            if (s_freq[s[right]-'a']<=p_freq[s[right]-'a']) {
                length++;
            }

        }
        right++;
        while (length==m) {
            char c = s[left];

            if (right-left<min_len) {
                min_len=right-left;
                start_index=left;
            }
            if (p_freq[s[left]-'a']>0) {
                s_freq[c-'a']--;
                if (s_freq[c-'a']<p_freq[c-'a']) {
                    length--;
                }
            }
            left++;
        }
    }
    return (start_index==-1)?"":s.substr(start_index,min_len);
}

int main(int argc, char *argv[]) {
    string s="zoom";
    string p="zooe";

    cout<<usingTwoPointers(s, p);
}
