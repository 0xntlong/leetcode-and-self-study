/*
2119. A Number After a Double Reversal
    Reversing an integer means to reverse all its digits.
    For example, reversing 2021 gives 1202. Reversing 12300 gives 321 as the leading zeros are not retained.
    Given an integer num, reverse num to get reversed1, then reverse reversed1 to get reversed2. Return true if reversed2 equals num. Otherwise return false.

    Example :
    Input: num = 526
    Output: true
    Explanation: Reverse num to get 625, then reverse 625 to get 526, which equals num.
*/


class Solution {
public:
    bool isSameAfterReversals(int num) {
        auto reverse_num = [](int n){
            int reversed = 0;
            while (n > 0){
                reversed = reversed * 10 + n % 10;
                n /= 10;
            }
            return reversed;
        };
        int reversed1 = reverse_num(num);
        int reversed2 = reverse_num(reversed1);
        return num == reversed2;
    }
};