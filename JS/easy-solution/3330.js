/**
3330. Find the Original Typed String I
    Alice is attempting to type a specific string on her computer. However, she tends to be clumsy and may press a key for too long, resulting in a character being typed multiple times.
    Although Alice tried to focus on her typing, she is aware that she may still have done this at most once.
    You are given a string word, which represents the final output displayed on Alice's screen.
    Return the total number of possible original strings that Alice might have intended to type.

    Example 1:
    Input: word = "abbcccc"
    Output: 5
    Explanation:
    The possible strings are: "abbcccc", "abbccc", "abbcc", "abbc", and "abcccc".
 */



/**
 * @param {string} word
 * @return {number}
 */
var possibleStringCount = function(word) {
    const n = word.length;
    let cnt = 0;
    for (let i = 1; i < n; i++){
        if (word[i] !== word[i - 1]){
            cnt++;
        }
    }
    return n - cnt;
};