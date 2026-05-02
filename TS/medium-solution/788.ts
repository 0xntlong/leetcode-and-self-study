/**
788. Rotated Digits
    An integer x is a good if after rotating each digit individually by 180 degrees, we get a valid number that is different from x. Each digit must be rotated - we cannot choose to leave it alone.
    A number is valid if each digit remains a digit after rotation. For example:
    0, 1, and 8 rotate to themselves,
    2 and 5 rotate to each other (in this case they are rotated in a different direction, in other words, 2 or 5 gets mirrored),
    6 and 9 rotate to each other, and
    the rest of the numbers do not rotate to any other number and become invalid.
    Given an integer n, return the number of good integers in the range [1, n].
    Example :
    Input: n = 10
    Output: 4
    Explanation: There are four good numbers in the range [1, 10] : 2, 5, 6, 9.
    Note that 1 and 10 are not good numbers, since they remain unchanged after rotating.
 */


function rotatedDigits(n: number): number {
    let cnt = 0;
    for (let num = 1; num <= n; num++) {
        let check = num;
        let valid = true;
        let changed = false;

        while (check > 0 && valid) {
            let digit = check % 10;
            if (digit === 3 || digit === 4 || digit === 7) {
                valid = false;
            } else if (digit === 2 || digit === 5 || digit === 6 || digit === 9) {
                changed = true;
            }
            check = Math.floor(check / 10);
        }

        if (valid && changed) 
            cnt++;

    }
    return cnt;
}