/**
3934. Smallest Unique Subarray
    You are given an integer array nums.
    Find the minimum length of a subarray that is not identical to any other subarray in nums.
    Return an integer denoting the minimum possible length of such a subarray.
    Two subarrays are considered identical if they have the same length and the same elements in corresponding positions.

    Example :
    Input: nums = [3,3,3]
    Output: 3
    Explanation:
    Subarrays of length 1: [3] → appears 3 times
    Subarrays of length 2: [3, 3] → appears 2 times
    Subarrays of length 3: [3, 3, 3] → appears once
    The subarray [3, 3, 3] is unique, so the smallest unique subarray length is 3.
 */


class Solution {
public:
    private:
    long long modPow(long long base, int exp, long long modulus) {
        long long res = 1;

        while (exp > 0) {
            if (exp & 1) {
                res = res * base % modulus;
            }
            base = base * base % modulus;
            exp >>= 1;
        }

        return res;
    }

public:
    int smallestUniqueSubarray(vector<int>& nums) {
        int low = 1;
        int high = nums.size() + 1;
        int ans = -1;

        const long long base = 100003;
        const long long modulus = 1000000007;

        while (low < high) {
            int mid = low + (high - low) / 2;

            unordered_set<long long> unique;
            unordered_set<long long> non_unique;

            long long subarray = 0;
            long long pow1 = modPow(base, mid - 1, modulus);

            for (int i = 0; i + mid <= nums.size(); i++) {
                if (i == 0) {
                    for (int j = i; j < i + mid; j++) {
                        subarray = (subarray * base + nums[j]) % modulus;
                    }
                } else {
                    subarray = (subarray - nums[i - 1] * pow1 % modulus + modulus) % modulus;
                    subarray = (subarray * base + nums[i + mid - 1]) % modulus;
                }

                if (non_unique.count(subarray)) {
                    continue;
                } else if (unique.count(subarray)) {
                    unique.erase(subarray);
                    non_unique.insert(subarray);
                } else {
                    unique.insert(subarray);
                }
            }

            if (!unique.empty()) {
                high = mid;
                ans = mid;
            } else {
                low = mid + 1;
            }
        }

        return ans;
    }
};
