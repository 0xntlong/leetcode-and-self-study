/**
1935. Maximum Number of Words You Can Type
    There is a malfunctioning keyboard where some letter keys do not work. All other keys on the keyboard work properly.
    Given a string text of words separated by a single space (no leading or trailing spaces) and a string brokenLetters of all distinct letter keys that are broken, return the number of words in text you can fully type using this keyboard.
    Example :
    Input: text = "hello world", brokenLetters = "ad"
    Output: 1
    Explanation: We cannot type "world" because the 'd' key is broken.
 */




/**
 * @param {string} text
 * @param {string} brokenLetters
 * @return {number}
 */
var canBeTypedWords = function(text, brokenLetters) {
    const st = new Set(brokenLetters.split(""));
    text = text.split(' ');
    let cnt = 0;
    for (let w of text){
        for (const char of w){
            if (st.has(char)){
                cnt++;
                break;
            }
        }
    }
    return text.length - cnt;
};