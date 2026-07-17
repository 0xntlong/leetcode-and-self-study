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




function gcdValues(nums: number[], queries: number[]): number[] {
    const maxValue = Math.max(...nums);

    const freq: number[] = Array(maxValue + 1).fill(0);

    for (const num of nums) {
        freq[num]++;
    }

    const count: number[] = Array(maxValue + 1).fill(0);

    for (let gcdValue = maxValue; gcdValue >= 1; gcdValue--) {
        let total = 0;

        for (
            let multiple = gcdValue;
            multiple <= maxValue;
            multiple += gcdValue
        ) {
            total += freq[multiple];
        }

        let pairs = total * (total - 1) / 2;

        for (
            let multiple = 2 * gcdValue;
            multiple <= maxValue;
            multiple += gcdValue
        ) {
            pairs -= count[multiple];
        }

        count[gcdValue] = pairs;
    }

    const prefix: number[] = [];
    const values: number[] = [];

    let sum = 0;

    for (let gcdValue = 1; gcdValue <= maxValue; gcdValue++) {
        if (count[gcdValue] > 0) {
            sum += count[gcdValue];
            prefix.push(sum);
            values.push(gcdValue);
        }
    }

    const result: number[] = [];

    for (const query of queries) {
        const target = query + 1;

        let left = 0;
        let right = prefix.length;

        while (left < right) {
            const mid = Math.floor((left + right) / 2);

            if (prefix[mid] < target) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }

        result.push(values[left]);
    }

    return result;
}