/*
1957. Delete Characters to Make Fancy String
    A fancy string is a string where no three consecutive characters are equal.
    Given a string s, delete the minimum possible number of characters from s to make it fancy.
    Return the final string after the deletion. It can be shown that the answer will always be unique.

    Example:
    leeetcode"
    Output: "leetcode"
    Explanation:
    Remove an 'e' from the first group of 'e's to create "leetcode".
    No three consecutive characters are equal, so return "leetcode".
*/


function makeFancyString(s: string): string {
    if (s.length < 3) 
        return s;

    let result = s[0];
    let prev = s[0];
    let flag = false;

    for (let i = 1; i < s.length; i++) {
        const c = s[i];
        if (c !== prev) {
            result += c;
            prev = c;
            flag = false;
        } else if (!flag) {
            result += c;
            flag = true;
        }
    }

    return result;
};