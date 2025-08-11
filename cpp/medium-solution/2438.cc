/**
2438. Range Product Queries of Powers
    Given a positive integer n, there exists a 0-indexed array called powers, composed of the minimum number of powers of 2 that sum to n. The array is sorted in non-decreasing order, and there is only one way to form the array.
    You are also given a 0-indexed 2D integer array queries, where queries[i] = [lefti, righti]. Each queries[i] represents a query where you have to find the product of all powers[j] with lefti <= j <= righti.
    Return an array answers, equal in length to queries, where answers[i] is the answer to the ith query. Since the answer to the ith query may be too large, each answers[i] should be returned modulo 109 + 7.

    Example :
    Input: n = 15, queries = [[0,1],[2,2],[0,3]]
    Output: [2,4,64]
    Explanation:
    For n = 15, powers = [1,2,4,8]. It can be shown that powers cannot be a smaller size.
    Answer to 1st query: powers[0] * powers[1] = 1 * 2 = 2.
    Answer to 2nd query: powers[2] = 4.
    Answer to 3rd query: powers[0] * powers[1] * powers[2] * powers[3] = 1 * 2 * 4 * 8 = 64.
    Each answer modulo 109 + 7 yields the same answer, so [2,4,64] is returned.
 */

#include <vector>
using namespace std;

class Solution {
public:
    vector<int> productQueries(int n, vector<vector<int>>& queries) {
        const int mod = 1e9 + 7;
        int power = 1;
        while (power <= n)
            power <<= 1;
        power >>= 1;
        vector<int> parts;
        int m = n;
        while (m > 0){
            if (power <= m){
                parts.push_back(power);
                m -= power;
            }
            power >>= 1;
        }
        int k = (int)parts.size();
        vector<vector<int>> prefix(k, vector<int>(k, 0));
        for (int i = 0; i < k; i++){
            prefix[i][i] = parts[k - 1 - i];
            for (int j = i + 1; j < k; j++){
                long long prod = 1LL * prefix[i][j - 1] * parts[k - 1 - j];
                prefix[i][j] = (int)(prod % mod);
            }
        }
        vector<int> res;
        res.reserve(queries.size());
        for (auto &q : queries){
            res.push_back(prefix[q[0]][q[1]]);
        }
        return res;
    }
};