/**
2785. Sort Vowels in a String
    Given a 0-indexed string s, permute s to get a new string t such that:
    All consonants remain in their original places. More formally, if there is an index i with 0 <= i < s.length such that s[i] is a consonant, then t[i] = s[i].
    The vowels must be sorted in the nondecreasing order of their ASCII values. More formally, for pairs of indices i, j with 0 <= i < j < s.length such that s[i] and s[j] are vowels, then t[i] must not have a higher ASCII value than t[j].
    Return the resulting string.
    The vowels are 'a', 'e', 'i', 'o', and 'u', and they can appear in lowercase or uppercase. Consonants comprise all letters that are not vowels.

    Example :
    Input: s = "lEetcOde"
    Output: "lEOtcede"
    Explanation: 'E', 'O', and 'e' are the vowels in s; 'l', 't', 'c', and 'd' are all consonants. The vowels are sorted according to their ASCII values, and the consonants remain in the same places.
 */




/**
 * @param {string} s
 * @return {string}
 */
var sortVowels = function(s) {
    const vowels = "AEIOUaeiou";
    let vowelList = [];
    for (let c of s){
        if (vowels.indexOf(c) !== -1){
            vowelList.push(c);
        }
    }
    vowelList.sort();
    let res = "";
    let vowelIdx = 0;
    for (let c of s){
        if (vowels.indexOf(c) !== -1){
            res += vowelList[vowelIdx++];
        } else {
            res += c;
        }
    }
    return res;
};