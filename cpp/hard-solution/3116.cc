/**
3116. Kth Smallest Amount With Single Denomination Combination
    You are given an integer array coins representing coins of different denominations and an integer k.
    You have an infinite number of coins of each denomination. However, you are not allowed to combine coins of different denominations.
    Return the kth smallest amount that can be made using these coins.

    Example :
    Input: coins = [3,6,9], k = 3
    Output: 9
    Explanation: The given coins can make the following amounts:
    Coin 3 produces multiples of 3: 3, 6, 9, 12, 15, etc.
    Coin 6 produces multiples of 6: 6, 12, 18, 24, etc.
    Coin 9 produces multiples of 9: 9, 18, 27, 36, etc.
    All of the coins combined produce: 3, 6, 9, 12, 15, etc.
 */



class Solution {
public:
    using ll = long long;
    long long findKthSmallest(vector<int>& coins, int k) {
        sort(coins.begin(), coins.end());

        vector<int> newCoins;

        for (int x : coins) {
            bool keep = true;

            for (int y : newCoins) {
                if (x % y == 0) {
                    keep = false;
                    break;
                }
            }

            if (keep) {
                newCoins.push_back(x);
            }
        }

        coins = newCoins;

        int n = coins.size();
        int m = 1 << n;

        vector<ll> lcm(m, 1);

        ll left = k;
        ll right = 1LL * coins[0] * k + 1;

        for (int mask = 1; mask < m; mask++) {
            int prevMask = mask & (mask - 1);
            int bit = mask & -mask;
            int i = __builtin_ctz(bit);

            ll temp = lcm[prevMask] /
                      gcd(lcm[prevMask], (ll)coins[i]);

            if (temp <= right / coins[i]) {
                lcm[mask] = temp * coins[i];
            } else {
                lcm[mask] = right + 1;
            }
        }

        auto get = [&](ll x) -> ll {
            ll count = 0;

            for (int mask = 1; mask < m; mask++) {
                if (lcm[mask] > x) {
                    continue;
                }

                if (__builtin_popcount(mask) % 2 == 1) {
                    count += x / lcm[mask];
                } else {
                    count -= x / lcm[mask];
                }
            }

            return count;
        };

        while (left < right) {
            ll mid = left + (right - left) / 2;

            if (get(mid) >= k) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }

        return left;
    }
};