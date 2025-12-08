/*
1925. Count Square Sum Triples
    A square triple (a,b,c) is a triple where a, b, and c are integers and a2 + b2 = c2.
    Given an integer n, return the number of square triples such that 1 <= a, b, c <= n.

    Example :
    Input: n = 5
    Output: 2
    Explanation: The square triples are (3,4,5) and (4,3,5).
*/



/**
 * @param {number} n
 * @return {number}
 */
var countTriples = function(n) {
    let cnt = 0;
    for (let a = 3; a < n; a++){
        let sqrtA = a * a;
        for (let b = 3; b < n; b++){
            let sqrtSum = sqrtA + b * b;
            let c = Math.floor(Math.sqrt(sqrtSum));
            if (c > n)
                break
            if (c * c === sqrtSum){
                cnt++;
            }
        }
    }
    return cnt;
};