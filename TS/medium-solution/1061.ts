/**
1061. Lexicographically Smallest Equivalent String
    You are given two strings of the same length s1 and s2 and a string baseStr.
    We say s1[i] and s2[i] are equivalent characters.
    For example, if s1 = "abc" and s2 = "cde", then we have 'a' == 'c', 'b' == 'd', and 'c' == 'e'.
    Equivalent characters follow the usual rules of any equivalence relation:
    Reflexivity: 'a' == 'a'.
    Symmetry: 'a' == 'b' implies 'b' == 'a'.
    Transitivity: 'a' == 'b' and 'b' == 'c' implies 'a' == 'c'.
    For example, given the equivalency information from s1 = "abc" and s2 = "cde", "acd" and "aab" are equivalent strings of baseStr = "eed", and "aab" is the lexicographically smallest equivalent string of baseStr.
    Return the lexicographically smallest equivalent string of baseStr by using the equivalency information from s1 and s2.

    Example :
    Input: s1 = "parker", s2 = "morris", baseStr = "parser"
    Output: "makkek"
    Explanation: Based on the equivalency information in s1 and s2, we can group their characters as [m,p], [a,o], [k,r,s], [e,i].
    The characters in each group are equivalent and sorted in lexicographical order.
    So the answer is "makkek".
 */

function smallestEquivalentString(s1: string, s2: string, baseStr: string): string {
    let root : string[] = Array(26);
    for (let i = 0; i < 26; i++){
        root[i] = String.fromCharCode(97 + i);
    }
    function find (x : string): string {
        if (root[x.charCodeAt(0) - 97] !== x){
            root[x.charCodeAt(0) - 97] = find(root[x.charCodeAt(0) - 97]);
        }
        return root[x.charCodeAt(0) - 97];
    }
    function unionSet(x : string, y : string): void {
        let r1 = find(x);
        let r2 = find(y);
        if (r1 !== r2){
            if (r1 < r2){
                root[r2.charCodeAt(0) - 97] = r1;
            } else {
                root[r1.charCodeAt(0) - 97] = r2;
            }
        }
    }
    for (let i = 0; i < s1.length; i++){
        unionSet(s1[i], s2[i]);
    }
    let res = "";
    for (let i = 0; i < baseStr.length; i++){
        res += find(baseStr[i]);
    }
    return res;
};