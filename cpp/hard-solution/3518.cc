/**
3518. Smallest Palindromic Rearrangement II
    You are given a palindromic string s and an integer k.
    Return the k-th lexicographically smallest palindromic permutation of s. If there are fewer than k distinct palindromic permutations, return an empty string.
    Note: Different rearrangements that yield the same palindromic string are considered identical and are counted once.
    
    Example:
    Input: s = "abba", k = 2
    Output: "baab"
    Explanation:
    The two distinct palindromic rearrangements of "abba" are "abba" and "baab".
    Lexicographically, "abba" comes before "baab". Since k = 2, the output is "baab".

 */


#include <vector>
#include <string>
using namespace std;

constexpr int INF = 1e6 + 1, N = 24;
int C[N][N] = {{0}};

constexpr void Pascal() {
    if (C[0][0] == 1) 
        return;
    C[0][0] = 1;
    for (int i = 1; i < N; i++) {
        C[i][0] = C[i][i] = 1;
        for (int j = 1; j <= i / 2; j++) {
            C[i][j] = C[i][i - j] = C[i - 1][j - 1] + C[i - 1][j];
        }
    }
}

class Solution {
public:
    static int comb(int n, int k) {
        if (n < N && k < N) 
            return C[n][k];
        if (2 * k > n) k = n - k;
        int64_t ans = 1;
        for (int i = 1; i <= k; i++) {
            ans = ans * (n - i + 1) / i;
            if (ans >= INF) 
                return INF;
        }
        return ans;
    }

    static int perm(const vector<int>& count, int sz) {
        int64_t ans = 1;
        for (int c : count) {
            if (c == 0) 
                continue;
            ans *= comb(sz, c);
            if (ans >= INF) 
                return INF;
            sz -= c;
        }
        return ans;
    }

    string smallestPalindrome(string S, long long K) {
        Pascal();
        int n = S.length();
        string ans(n, ' ');

        map<char, int> countMap;
        for (int i = 0; i < n / 2; ++i) {
            countMap[S[i]]++;
        }

        if (n & 1) {
            ans[n / 2] = S[n / 2];
        }

        
        vector<char> keys_asc;
        for (auto const& [c, val] : countMap) 
            keys_asc.push_back(c);
        
        vector<int> count(26, 0);
        for (auto const& [c, val] : countMap) {
            count[c - 'a'] = val;
        }

        int n0 = n / 2;
        int total = perm(count, n0);
        if (K > total) 
            return "";

        int index = 0;
        int sz = n0;

        for (int i = 0; i < n0; ++i) {
            bool placed = false;
            for (char c : keys_asc) {
                int idx = c - 'a';
                if (count[idx] == 0) 
                    continue;

                count[idx]--;
                sz--;
                int cnt = perm(count, sz);

                if (cnt >= K) {
                    ans[index] = ans[n - 1 - index] = c;
                    index++;
                    placed = true;
                    break;
                } else {
                    K -= cnt;
                    count[idx]++;
                    sz++;
                }
            }
            if (!placed) 
                break;
        }

        return ans;
    }
};

