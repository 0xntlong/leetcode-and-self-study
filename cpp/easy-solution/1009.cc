/**
1009. Complement of Base 10 Integer
    The complement of an integer is the integer you get when you flip all the 0's to 1's and all the 1's to 0's in its binary representation.

    For example, The integer 5 is "101" in binary and its complement is "010" which is the integer 2.
    Given an integer n, return its complement.

    Example :
    Input: n = 5
    Output: 2
    Explanation: 5 is "101" in binary, with complement "010" in binary, which is 2 in base-10.
 */



class Solution {
public:
    int bitwiseComplement(int n) {
        if (n == 0)
            return 1;
        int mask = 0;
        int x = n;
        while (x){
            mask = (mask << 1) | 1;
            x >>= 1;
        }
        return mask ^ n;
    }
};