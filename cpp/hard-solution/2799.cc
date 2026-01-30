/**
2977. Minimum Cost to Convert String II
    You are given two 0-indexed strings source and target, both of length n and consisting of lowercase English characters. You are also given two 0-indexed string arrays original and changed, and an integer array cost, where cost[i] represents the cost of converting the string original[i] to the string changed[i].
    You start with the string source. In one operation, you can pick a substring x from the string, and change it to y at a cost of z if there exists any index j such that cost[j] == z, original[j] == x, and changed[j] == y. You are allowed to do any number of operations, but any pair of operations must satisfy either of these two conditions:
    The substrings picked in the operations are source[a..b] and source[c..d] with either b < c or d < a. In other words, the indices picked in both operations are disjoint.
    The substrings picked in the operations are source[a..b] and source[c..d] with a == c and b == d. In other words, the indices picked in both operations are identical.
    Return the minimum cost to convert the string source to the string target using any number of operations. If it is impossible to convert source to target, return -1.
    Note that there may exist indices i, j such that original[j] == original[i] and changed[j] == changed[i].

    Example :

    Input: source = "abcd", target = "acbe", original = ["a","b","c","c","e","d"], changed = ["b","c","b","e","b","e"], cost = [2,5,5,1,2,20]
    Output: 28
    Explanation: To convert "abcd" to "acbe", do the following operations:
    - Change substring source[1..1] from "b" to "c" at a cost of 5.
    - Change substring source[2..2] from "c" to "e" at a cost of 1.
    - Change substring source[2..2] from "e" to "b" at a cost of 2.
    - Change substring source[3..3] from "d" to "e" at a cost of 20.
    The total cost incurred is 5 + 1 + 2 + 20 = 28. 
    It can be shown that this is the minimum possible cost.
 */


#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <climits>
using namespace std;

class Solution {
public:
    long long minimumCost(string source, string target, vector<string>& original, vector<string>& changed, vector<int>& cost) {
        unordered_map<string, int> idx;
        int cnt = 0;
        for (auto &s : original)
            if (!idx.count(s)) 
                idx[s] = cnt++;
        for (auto &s : changed)
            if (!idx.count(s)) 
                idx[s] = cnt++;

        const long long INF = LLONG_MAX / 4;
        vector<vector<long long>> dist(cnt, vector<long long>(cnt, INF));

        for (int i = 0; i < cnt; i++) 
            dist[i][i] = 0;

        for (int i = 0; i < original.size(); i++) {
            int u = idx[original[i]];
            int v = idx[changed[i]];
            dist[u][v] = min(dist[u][v], (long long)cost[i]);
        }

        for (int k = 0; k < cnt; k++)
            for (int i = 0; i < cnt; i++)
                if (dist[i][k] < INF)
                    for (int j = 0; j < cnt; j++)
                        if (dist[k][j] < INF)
                            dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);

        int n = source.size();
        vector<long long> dp(n + 1, INF);
        dp[n] = 0;
        unordered_set<int> lens;
        for (auto &s : original) 
            lens.insert(s.size());

        for (int i = n - 1; i >= 0; i--) {
            if (source[i] == target[i])
                dp[i] = dp[i + 1];

            for (int L : lens) {
                if (i + L > n) 
                    continue;
                string s1 = source.substr(i, L);
                string s2 = target.substr(i, L);
                if (idx.count(s1) && idx.count(s2)) {
                    int u = idx[s1], v = idx[s2];
                    if (dist[u][v] < INF && dp[i + L] < INF)
                        dp[i] = min(dp[i], dist[u][v] + dp[i + L]);
                }
            }
        }
        return dp[0] == INF ? -1 : dp[0];
    }
};