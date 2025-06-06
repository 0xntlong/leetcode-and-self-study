/**
2434. Using a Robot to Print the Lexicographically Smallest String
    You are given a string s and a robot that currently holds an empty string t. Apply one of the following operations until s and t are both empty:
    Remove the first character of a string s and give it to the robot. The robot will append this character to the string t.
    Remove the last character of a string t and give it to the robot. The robot will write this character on paper.
    Return the lexicographically smallest string that can be written on the paper.

    Example :
    Input: s = "zza"
    Output: "azz"
    Explanation: Let p denote the written string.
    Initially p="", s="zza", t="".
    Perform first operation three times p="", s="", t="zza".
    Perform second operation three times p="azz", s="", t="".
 */


/**
 * @param {string} s
 * @return {string}
 */
var robotWithString = function(s) {
    let n = s.length;
    let min_c = new Array(n);
    min_c[n - 1] = s.charAt(n - 1);
    for (let i = n - 2; i >= 0; i--){
        min_c[i] = String.fromCharCode(Math.min(s.charCodeAt(i), min_c[i + 1].charCodeAt(0)));
    }
    let p = '';
    let t = [];
    for (let i = 0; i < n; i++){
        t.push(s.charAt(i));
        while (t.length > 0 && (i === n - 1 || t[t.length - 1] <= min_c[i + 1])){
            p += t.pop();
        }
    }
    return p;
};