/**
2075. Decode the Slanted Ciphertext
    A string originalText is encoded using a slanted transposition cipher to a string encodedText with the help of a matrix having a fixed number of rows rows.
    originalText is placed first in a top-left to bottom-right manner.
    The blue cells are filled first, followed by the red cells, then the yellow cells, and so on, until we reach the end of originalText. The arrow indicates the order in which the cells are filled. All empty cells are filled with ' '. The number of columns is chosen such that the rightmost column will not be empty after filling in originalText.
    encodedText is then formed by appending all characters of the matrix in a row-wise fashion.
    The characters in the blue cells are appended first to encodedText, then the red cells, and so on, and finally the yellow cells. The arrow indicates the order in which the cells are accessed.
    For example, if originalText = "cipher" and rows = 3, then we encode it in the following manner:
    The blue arrows depict how originalText is placed in the matrix, and the red arrows denote the order in which encodedText is formed. In the above example, encodedText = "ch ie pr".
    Given the encoded string encodedText and number of rows rows, return the original string originalText.
    Note: originalText does not have any trailing spaces ' '. The test cases are generated such that there is only one possible originalText.

    Example:
    Input: encodedText = "ch   ie   pr", rows = 3
    Output: "cipher"
    Explanation: This is the same example described in the problem description.
 */

/**
 * @param {string} encodedText
 * @param {number} rows
 * @return {string}
 */
var decodeCiphertext = function(encodedText, rows) {
    if (rows === 1) 
        return encodedText;
    
    const n = encodedText.length;
    const cols = n / rows;
    let i = 0, j = 0, k = 0;
    let dec = '';
    
    while (k < n) {
        dec += encodedText[k];
        i++;
        if (i === rows) {
            i = 0;
            j++;
        }
        k = i * (cols + 1) + j;
    }
    
    while (dec.length > 0 && dec[dec.length - 1] === ' ') {
        dec = dec.slice(0, -1);
    }

    return dec;
};
    