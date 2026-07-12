/**
1331. Rank Transform of an Array
    Given an array of integers arr, replace each element with its rank.
    The rank represents how large the element is. The rank has the following rules:
    Rank is an integer starting from 1.
    The larger the element, the larger the rank. If two elements are equal, their rank must be the same.
    Rank should be as small as possible.

    Example 
    Input: arr = [40,10,20,30]
    Output: [4,1,2,3]
    Explanation: 40 is the largest element. 10 is the smallest. 20 is the second smallest. 30 is the third smallest.
 */



function arrayRankTransform(arr: number[]): number[] {
    const rankMap = new Map<number, number>();
    const sortedArray = [...arr].sort((a, b) => a - b);

    let rank = 1;

    for (const x of sortedArray) {
        if (!rankMap.has(x)) {
            rankMap.set(x, rank);
            rank++;
        }
    }

    return arr.map(x => rankMap.get(x)!);
}