/**
3272. Find the Count of Good Integers
    You are given two positive integers n and k.
    An integer x is called k-palindromic if:
    x is a palindrome.
    x is divisible by k.
    An integer is called good if its digits can be rearranged to form a k-palindromic integer. For example, for k = 2, 2020 can be rearranged to form the k-palindromic integer 2002, whereas 1010 cannot be rearranged to form a k-palindromic integer.
    Return the count of good integers containing n digits.
    Note that any integer must not have leading zeros, neither before nor after rearrangement. For example, 1010 cannot be rearranged to form 101.

    Example :
    Input: n = 3, k = 5
    Output: 27
    Explanation:
    Some of the good integers are:
    551 because it can be rearranged to form 515.
    525 because it is already k-palindromic.
 */


/**
 * @param {number} n
 * @param {number} k
 * @return {number}
 */
var countGoodIntegers = function(n, k) {
    function factorial(n){
        let res = 1;
        for (let i = 1; i <= n; i++){
            res *= i;
        }
        return res;
    }
    let dict = new Set();
    let base = Math.pow(10, Math.floor((n - 1) / 2));
    let skip = n % 2;
    for (let i = base; i < base * 10; i++){
        let s = i.toString();
        let sb = s.split('');
        if (skip === 1){
            sb.pop();
        }
        let palindString = s + sb.reverse().join('');
        let palindInt = parseInt(palindString, 10);
        if (palindInt % k === 0){
            let palindCharArr = palindString.split('');
            palindCharArr.sort();
            dict.add(palindCharArr.join(''));
        }
    }
    let fac = Array(n + 1).fill(0);
    for (let i = 0; i <= n; i++){
        fac[i] = factorial(i);
    }
    let ans = 0;
    for (let s of dict){
        let cnt = Array(10).fill(0);
        for (let c of s){
            cnt[parseInt(c, 10)]++;
        }
        let total = (n - cnt[0]) * fac[n - 1];
        for (let x of cnt){
            if (x > 1){
                total /= fac[x];
            }
        }
        ans += total;
    }
    return ans;
};