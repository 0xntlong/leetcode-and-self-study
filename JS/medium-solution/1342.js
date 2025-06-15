/**
1432. Max Difference You Can Get From Changing an Integer
    You are given an integer num. You will apply the following steps to num two separate times:
    Pick a digit x (0 <= x <= 9).
    Pick another digit y (0 <= y <= 9). Note y can be equal to x.
    Replace all the occurrences of x in the decimal representation of num by y.
    Let a and b be the two results from applying the operation to num independently.
    Return the max difference between a and b.
    Note that neither a nor b may have any leading zeros, and must not be 0.

    Example :
    Input: num = 555
    Output: 888
    Explanation: The first time pick x = 5 and y = 9 and store the new integer in a.
    The second time pick x = 5 and y = 1 and store the new integer in b.
    We have now a = 999 and b = 111 and max difference = 888
 */



/**
 * @param {number} num
 * @return {number}
 */
var maxDiff = function(num) {
    let ten = Array(10).fill(1);
    for (let i = 1; i < 10; i++){
        ten[i] = ten[i - 1] * 10;
    }
    let value = 1;
    for (let i = 0; i < 10; i++){
        if (ten[i] > num){
            value = ten[i - 1];
            break;
        }
    }
    let a = -1, b = -1, x = 0, y = 0;
    const c = Math.floor(num / value) === 1 ? 0 : 1;

    while (value >= 1){
        const d = Math.floor(num / value);
        num %= value;
        if (a === -1 && d !== 9){
            a = d;
            x += 9 * value;
        } else if (d === a){
            x += 9 * value;
        } else {
            x += d * value;
        }
        if (b === -1 && d !== 0 && d !== 1){
            b = d;
            y += c * value;
        } else if (d === b){
            y += c * value;
        } else {
            y += d * value;
        }
        value = Math.floor(value / 10);
    }
    return x - y;
};