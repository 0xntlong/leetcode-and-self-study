/**
3714. Longest Balanced Substring II
    You are given a string s consisting only of the characters 'a', 'b', and 'c'.
    A substring of s is called balanced if all distinct characters in the substring appear the same number of times.
    Return the length of the longest balanced substring of s.
    Example :
    Input: s = "abbac"
    Output: 4
    Explanation:
    The longest balanced substring is "abba" because both distinct characters 'a' and 'b' each appear exactly 2 times.
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestBalanced(string s) {
        int n = (int)s.size();
        int ans = 0;

        for (int i = 0; i < n; ) {
            int start = i;
            i++;
            while (i < n && s[i] == s[i - 1]) i++;
            ans = max(ans, i - start);
        }

        auto twoChars = [&](char x, char y) {
            int i = 0;
            vector<int> first(2 * n + 1, INT_MAX);
            vector<int> touched;
            touched.reserve(2 * n + 1);

            while (i < n) {
                int segStart = i;
                first[n] = segStart - 1;
                touched.push_back(n);

                int d = 0;
                while (i < n && (s[i] == x || s[i] == y)) {
                    d += (s[i] == x) ? 1 : -1;
                    int idx = d + n;
                    if (first[idx] != INT_MAX) {
                        ans = max(ans, i - first[idx]);
                    } else {
                        first[idx] = i;
                        touched.push_back(idx);
                    }
                    i++;
                }

                for (int idx : touched) 
                    first[idx] = INT_MAX;
                touched.clear();

                i++; 
            }
        };

        twoChars('a','b');
        twoChars('a','c');
        twoChars('b','c');

        unordered_map<long long, int> pos;
        pos.reserve(n * 2 + 1);

        auto key = [&](int d1, int d2) -> long long {
            return ( (long long)d1 << 32 ) ^ (unsigned int)d2;
        };

        int ca = 0, cb = 0, cc = 0;
        pos[key(0,0)] = -1;

        for (int i = 0; i < n; i++) {
            if (s[i] == 'a') 
                ca++;
            else if (s[i] == 'b') 
                cb++;
            else if (s[i] == 'c') 
                cc++;

            int d1 = ca - cb;
            int d2 = cb - cc;
            long long k = key(d1, d2);

            auto it = pos.find(k);
            if (it != pos.end()) 
                ans = max(ans, i - it->second);
            else pos[k] = i;
        }

        return ans;
    }
};