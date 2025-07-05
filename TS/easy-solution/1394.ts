/*
1394. Find Lucky Integer in an Array
    Given an array of integers arr, a lucky integer is an integer that has a frequency in the array equal to its value.
    Return the largest lucky integer in the array. If there is no lucky integer return -1.
    
    Example :
    Input: arr = [2,2,3,4]
    Output: 2
    Explanation: The only lucky number in the array is 2 because frequency[2] == 2.

 */


function findLucky(arr: number[]): number {
    const hashMap = new Array(501).fill(0);
    let lucky = -1;

    for (const num of arr) {
        hashMap[num]++;
    }

    for (let i = 1; i <= 500; i++) {
        if (hashMap[i] === i) {
            lucky = Math.max(lucky, i);
        }
    }

    return lucky;
};