/**
898. Bitwise ORs of Subarrays
    Given an integer array arr, return the number of distinct bitwise ORs of all the non-empty subarrays of arr.
    The bitwise OR of a subarray is the bitwise OR of each integer in the subarray. The bitwise OR of a subarray of one integer is that integer.
    A subarray is a contiguous non-empty sequence of elements within an array.

    Example :
    Input: arr = [0]
    Output: 1
    Explanation: There is only one possible result: 0.
 */


function subarrayBitwiseORs(arr: number[]): number {
    const res : Set<number> = new Set();
    for (let i = 0 ; i < arr.length; i++){
        res.add(arr[i]);
        for (let j = i - 1; j >= 0; j--){
            if (arr[j] === (arr[j] | arr[i]))
                break;
            arr[j] |= arr[i];
            res.add(arr[j]);
        }
    }
    return res.size;
};