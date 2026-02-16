/**
190. Reverse Bits
    Reverse bits of a given 32 bits signed integer.
    Example :
    Input: n = 43261596
    Output: 964176192
    Explanation:
    Integer	Binary
    43261596	00000010100101000001111010011100
    964176192	00111001011110000010100101000000
 */



function reverseBits(n: number): number {
    const bits: number[] = new Array(32).fill(0);
    let i = 0;
    let num = n >>> 0;

    while (num !== 0 && i < 32) {
        bits[i] = num & 1;
        num = num >>> 1;
        i++;
    }

    let res = bits[31] >>> 0;
    for (let k = 0; k < 31; k++) {
        res = (res + (bits[k] << (31 - k))) >>> 0;
    }
    return res >>> 0;
};