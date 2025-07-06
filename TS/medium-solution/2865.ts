/**
1865. Finding Pairs With a Certain Sum
    You are given two integer arrays nums1 and nums2. You are tasked to implement a data structure that supports queries of two types:

    Add a positive integer to an element of a given index in the array nums2.
    Count the number of pairs (i, j) such that nums1[i] + nums2[j] equals a given value (0 <= i < nums1.length and 0 <= j < nums2.length).
    Implement the FindSumPairs class:

    FindSumPairs(int[] nums1, int[] nums2) Initializes the FindSumPairs object with two integer arrays nums1 and nums2.
    void add(int index, int val) Adds val to nums2[index], i.e., apply nums2[index] += val.
    int count(int tot) Returns the number of pairs (i, j) such that nums1[i] + nums2[j] == tot.

    Example 1:
    Input
    ["FindSumPairs", "count", "add", "count", "count", "add", "add", "count"]
    [[[1, 1, 2, 2, 2, 3], [1, 4, 5, 2, 5, 4]], [7], [3, 2], [8], [4], [0, 1], [1, 1], [7]]
    Output
    [null, 8, null, 2, 1, null, null, 11]
 */



class FindSumPairs {
    private freq1: Map<number, number> = new Map();
    private freq2: Map<number, number> = new Map();
    private keys: number[] = [];
    private nums2: number[];

    constructor(nums1: number[], nums2: number[]) {
        for (const num of nums1){
            this.freq1.set(num, (this.freq1.get(num) || 0) + 1);
        }
        for (const num of nums2){
            this.freq2.set(num, (this.freq2.get(num) || 0) + 1);
        }
        this.keys = Array.from(new Set(nums1)).sort((a, b) => a - b);
        this.nums2 = nums2;
    }

    add(index: number, val: number): void {
        const oldVal = this.nums2[index];
        this.freq2.set(oldVal, this.freq2.get(oldVal)! - 1);
        this.nums2[index] += val;
        this.freq2.set(this.nums2[index], (this.freq2.get(this.nums2[index]) || 0) + 1);
    }

    count(tot: number): number {
        let cnt = 0;
        for (const num1 of this.keys){
            if (num1 > tot)
                break;
            const rem = tot - num1;
            if (this.freq2.has(rem)){
                cnt += (this.freq1.get(num1) || 0) * (this.freq2.get(rem) || 0);
            }
        }
        return cnt;
    }
}

/**
 * Your FindSumPairs object will be instantiated and called as such:
 * var obj = new FindSumPairs(nums1, nums2)
 * obj.add(index,val)
 * var param_2 = obj.count(tot)
 */