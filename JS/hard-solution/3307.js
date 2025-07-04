/**
3307. Find the K-th Character in String Game II
    Alice and Bob are playing a game. Initially, Alice has a string word = "a".
    You are given a positive integer k. You are also given an integer array operations, where operations[i] represents the type of the ith operation.
    Now Bob will ask Alice to perform all operations in sequence:
    If operations[i] == 0, append a copy of word to itself.
    If operations[i] == 1, generate a new string by changing each character in word to its next character in the English alphabet, and append it to the original word. For example, performing the operation on "c" generates "cd" and performing the operation on "zb" generates "zbac".
    Return the value of the kth character in word after performing all the operations.
    Note that the character 'z' can be changed to 'a' in the second type of operation.

    Example :
    Input: k = 5, operations = [0,0,0]
    Output: "a"
    Explanation:
    Initially, word == "a". Alice performs the three operations as follows:
    Appends "a" to "a", word becomes "aa".
    Appends "aa" to "aa", word becomes "aaaa".
    Appends "aaaa" to "aaaa", word becomes "aaaaaaaa".
 */



/**
 * @param {number} k
 * @param {number[]} operations
 * @return {character}
 */
var kthCharacter = function(k, operations) {
    let ans = 0;
    while (k !== 1){
        let t = Math.floor(Math.log2(k));
        if (Number(1n << BigInt(t)) === k){
            t--;
        }
        k -= Number(1n << BigInt(t));
        if (operations[t]){
            ans++;
        }
    }
    return String.fromCharCode("a".charCodeAt(0) + (ans % 26));
};