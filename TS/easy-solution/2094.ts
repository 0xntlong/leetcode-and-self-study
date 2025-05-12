/**
2094. Finding 3-Digits Even Numbers
    You are given an integer array digits, where each element is a digit. The array may contain duplicates.
    You need to find all the unique integers that follow the given requirements:
    The integer consists of the concatenation of three elements from digits in any arbitrary order.
    The integer does not have leading zeros.
    The integer is even.
    For example, if the given digits were [1, 2, 3], integers 132 and 312 follow the requirements.
    Return a sorted array of the unique integers.

    Example :
    Input: digits = [2,1,3,0]
    Output: [102,120,130,132,210,230,302,310,312,320]
    Explanation: All the possible integers that follow the requirements are in the output array. 
    Notice that there are no odd integers or integers with leading zeros.
 */

    function findEvenNumbers(digits: number[]): number[] {
    const res : number[] = [];
    const freq : number[] = new Array(10).fill(0);
    const DFS = (n : number) => {
        if (n > 99){
            if (n % 2 === 0){
                res.push(n);
            }
            return;
        }
        for (let i = (n === 0 ? 1 : 0); i < 10; i++){
            if (freq[i] > 0){
                freq[i]--;
                DFS(n * 10 + i);
                freq[i]++;
            }
        }
    };
    digits.forEach(d => freq[d]++);
    DFS(0);
    return res;
};