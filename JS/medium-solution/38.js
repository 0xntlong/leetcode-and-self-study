/**
38. Count and Say
    The count-and-say sequence is a sequence of digit strings defined by the recursive formula:
    countAndSay(1) = "1"
    countAndSay(n) is the run-length encoding of countAndSay(n - 1).
    Run-length encoding (RLE) is a string compression method that works by replacing consecutive identical characters (repeated 2 or more times) with the concatenation of the character and the number marking the count of the characters (length of the run). For example, to compress the string "3322251" we replace "33" with "23", replace "222" with "32", replace "5" with "15" and replace "1" with "11". Thus the compressed string becomes "23321511".
    Given a positive integer n, return the nth element of the count-and-say sequence.

    Example 1:
    Input: n = 4
    Output: "1211"
    Explanation:
    countAndSay(1) = "1"
    countAndSay(2) = RLE of "1" = "11"
    countAndSay(3) = RLE of "11" = "21"
    countAndSay(4) = RLE of "21" = "1211"
 */


    /**
 * @param {number} n
 * @return {string}
 */
var countAndSay = function(n) {
    if (n === 1) {
        return "1";
    }

    const str = (sequence) => {
        let result = "";
        for (const [freq, digit] of sequence) {
            result += freq.toString() + digit;
        }
        return result;
    };

    let sequence = [[1, '1']];
    let s1 = str(sequence);

    for (let i = 3; i <= n; i++) {
        const len = s1.length;
        let c = s1[0];
        sequence = [[1, c]];

        for (let j = 1; j < len; j++) {
            if (s1[j] === c) {
                sequence[sequence.length - 1][0]++;
            } else {
                sequence.push([1, s1[j]]);
                c = s1[j];
            }
        }

        s1 = str(sequence);
    }

    return s1;
};