/**
3003. Maximize the Number of Partitions After Operations
    You are given a string s and an integer k.
    First, you are allowed to change at most one index in s to another lowercase English letter.
    After that, do the following partitioning operation until s is empty:
    Choose the longest prefix of s containing at most k distinct characters.
    Delete the prefix from s and increase the number of partitions by one. The remaining characters (if any) in s maintain their initial order.
    Return an integer denoting the maximum number of resulting partitions after the operations by optimally choosing at most one index to change.

    Example :
    Input: s = "accca", k = 2
    Output: 3
    Explanation:
    The optimal way is to change s[2] to something other than a and c, for example, b. then it becomes "acbca".
    Then we perform the operations:
    The longest prefix containing at most 2 distinct characters is "ac", we remove it and s becomes "bca".
    Now The longest prefix containing at most 2 distinct characters is "bc", so we remove it and s becomes "a".
    Finally, we remove "a" and s becomes empty, so the procedure ends.
    Doing the operations, the string is divided into 3 partitions, so the answer is 3.
 */



/**
 * @param {string} s
 * @param {number} k
 * @return {number}
 */
var maxPartitionsAfterOperations = function(s, k) {
    const n = s.length;
    const L = Array.from({ length: n }, () => [0, 0, 0]);
    const R = Array.from({ length: n }, () => [0, 0, 0]);

    let num = 0, mask = 0, cnt = 0;
    for (let i = 0; i < n - 1; i++) {
        const bitMask = 1 << (s.charCodeAt(i) - 97);
        if (!(mask & bitMask)) {
            cnt++;
            if (cnt <= k)
                mask |= bitMask;
            else {
                num++;
                mask = bitMask;
                cnt = 1;
            }
        }
        L[i + 1] = [num, mask, cnt];
    }

    num = mask = cnt = 0;
    for (let i = n - 1; i > 0; i--) {
        const bitMask = 1 << (s.charCodeAt(i) - 97);
        if (!(mask & bitMask)) {
            cnt++;
            if (cnt <= k)
                mask |= bitMask;
            else {
                num++;
                mask = bitMask;
                cnt = 1;
            }
        }
        R[i - 1] = [num, mask, cnt];
    }

    let maxVal = 0;
    for (let i = 0; i < n; i++) {
        let seg = L[i][0] + R[i][0] + 2;
        const split = L[i][1] | R[i][1];
        const count = split.toString(2).split('1').length - 1;

        if (L[i][2] === k && R[i][2] === k && count < 26)
            seg += 1;
        else if (Math.min(count + 1, 26) <= k)
            seg -= 1;

        maxVal = Math.max(maxVal, seg);
    }

    return maxVal;
};