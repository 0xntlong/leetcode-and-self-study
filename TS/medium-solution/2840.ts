/**
2840. Check if Strings Can be Made Equal With Operations II
    You are given two strings s1 and s2, both of length n, consisting of lowercase English letters.
    You can apply the following operation on any of the two strings any number of times:
    Choose any two indices i and j such that i < j and the difference j - i is even, then swap the two characters at those indices in the string.
    Return true if you can make the strings s1 and s2 equal, and false otherwise.

    Example :
    Input: s1 = "abcdba", s2 = "cabdab"
    Output: true
    Explanation: We can apply the following operations on s1:
    - Choose the indices i = 0, j = 2. The resulting string is s1 = "cbadba".
    - Choose the indices i = 2, j = 4. The resulting string is s1 = "cbbdaa".
    - Choose the indices i = 1, j = 5. The resulting string is s1 = "cabdab" = s2.

*/

function checkStrings(s1: string, s2: string): boolean {
    const odds_s1 = new Array(26).fill(0);  
    const evens_s1 = new Array(26).fill(0);  
    const odds_s2 = new Array(26).fill(0);  
    const evens_s2 = new Array(26).fill(0);  

    for (let i = 1; i < s1.length; i += 2) {
        odds_s1[s1[i].charCodeAt(0) - 'a'.charCodeAt(0)]++;
    }

    for (let i = 0; i < s1.length; i += 2) {
        evens_s1[s1[i].charCodeAt(0) - 'a'.charCodeAt(0)]++;
    }

    for (let i = 1; i < s2.length; i += 2) {
        odds_s2[s2[i].charCodeAt(0) - 'a'.charCodeAt(0)]++;
    }

    for (let i = 0; i < s2.length; i += 2) {
        evens_s2[s2[i].charCodeAt(0) - 'a'.charCodeAt(0)]++;
    }

    for (let i = 0; i < 26; i++) {
        if (odds_s1[i] !== odds_s2[i] || evens_s1[i] !== evens_s2[i]) {
            return false; 
        }
    }

    return true;
};