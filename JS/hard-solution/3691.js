/**
3691. Maximum Total Subarray Value II
    You are given an integer array nums of length n and an integer k.
    You must select exactly k distinct subarrays nums[l..r] of nums. Subarrays may overlap, but the exact same subarray (same l and r) cannot be chosen more than once.
    The value of a subarray nums[l..r] is defined as: max(nums[l..r]) - min(nums[l..r]).
    The total value is the sum of the values of all chosen subarrays.
    Return the maximum possible total value you can achieve.

    Example :
    Input: nums = [1,3,2], k = 2
    Output: 4
    Explanation:
    One optimal approach is:
    Choose nums[0..1] = [1, 3]. The maximum is 3 and the minimum is 1, giving a value of 3 - 1 = 2.
    Choose nums[0..2] = [1, 3, 2]. The maximum is still 3 and the minimum is still 1, so the value is also 3 - 1 = 2.
    Adding these gives 2 + 2 = 4.
 */




/**
 * @param {number[]} nums
 * @param {number} k
 * @return {number}
 */
var maxTotalValue = function(nums, k) {
    class MaxHeap {
        constructor() { this.heap = []; }
        push(node) {
            this.heap.push(node);
            let idx = this.heap.length - 1;
            while (idx > 0) {
                let parent = Math.floor((idx - 1) / 2);
                if (this.heap[idx].val <= this.heap[parent].val) break;
                [this.heap[idx], this.heap[parent]] = [this.heap[parent], this.heap[idx]];
                idx = parent;
            }
        }
        pop() {
            if (this.heap.length === 1) return this.heap.pop();
            const top = this.heap[0];
            this.heap[0] = this.heap.pop();
            let idx = 0;
            while (true) {
                let left = 2 * idx + 1, right = 2 * idx + 2, largest = idx;
                if (left < this.heap.length && this.heap[left].val > this.heap[largest].val) largest = left;
                if (right < this.heap.length && this.heap[right].val > this.heap[largest].val) largest = right;
                if (largest === idx) 
                    break;
                [this.heap[idx], this.heap[largest]] = [this.heap[largest], this.heap[idx]];
                idx = largest;
            }
            return top;
        }
    }

    const n = nums.length;
    let size = 1; while (size < n) size *= 2;
    const segMax = new Int32Array(2 * size).fill(0);
    const segMin = new Int32Array(2 * size).fill(1e9);

    for (let i = 0; i < n; i++) segMax[size + i] = segMin[size + i] = nums[i];
    for (let i = size - 1; i > 0; i--) {
        segMax[i] = Math.max(segMax[2 * i], segMax[2 * i + 1]);
        segMin[i] = Math.min(segMin[2 * i], segMin[2 * i + 1]);
    }

    const query = (l, r) => {
        let mx = 0, mn = 1e9;
        for (l += size, r += size; l <= r; l >>= 1, r >>= 1) {
            if (l & 1) { 
                mx = Math.max(mx, segMax[l]); 
                mn = Math.min(mn, segMin[l]); 
                l++; 
            }
            if (!(r & 1)) { 
                mx = Math.max(mx, segMax[r]); 
                mn = Math.min(mn, segMin[r]); 
                r--; 
            }
        }
        return mx - mn;
    };

    const pq = new MaxHeap();
    for (let l = 0; l < n; l++)
        pq.push({val: query(l, n - 1), l, r: n - 1});

    let ans = 0;
    for (let i = 0; i < k; i++) {
        let {val, l, r} = pq.pop();
        ans += val;
        if (r > l) 
            pq.push({val: query(l, r - 1), l, r: r - 1});
    }
    return ans;
};