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


#include <vector>
using namespace std;
class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits) {
        int i = 0;
        int n = bits.size();
        while (i < n){
            if (bits[i] == 1){
                i += 2;
            } else {
                if (i == n - 1){
                    return true;
                } else {
                    i++;
                }
            }
        }
        return false;
    }
};