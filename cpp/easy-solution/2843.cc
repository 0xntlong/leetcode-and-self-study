/*
2843. Count Symmetric Integers
    You are given two positive integers low and high.
    An integer x consisting of 2 * n digits is symmetric if the sum of the first n digits of x is equal to the sum of the last n digits of x. Numbers with an odd number of digits are never symmetric.
    Return the number of symmetric integers in the range [low, high].

    Example :
    Input: low = 1, high = 100
    Output: 9
    Explanation: There are 9 symmetric integers between 1 and 100: 11, 22, 33, 44, 55, 66, 77, 88, and 99.
*/


class Solution {
    public:
        int countSymmetricIntegers(int low, int high) {
            int count = 0;
            for (int num = low; num <= high; num++){
                string s = to_string(num);
                if (s.length() % 2 == 0){
                    int mid = s.length() / 2;
                    int sum_left = 0, sum_right = 0;
                    for (int i = 0; i < mid; i++){
                        sum_left += s[i] - '0';
                    }
                    for (int i = mid; i < s.length(); i++){
                        sum_right += s[i] - '0';
                    }
                    if (sum_left == sum_right){
                        count++;
                    }
                }
            }
            return count;
        }
    };