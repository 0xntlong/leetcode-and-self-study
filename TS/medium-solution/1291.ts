/**
1291. Sequential Digits
    An integer has sequential digits if and only if each digit in the number is one more than the previous digit.
    Return a sorted list of all the integers in the range [low, high] inclusive that have sequential digits.

    Example :
    Input: low = 100, high = 300
    Output: [123,234]
 */


function sequentialDigits(low: number, high: number): number[] {
    const digits = "123456789";
    const res: number[] = [];

    const n = String(low).length;
    const m = String(high).length;

    for (let length = n; length <= m; length++) {
        for (let i = 0; i < 10 - length; i++) {
            const num = Number(digits.slice(i, i + length));

            if (low <= num && num <= high) {
                res.push(num);
            }
        }
    }

    return res;
}