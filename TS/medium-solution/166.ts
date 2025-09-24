/**
166. Fraction to Recurring Decimal
    Given two integers representing the numerator and denominator of a fraction, return the fraction in string format.
    If the fractional part is repeating, enclose the repeating part in parentheses.
    If multiple answers are possible, return any of them.
    It is guaranteed that the length of the answer string is less than 104 for all the given inputs.

    Example:
    Input: numerator = 1, denominator = 2
    Output: "0.5"
 */




function fractionToDecimal(numerator: number, denominator: number): string {
    if (numerator === 0){
        return "0";
    }
    let res = (numerator < 0) !== (denominator < 0) ? "-" : "";
    let n = Math.abs(numerator);
    let d = Math.abs(denominator);
    let integer = Math.floor(n / d);
    let rem = n % d;
    res  += integer;
    if (rem === 0){
        return res;
    }
    res += ".";
    const pos = new Map();
    while (rem !== 0){
        if (pos.has(rem)){
            const idx = pos.get(rem);
            res = res.slice(0, idx) + "(" + res.slice(idx) + ")";
            break;
        }
        pos.set(rem, res.length);
        rem *= 10;
        res += Math.floor(rem / d);
        rem %= d;
    }
    return res;
};