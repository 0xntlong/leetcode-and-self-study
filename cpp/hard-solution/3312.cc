/**
3312. Sorted GCD Pair Queries
    You are given an integer array nums of length n and an integer array queries.

    Let gcdPairs denote an array obtained by calculating the GCD of all possible pairs (nums[i], nums[j]), where 0 <= i < j < n, and then sorting these values in ascending order.

    For each query queries[i], you need to find the element at index queries[i] in gcdPairs.

    Return an integer array answer, where answer[i] is the value at gcdPairs[queries[i]] for each query.

    The term gcd(a, b) denotes the greatest common divisor of a and b.

    

    Example 1:

    Input: nums = [2,3,4], queries = [0,2,2]

    Output: [1,2,2]

    Explanation:

    gcdPairs = [gcd(nums[0], nums[1]), gcd(nums[0], nums[2]), gcd(nums[1], nums[2])] = [1, 2, 1].

    After sorting in ascending order, gcdPairs = [1, 1, 2].

    So, the answer is [gcdPairs[queries[0]], gcdPairs[queries[1]], gcdPairs[queries[2]]] = [1, 2, 2].
 */



class Solution {
public:
    vector<int> gcdValues(vector<int>& nums, vector<long long>& queries) {
        int maxValue = *max_element(nums.begin(), nums.end());

        vector<int> freq(maxValue + 1, 0);
        for (int num : nums) {
            freq[num]++;
        }

        vector<long long> count(maxValue + 1, 0);

        for (int gcdValue = maxValue; gcdValue >= 1; gcdValue--) {
            long long total = 0;

            for (int multiple = gcdValue; multiple <= maxValue; multiple += gcdValue) {
                total += freq[multiple];
            }

            long long pairs = total * (total - 1) / 2;

            for (
                int multiple = 2 * gcdValue;
                multiple <= maxValue;
                multiple += gcdValue
            ) {
                pairs -= count[multiple];
            }

            count[gcdValue] = pairs;
        }

        vector<long long> prefix;
        vector<int> values;
        long long sum = 0;

        for (int gcdValue = 1; gcdValue <= maxValue; gcdValue++) {
            if (count[gcdValue] > 0) {
                sum += count[gcdValue];
                prefix.push_back(sum);
                values.push_back(gcdValue);
            }
        }

        vector<int> result;

        for (long long query : queries) {
            int index = lower_bound(
                prefix.begin(),
                prefix.end(),
                query + 1
            ) - prefix.begin();

            result.push_back(values[index]);
        }

        return result;
    }
};