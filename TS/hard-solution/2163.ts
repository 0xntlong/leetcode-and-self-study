/**
2163. Minimum Difference in Sums After Removal of Elements
    You are allowed to remove any subsequence of elements of size exactly n from nums. The remaining 2 * n elements will be divided into two equal parts:

    The first n elements belonging to the first part and their sum is sumfirst.
    The next n elements belonging to the second part and their sum is sumsecond.
    The difference in sums of the two parts is denoted as sumfirst - sumsecond.

    For example, if sumfirst = 3 and sumsecond = 2, their difference is 1.
    Similarly, if sumfirst = 2 and sumsecond = 3, their difference is -1.
    Return the minimum difference possible between the sums of the two parts after the removal of n elements.

    Example :

    Input: nums = [3,1,2]
    Output: -1
    Explanation: Here, nums has 3 elements, so n = 1. 
    Thus we have to remove 1 element from nums and divide the array into two equal parts.
    - If we remove nums[0] = 3, the array will be [1,2]. The difference in sums of the two parts will be 1 - 2 = -1.
    - If we remove nums[1] = 1, the array will be [3,2]. The difference in sums of the two parts will be 3 - 2 = 1.
    - If we remove nums[2] = 2, the array will be [3,1]. The difference in sums of the two parts will be 3 - 1 = 2.
    The minimum difference between sums of the two parts is min(-1,1,2) = -1. 
 */



function minimumDifference(nums: number[]): number {
    const n = nums.length / 3;

    let maxHeap = [];
    let leftSum = 0;
    const leftDiff = new Array(n + 1);

    for (let i = 0; i < n; i++) {
        insertMax(maxHeap, nums[i]);
        leftSum += nums[i];
    }
    leftDiff[0] = leftSum;

    for (let i = n; i < 2 * n; i++) {
        const num = nums[i];
        if (num < maxHeap[0]) {
            leftSum += num - extractMax(maxHeap);
            insertMax(maxHeap, num);
        }
        leftDiff[i - n + 1] = leftSum;
    }

    let minHeap = [];
    let rightSum = 0;
    for (let i = 2 * n; i < 3 * n; i++) {
        insertMin(minHeap, nums[i]);
        rightSum += nums[i];
    }

    let minDiff = leftDiff[n] - rightSum;

    for (let i = 2 * n - 1; i >= n; i--) {
        const num = nums[i];
        if (num > minHeap[0]) {
            rightSum += num - extractMin(minHeap);
            insertMin(minHeap, num);
        }
        const diffIndex = i - n;
        const currDiff = leftDiff[diffIndex] - rightSum;
        minDiff = Math.min(minDiff, currDiff);
    }

    return minDiff;

    function insertMax(heap, val) {
        heap.push(val);
        siftUpMax(heap, heap.length - 1);
    }
    function extractMax(heap) {
        const max = heap[0];
        const last = heap.pop();
        if (heap.length > 0) {
            heap[0] = last;
            siftDownMax(heap, 0);
        }
        return max;
    }
    function siftUpMax(heap, i) {
        while (i > 0) {
            const p = Math.floor((i - 1) / 2);
            if (heap[p] >= heap[i]) break;
            [heap[p], heap[i]] = [heap[i], heap[p]];
            i = p;
        }
    }
    function siftDownMax(heap, i) {
        const n = heap.length;
        while (2 * i + 1 < n) {
            let j = 2 * i + 1;
            if (j + 1 < n && heap[j + 1] > heap[j]) j++;
            if (heap[i] >= heap[j]) break;
            [heap[i], heap[j]] = [heap[j], heap[i]];
            i = j;
        }
    }

    function insertMin(heap, val) {
        heap.push(val);
        siftUpMin(heap, heap.length - 1);
    }
    function extractMin(heap) {
        const min = heap[0];
        const last = heap.pop();
        if (heap.length > 0) {
            heap[0] = last;
            siftDownMin(heap, 0);
        }
        return min;
    }
    function siftUpMin(heap, i) {
        while (i > 0) {
            const p = Math.floor((i - 1) / 2);
            if (heap[p] <= heap[i]) break;
            [heap[p], heap[i]] = [heap[i], heap[p]];
            i = p;
        }
    }
    function siftDownMin(heap, i) {
        const n = heap.length;
        while (2 * i + 1 < n) {
            let j = 2 * i + 1;
            if (j + 1 < n && heap[j + 1] < heap[j]) j++;
            if (heap[i] <= heap[j]) break;
            [heap[i], heap[j]] = [heap[j], heap[i]];
            i = j;
        }
    }
};