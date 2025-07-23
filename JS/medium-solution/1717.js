/**
1717. Maximum Score From Removing Substrings
    You are given a string s and two integers x and y. You can perform two types of operations any number of times.
    Remove substring "ab" and gain x points.
    For example, when removing "ab" from "cabxbae" it becomes "cxbae".
    Remove substring "ba" and gain y points.
    For example, when removing "ba" from "cabxbae" it becomes "cabxe".
    Return the maximum points you can gain after applying the above operations on s.

    Example :
    Input: s = "cdbcbbaaabab", x = 4, y = 5
    Output: 19
    Explanation:
    - Remove the "ba" underlined in "cdbcbbaaabab". Now, s = "cdbcbbaaab" and 5 points are added to the score.
    - Remove the "ab" underlined in "cdbcbbaaab". Now, s = "cdbcbbaa" and 4 points are added to the score.
    - Remove the "ba" underlined in "cdbcbbaa". Now, s = "cdbcba" and 5 points are added to the score.
    - Remove the "ba" underlined in "cdbcba". Now, s = "cdbc" and 5 points are added to the score.
    Total score = 5 + 4 + 5 + 5 = 19.
 */


/**
 * @param {string} s
 * @param {number} x
 * @param {number} y
 * @return {number}
 */
var maximumGain = function(s, x, y) {
    if (x > y){
        return getMax(s, 'a', 'b', x, y);
    } else {
        return getMax(s, 'b', 'a', y, x);
    }
    function getMax(s, a , b, x, y){
        let c1 = 0, c2 = 0, ans = 0;
        s += 'c';
        for (let c of s){
            if (c === a){
                c1++;
            } else if (c === b){
                if (c1 === 0){
                    c2++;
                } else {
                    ans += x;
                    c1--;
                }
            } else {
                ans += y * Math.min(c1, c2);
                c1 = c2 = 0;
            }
        }
        return ans;
    }
};