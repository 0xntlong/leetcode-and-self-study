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

#include <vector>
#include <cmath>
using namespace std;
class Solution {
public:
    int convert(vector<int>bits){
        int n = bits[31];
        for (int i = 0; i< 31; i++){
            n = n + bits[i] * pow(2, 31 - i);
        }
        return n;
    }
    int reverseBits(int n) {
        vector<int> bits(32, 0);
        int i = 0;
        int num = n;
        while (num != 0){
            int rem = num % 2;
            bits[i] = rem;
            num = num / 2;
            i++;
        }
        return convert(bits);
    }
};