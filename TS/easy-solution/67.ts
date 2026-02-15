/**
67. Add Binary
    Given two binary strings a and b, return their sum as a binary string.

    Example :
    Input: a = "11", b = "1"
    Output: "100"
 */

function addBinary(a: string, b: string): string {
    let res: string[] = [];
    let carry = 0;
    let i = a.length - 1;
    let j = b.length - 1;

    while (i >= 0 || j >= 0 || carry) {
        let total = carry;

        if (i >= 0) 
            total += Number(a[i--]);
        if (j >= 0) 
            total += Number(b[j--]);

        res.push(String(total % 2));
        carry = Math.floor(total / 2);
    }

    return res.reverse().join("");
};