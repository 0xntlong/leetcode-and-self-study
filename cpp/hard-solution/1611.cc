/**
1611. Minimum One Bit Operations to Make Integers Zero
    Given an integer n, you must transform it into 0 using the following operations any number of times:
    Change the rightmost (0th) bit in the binary representation of n.
    Change the ith bit in the binary representation of n if the (i-1)th bit is set to 1 and the (i-2)th through 0th bits are set to 0.
    Return the minimum number of operations to transform n into 0.
    Example :
    Input: n = 3
    Output: 2
    Explanation: The binary representation of 3 is "11".
    "11" -> "01" with the 2nd operation since the 0th bit is 1.
    "01" -> "00" with the 1st operation.
 */


class Solution {
public:
    int minimumOneBitOperations(int n) {
        if (n == 0) 
            return 0;  
        string binary = bitset<32>(n).to_string();
        int op = 0;
        int sign = 1;
        int len = binary.find('1');
        if (len == string::npos) {
            return 0;  
        }
        binary = binary.substr(len);
        for (int i = 0; i < binary.length(); i++) {
            if (binary[i] == '1') {
                op += sign * ((1 << (binary.length() - i)) - 1);
                sign *= -1;
            }
        }
        return op;
    }
};