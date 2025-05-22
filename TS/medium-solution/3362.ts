/**
3362. Zero Array Transformation III
    You are given an integer array nums of length n and a 2D array queries where queries[i] = [li, ri].
    Each queries[i] represents the following action on nums:
    Decrement the value at each index in the range [li, ri] in nums by at most 1.
    The amount by which the value is decremented can be chosen independently for each index.
    A Zero Array is an array with all its elements equal to 0.
    Return the maximum number of elements that can be removed from queries, such that nums can still be converted to a zero array using the remaining queries. If it is not possible to convert nums to a zero array, return -1.

    Example :
    Input: nums = [2,0,2], queries = [[0,2],[0,2],[1,1]]
    Output: 1
    Explanation:
    After removing queries[2], nums can still be converted to a zero array.
    Using queries[0], decrement nums[0] and nums[2] by 1 and nums[1] by 0.
    Using queries[1], decrement nums[0] and nums[2] by 1 and nums[1] by 0.
*/



class MaxHeap {
    arr: number[] = [];
    push(x: number) {
        this.arr.push(x);
        let i = this.arr.length - 1;
        while (i > 0 && this.arr[(i - 1) >> 1] < this.arr[i]) {
            [this.arr[i], this.arr[(i - 1) >> 1]] = [this.arr[(i - 1) >> 1], this.arr[i]];
            i = (i - 1) >> 1;
        }
    }
    pop(): number {
        const top = this.arr[0];
        const last = this.arr.pop()!;
        if (this.arr.length) {
            this.arr[0] = last;
            let i = 0, n = this.arr.length;
            while (true) {
                let l = 2 * i + 1, r = 2 * i + 2, max = i;
                if (l < n && this.arr[l] > this.arr[max]) max = l;
                if (r < n && this.arr[r] > this.arr[max]) max = r;
                if (max === i) break;
                [this.arr[i], this.arr[max]] = [this.arr[max], this.arr[i]];
                i = max;
            }
        }
        return top;
    }
    top(): number { return this.arr[0]; }
    size(): number { return this.arr.length; }
}

function maxRemoval(nums: number[], queries: number[][]): number {
    queries.sort((a, b) => a[0] - b[0]);
    const heap = new MaxHeap();
    const edges = new Array(nums.length + 1).fill(0);
    let cnt = 0;
    for (let i = 0, j = 0; i < nums.length; i++) {
        cnt += edges[i];
        while (j < queries.length && queries[j][0] === i) heap.push(queries[j++][1]);
        while (cnt < nums[i] && heap.size() && heap.top() >= i) {
            cnt++;
            edges[heap.pop() + 1] -= 1;
        }
        if (cnt < nums[i]) return -1;
    }
    return heap.size();
}