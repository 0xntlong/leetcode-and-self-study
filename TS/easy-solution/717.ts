/**
717. 1-bit and 2-bit Characters
    We have two special characters:
    The first character can be represented by one bit 0.
    The second character can be represented by two bits (10 or 11).
    Given a binary array bits that ends with 0, return true if the last character must be a one-bit character.

    Example :
    Input: bits = [1,0,0]
    Output: true
    Explanation: The only way to decode it is two-bit character and one-bit character.
    So the last character is one-bit character.

 */


function isOneBitCharacter(bits: number[]): boolean {
    const n = bits.length;
    let i = 0;
    while (i < n - 1) {
        if (bits[i] == 1) {
            i += 2;
        } else {
            i++;
        }
    }
    return i == n - 1 && bits[i] == 0;
};