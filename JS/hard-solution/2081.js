/**
2081. Sum of k-Mirror Numbers
    A k-mirror number is a positive integer without leading zeros that reads the same both forward and backward in base-10 as well as in base-k.
    For example, 9 is a 2-mirror number. The representation of 9 in base-10 and base-2 are 9 and 1001 respectively, which read the same both forward and backward.
    On the contrary, 4 is not a 2-mirror number. The representation of 4 in base-2 is 100, which does not read the same both forward and backward.
    Given the base k and the number n, return the sum of the n smallest k-mirror numbers.

    Example :
    Input: k = 2, n = 5
    Output: 25
    Explanation:
    The 5 smallest 2-mirror numbers and their representations in base-2 are listed as follows:
    base-10    base-2
        1          1
        3          11
        5          101
        7          111
        9          1001
    Their sum = 1 + 3 + 5 + 7 + 9 = 25.
 */



/**
 * @param {number} k
 * @param {number} n
 * @return {number}
 */

var reverse = function(x){
    let res = 0;
    while (x > 0){
        res = res * 10 + x % 10;
        x = Math.floor(x / 10);
    }
    return res;
}
var Palindrome = function (x, k){
    const digits = [];
    while (x > 0){
        digits.push(x % k);
        x = Math.floor(x / k);
    }
    for (let i = 0, j = digits.length - 1; i < j; i++, j--){
        if (digits[i] !== digits[j])
            return false;
    }
    return true;
}
var isPalindrome = function(mid, odd){
    const len = String(mid).length;
    const rev = reverse(odd ? Math.floor(mid / 10) : mid);
    const fac = 10 ** (odd ? len - 1 : len);
    return mid * fac + rev;
}
var kMirror = function(k, n) {
    let total = 0;
    let length = 1;
    while (true){
        const mid = Math.floor((length + 1) / 2);
        const start = 10 ** (mid - 1);
        const end = 10 ** mid;
        for (let i = start; i < end; i++){
            const pal = isPalindrome(i, length % 2 === 1);
            if (Palindrome(pal, k)){
                total += pal;
                n--;
                if (n === 0){
                    return total;
                }
            }
        }
        length++;
    }
};