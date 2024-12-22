/*
2180. Count Interger With Even Digit Sum
    Given a positive integer num, return the number of positive integers less than or equal to num whose digit sums are even.
    The digit sum of a positive integer is the sum of all its digits.
    
    Example :
    Input: num = 4
    Output: 2
    Explanation:
    The only integers less than or equal to 4 whose digit sums are even are 2 and 4.  
*/


class Solution {
public:
    int countEven(int num) {
        int digit_sum = 0, n = num;
        while (n > 0){
            digit_sum += n % 10;
            n /= 10;
        }
        return (digit_sum % 2 == 0) ? num / 2 : (num - 1) / 2;
    }
};