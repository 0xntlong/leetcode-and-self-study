/**
3136. Valid Word
    A word is considered valid if:
    It contains a minimum of 3 characters.
    It contains only digits (0-9), and English letters (uppercase and lowercase).
    It includes at least one vowel.
    It includes at least one consonant.
    You are given a string word.
    Return true if word is valid, otherwise, return false.
    Notes:
    'a', 'e', 'i', 'o', 'u', and their uppercases are vowels.
    A consonant is an English letter that is not a vowel.

    Example :
    Input: word = "234Adas"
    Output: true
    Explanation:
    This word satisfies the conditions.
 */



/**
 * @param {string} word
 * @return {boolean}
 */
var isValid = function(word) {
    if (word.length < 3)
        return false;
    const vowels = new Set("aeiouAEIOU");
    let hasVowels = false;
    let hasCons = false;
    for (const c of word){
        if (!/[a-zA-Z0-9]/.test(c)){
                return false;
        }
        if (/[a-zA-Z]/.test(c)){
            if (vowels.has(c)){
                hasVowels = true;
            } else {
                hasCons = true;
            }
        }
    }
    return hasVowels && hasCons;
};