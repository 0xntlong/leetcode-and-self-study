/**
1569. Number of Ways to Reorder Array to Get Same BST
    Given an array nums that represents a permutation of integers from 1 to n. We are going to construct a binary search tree (BST) by inserting the elements of nums in order into an initially empty BST. Find the number of different ways to reorder nums so that the constructed BST is identical to that formed from the original array nums.
    For example, given nums = [2,1,3], we will have 2 as the root, 1 as a left child, and 3 as a right child. The array [2,3,1] also yields the same BST but [3,2,1] yields a different BST.
    Return the number of ways to reorder nums such that the BST formed is identical to the original BST formed from nums.
    Since the answer may be very large, return it modulo 109 + 7.

    Example :
    Input: nums = [2,1,3]
    Output: 1
    Explanation: We can reorder nums to be [2,3,1] which will yield the same BST. There are no other ways to reorder nums which will yield the same BST.
 */



class Solution {
public:
    static constexpr long long MOD = 1000000007LL;

    vector<vector<long long>> comb;

    long long count(const vector<int>& arr) {
        int n = arr.size();

        if (n <= 2) {
            return 1;
        }

        int root = arr[0];

        vector<int> left, right;

        for (int x : arr) {
            if (x < root) {
                left.push_back(x);
            } else if (x > root) {
                right.push_back(x);
            }
        }

        int L = left.size();
        int R = right.size();

        long long ways = comb[L + R][L];

        return ways * count(left) % MOD * count(right) % MOD;
    }

    int numOfWays(vector<int>& nums) {
        int n = nums.size();

        comb.assign(n + 1, vector<long long>(n + 1, 0));

        for (int i = 0; i <= n; i++) {
            comb[i][0] = comb[i][i] = 1;

            for (int j = 1; j < i; j++) {
                comb[i][j] =
                    (comb[i - 1][j - 1] + comb[i - 1][j]) % MOD;
            }
        }

        return (count(nums) - 1 + MOD) % MOD;
    }
};