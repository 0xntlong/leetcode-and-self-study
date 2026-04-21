/**
1722. Minimize Hamming Distance After Swap Operations
    You are given two integer arrays, source and target, both of length n. You are also given an array allowedSwaps where each allowedSwaps[i] = [ai, bi] indicates that you are allowed to swap the elements at index ai and index bi (0-indexed) of array source. Note that you can swap elements at a specific pair of indices multiple times and in any order.
    The Hamming distance of two arrays of the same length, source and target, is the number of positions where the elements are different. Formally, it is the number of indices i for 0 <= i <= n-1 where source[i] != target[i] (0-indexed).
    Return the minimum Hamming distance of source and target after performing any amount of swap operations on array source.

    Example :
    Input: source = [1,2,3,4], target = [2,1,4,5], allowedSwaps = [[0,1],[2,3]]
    Output: 1
    Explanation: source can be transformed the following way:
    - Swap indices 0 and 1: source = [2,1,3,4]
    - Swap indices 2 and 3: source = [2,1,4,3]
    The Hamming distance of source and target is 1 as they differ in 1 position: index 3.
 */

#include <vector>
#include <unordered_map>
#include <functional>
using namespace std;

class Solution {
public:
    int minimumHammingDistance(vector<int>& source, vector<int>& target, vector<vector<int>>& allowedSwaps) {
        int n = source.size();
        vector<int> parent(n), rank(n, 0);
        for (int i = 0; i < n; i++) 
            parent[i] = i;

        function<int(int)> find = [&](int x) {
            if (parent[x] != x)
                parent[x] = find(parent[x]);
            return parent[x];

        };
        auto uni = [&](int a, int b) {
            int fa = find(a), fb = find(b);
            if (fa == fb) 
                return;

            if (rank[fa] < rank[fb]) 
                swap(fa, fb);

            parent[fb] = fa;
            if (rank[fa] == rank[fb])
                rank[fa]++;
        };

        for (auto& p : allowedSwaps) {
            uni(p[0], p[1]);
        }

        unordered_map<int, vector<int>> groups;

        for (int i = 0; i < n; i++) {
            groups[find(i)].push_back(i);
        }

        int ans = 0;
        for (auto& [_, idxs] : groups) {
            unordered_map<int, int> freq;
            for (int i : idxs) {
                freq[source[i]]++;
            }

            for (int i : idxs) {
                if (freq[target[i]] > 0) {
                    freq[target[i]]--;
                } else {
                    ans++;
                }
            }

        }
        return ans;
    }
};