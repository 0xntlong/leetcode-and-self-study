/*
1128. Number of Equivalent Domino Pairs
    Given a list of dominoes, dominoes[i] = [a, b] is equivalent to dominoes[j] = [c, d] if and only if either (a == c and b == d), or (a == d and b == c) - that is, one domino can be rotated to be equal to another domino.
    Return the number of pairs (i, j) for which 0 <= i < j < dominoes.length, and dominoes[i] is equivalent to dominoes[j].

    Example :
    Input: dominoes = [[1,2],[2,1],[3,4],[5,6]]
    Output: 1
*/


#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
    public:
        int numEquivDominoPairs(vector<vector<int>>& dominoes) {
            unordered_map<int, int> counter;
            for (auto& domino : dominoes){
                int equi = min(domino[0], domino[1]) * 10 + max(domino[0], domino[1]);
                counter[equi]++;
            }
            int res = 0;
            for (auto& entry : counter){
                int count = entry.second;
                res += count * (count - 1) / 2;
            }
            return res;
        }
    };