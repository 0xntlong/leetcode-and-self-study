/**
1200. Minimum Absolute Difference
    Given an array of distinct integers arr, find all pairs of elements with the minimum absolute difference of any two elements.
    Return a list of pairs in ascending order(with respect to pairs), each pair [a, b] follows
    a, b are from arr
    a < b
    b - a equals to the minimum absolute difference of any two elements in arr
    Example :
    Input: arr = [4,2,1,3]
    Output: [[1,2],[2,3],[3,4]]
    Explanation: The minimum absolute difference is 1. List all pairs with difference equal to 1 in ascending order.
 */



function minimumAbsDifference(arr: number[]): number[][] {
    arr.sort((a, b) => a - b);
    const n = arr.length;
    let min_diff = Number.POSITIVE_INFINITY;
    for (let i = 0; i < n - 1; i++) {
        min_diff = Math.min(min_diff, arr[i + 1] - arr[i]);
    }

    const res: number[][] = [];
    for (let i = 0; i < n - 1; i++) {
        if (arr[i + 1] - arr[i] === min_diff) {
            res.push([arr[i], arr[i + 1]]);
        }
    }
    return res;
};