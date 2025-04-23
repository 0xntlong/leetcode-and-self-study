/**
1399. Count Largest Group
    You are given an integer n.
    Each number from 1 to n is grouped according to the sum of its digits.
    Return the number of groups that have the largest size.

    Example :
    Input: n = 13
    Output: 4
    Explanation: There are 9 groups in total, they are grouped according sum of its digits of numbers from 1 to 13:
    [1,10], [2,11], [3,12], [4,13], [5], [6], [7], [8], [9].
    There are 4 groups with largest size.
 */

    function countLargestGroup(n: number): number {
        const sumDigit = (x : number): number => {
            let sum = 0;
            while (x > 0){
                sum += x % 10;
                x = Math.floor(x / 10);
            }
            return sum;
        };
        const freqMap = new Map<number, number>();
        for (let i = 1; i <= n; i++){
            const total = sumDigit(i);
            freqMap.set(total, (freqMap.get(total) || 0) + 1);
        }
        let maxRange = 0;
        for (let value of freqMap.values()){
            maxRange = Math.max(maxRange, value);
        }
        let largest = 0;
        for (let value of freqMap.values()){
            if (value === maxRange){
                largest++;
            }
        }
        return largest;
    };