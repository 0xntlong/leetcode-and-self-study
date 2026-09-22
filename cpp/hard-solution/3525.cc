/**
3525. Find X Value of Array II
    You are given an array of positive integers nums and a positive integer k. You are also given a 2D array queries, where queries[i] = [indexi, valuei, starti, xi].
    You are allowed to perform an operation once on nums, where you can remove any suffix from nums such that nums remains non-empty.
    The x-value of nums for a given x is defined as the number of ways to perform this operation so that the product of the remaining elements leaves a remainder of x modulo k.
    For each query in queries you need to determine the x-value of nums for xi after performing the following actions:
    Update nums[indexi] to valuei. Only this step persists for the rest of the queries.
    Remove the prefix nums[0..(starti - 1)] (where nums[0..(-1)] will be used to represent the empty prefix).
    Return an array result of size queries.length where result[i] is the answer for the ith query.
    A prefix of an array is a subarray that starts from the beginning of the array and extends to any point within it.
    A suffix of an array is a subarray that starts at any point within the array and extends to the end of the array.
    Note that the prefix and suffix to be chosen for the operation can be empty.
    Note that x-value has a different definition in this version.

    Example :

    Input: nums = [1,2,3,4,5], k = 3, queries = [[2,2,0,2],[3,3,3,0],[0,1,0,1]]
    Output: [2,2,2]
    Explanation:
    For query 0, nums becomes [1, 2, 2, 4, 5], and the empty prefix must be removed. The possible operations are:
    Remove the suffix [2, 4, 5]. nums becomes [1, 2].
    Remove the empty suffix. nums becomes [1, 2, 2, 4, 5] with a product 80, which gives remainder 2 when divided by 3.
    For query 1, nums becomes [1, 2, 2, 3, 5], and the prefix [1, 2, 2] must be removed. The possible operations are:
    Remove the empty suffix. nums becomes [3, 5].
    Remove the suffix [5]. nums becomes [3].
    For query 2, nums becomes [1, 2, 2, 3, 5], and the empty prefix must be removed. The possible operations are:
    Remove the suffix [2, 2, 3, 5]. nums becomes [1].
    Remove the suffix [3, 5]. nums becomes [1, 2, 2].
 */


class Solution {
public:
    vector<int> resultArray(vector<int>& nums, int k, vector<vector<int>>& queries) {
        int n = nums.size();

        int size = 1;
        while (size < n) {
            size <<= 1;
        }

        vector<long long> H(2 * size * k, 0);
        vector<int> prod(2 * size, 1 % k);

        for (int i = 0; i < n; i++) {
            int v = nums[i] % k;
            int nd = size + i;

            H[nd * k + v] = 1;
            prod[nd] = v;
        }

        for (int i = size - 1; i >= 1; i--) {
            int lc = 2 * i;
            int rc = lc + 1;
            int lp = prod[lc];

            int bi = i * k;
            int bl = lc * k;
            int br = rc * k;

            for (int q = 0; q < k; q++) {
                H[bi + q] = H[bl + q];
            }

            for (int q = 0; q < k; q++) {
                long long c = H[br + q];

                if (c) {
                    H[bi + (lp * q) % k] += c;
                }
            }

            prod[i] = lp * prod[rc] % k;
        }

        vector<int> ans;

        for (auto& query : queries) {
            int idx = query[0];
            int val = query[1];
            int start = query[2];
            int x = query[3];

            int nd = size + idx;
            int base = nd * k;

            for (int q = 0; q < k; q++) {
                H[base + q] = 0;
            }

            int v = val % k;

            H[base + v] = 1;
            prod[nd] = v;

            int cur = nd >> 1;

            while (cur) {
                int lc = 2 * cur;
                int rc = lc + 1;
                int lp = prod[lc];

                int bi = cur * k;
                int bl = lc * k;
                int br = rc * k;

                for (int q = 0; q < k; q++) {
                    H[bi + q] = H[bl + q];
                }

                for (int q = 0; q < k; q++) {
                    long long c = H[br + q];

                    if (c) {
                        H[bi + (lp * q) % k] += c;
                    }
                }

                prod[cur] = lp * prod[rc] % k;
                cur >>= 1;
            }

            int l = start + size;
            int r = n + size;

            vector<int> ln;
            vector<int> rn;

            while (l < r) {
                if (l & 1) {
                    ln.push_back(l);
                    l++;
                }

                if (r & 1) {
                    r--;
                    rn.push_back(r);
                }

                l >>= 1;
                r >>= 1;
            }

            reverse(rn.begin(), rn.end());

            vector<long long> res(k, 0);
            int p = 1 % k;

            for (int node : ln) {
                int b = node * k;

                for (int q = 0; q < k; q++) {
                    long long c = H[b + q];

                    if (c) {
                        res[(p * q) % k] += c;
                    }
                }

                p = p * prod[node] % k;
            }

            for (int node : rn) {
                int b = node * k;

                for (int q = 0; q < k; q++) {
                    long long c = H[b + q];

                    if (c) {
                        res[(p * q) % k] += c;
                    }
                }

                p = p * prod[node] % k;
            }

            ans.push_back((int)res[x]);
        }

        return ans;
    }
};