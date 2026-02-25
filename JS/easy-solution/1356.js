/*
1356. Sort Integers by The Number of 1 Bits
    You are given an integer array arr. 
    Sort the integers in the array in ascending order by the number of 1's in their binary representation 
    and in case of two or more integers have the same number of 1's you have to sort them in ascending order.
    Return the array after sorting it.
    
    Example :
    Input: arr = [0,1,2,3,4,5,6,7,8]
    Output: [0,1,2,4,8,3,5,6,7]
    Explantion: [0] is the only integer with 0 bits.
    [1,2,4,8] all have 1 bit.
    [3,5,6] have 2 bits.
    [7] has 3 bits.
    The sorted array by bits is [0,1,2,4,8,3,5,6,7]
*/



/**
 * @param {number[]} arr
 * @return {number[]}
 */
var sortByBits = function(arr) {
    arr.sort((a, b) => {
        const bitsA = a.toString(2).split('0').join('').length;
        const bitsB = b.toString(2).split('0').join('').length;

        if (bitsA === bitsB)
            return a - b;

        return bitsA - bitsB;
    });

    return arr;
};