/**
2976. Minimum Cost to Convert String I
    You are given two 0-indexed strings source and target, both of length n and consisting of lowercase English letters. You are also given two 0-indexed character arrays original and changed, and an integer array cost, where cost[i] represents the cost of changing the character original[i] to the character changed[i].
    You start with the string source. In one operation, you can pick a character x from the string and change it to the character y at a cost of z if there exists any index j such that cost[j] == z, original[j] == x, and changed[j] == y.
    Return the minimum cost to convert the string source to the string target using any number of operations. If it is impossible to convert source to target, return -1.
    Note that there may exist indices i, j such that original[j] == original[i] and changed[j] == changed[i].

    Example :
    Input: source = "abcd", target = "acbe", original = ["a","b","c","c","e","d"], changed = ["b","c","b","e","b","e"], cost = [2,5,5,1,2,20]
    Output: 28
    Explanation: To convert the string "abcd" to string "acbe":
    - Change value at index 1 from 'b' to 'c' at a cost of 5.
    - Change value at index 2 from 'c' to 'e' at a cost of 1.
    - Change value at index 2 from 'e' to 'b' at a cost of 2.
    - Change value at index 3 from 'd' to 'e' at a cost of 20.
    The total cost incurred is 5 + 1 + 2 + 20 = 28.
    It can be shown that this is the minimum possible cost.

*/

#include <vector>
#include <string>
#include <queue>
using namespace std;

class Solution {
public:
    using ll = long long;
    ll INF = (1LL << 25);
    vector<ll> dijkstra(int start, vector<vector<pair<int, int>>> & graph){
        vector<ll> dist(26, INF);
        dist[start] = 0;
        priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<>> pq;
        pq.push({0, start});
        while (!pq.empty()){
            auto [d, u] = pq.top();
            pq.pop();
            if (d > dist[u])
                continue;
            for (auto &[v, w] : graph[u]){
                ll nd = d + w;
                if (nd < dist[v]){
                    dist[v] = nd;
                    pq.push({nd, v});
                }
            }
        }
        return dist;
    }
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        vector<vector<pair<int, int>>> graph(26);
        for (int i = 0; i < original.size(); i++){
            graph[original[i] - 'a'].push_back({changed[i] - 'a', cost[i]});
        }
        vector<vector<ll>> compute(26);
        for (int i = 0; i < 26; i++){
            compute[i] = dijkstra(i, graph);
        }
        ll total = 0;
        for (int i = 0; i < source.size(); i++){
            int s = source[i] - 'a';
            int t = target[i] - 'a';
            if (compute[s][t] >= INF)
                return -1;
            total += compute[s][t];
        }
        return total;
    }
};