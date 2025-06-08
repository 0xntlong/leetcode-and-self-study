/**
386. Lexicographical Numbers
    Given an integer n, return all the numbers in the range [1, n] sorted in lexicographical order.
    You must write an algorithm that runs in O(n) time and uses O(1) extra space. 

    Example :
    Input: n = 13
    Output: [1,10,11,12,13,2,3,4,5,6,7,8,9]
 */


function lexicalOrder(n: number): number[] {
    let res: number[] = new Array(n);
    let curr = 1;
    for (let i = 0; i < n ; i++){
        res[i] = curr;
        if (curr * 10 > n){
            if (curr === n){
                curr = Math.floor(curr / 10);
            }
            curr++;
            while (curr % 10 === 0){
                curr = Math.floor(curr / 10);
            }
        } else {
            curr *= 10;
        }
    }
    return res;
};