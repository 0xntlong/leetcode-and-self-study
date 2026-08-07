/**
3348. Smallest Divisible Digit Product II
    You are given a string num which represents a positive integer, and an integer t.
    A number is called zero-free if none of its digits are 0.
    Return a string representing the smallest zero-free number greater than or equal to num such that the product of its digits is divisible by t. If no such number exists, return "-1".

    Example :
    Input: num = "1234", t = 256
    Output: "1488"
    Explanation:
    The smallest zero-free number that is greater than 1234 and has the product of its digits divisible by 256 is 1488, with the product of its digits equal to 256.
 */


#include <string>
#include <vector>
using namespace std;
#include <algorithm> 

class Solution {
public:
    string smallestNumber(string num, long long t) {
        long long temp = t;

        for (int digit = 2; digit <= 9; digit++) {
            while (temp % digit == 0) {
                temp /= digit;
            }
        }

        if (temp != 1) {
            return "-1";
        }

        int n = num.size();
        vector<char> digits(num.begin(), num.end());

        vector<long long> remaining(n + 1, 0);
        remaining[0] = t;

        int lastValidPos = n - 1;

        for (int i = 0; i < n; i++) {
            int digit = digits[i] - '0';

            if (digit == 0) {
                lastValidPos = i;
                break;
            }

            long long common = gcd(remaining[i], (long long)digit);
            remaining[i + 1] = remaining[i] / common;
        }

        if (remaining[n] == 1) {
            return num;
        }

        for (int i = lastValidPos; i >= 0; i--) {
            int currentDigit = digits[i] - '0';

            for (int newDigit = currentDigit + 1; newDigit <= 9; newDigit++) {
                digits[i] = char('0' + newDigit);

                long long need = remaining[i];
                need /= gcd(need, (long long)newDigit);

                vector<char> suffix;

                for (int j = i + 1; j < n; j++) {
                    int chosenDigit = 9;

                    while (chosenDigit > 1 && need % chosenDigit != 0) {
                        chosenDigit--;
                    }

                    if (need % chosenDigit == 0) {
                        need /= chosenDigit;
                    }

                    suffix.push_back(char('0' + chosenDigit));
                }

                if (need == 1) {
                    reverse(suffix.begin(), suffix.end());

                    for (int j = i + 1; j < n; j++) {
                        digits[j] = suffix[j - i - 1];
                    }

                    return string(digits.begin(), digits.end());
                }
            }

            digits[i] = num[i];
        }

        vector<char> factors;
        long long remainingT = t;

        for (int digit = 9; digit >= 2; digit--) {
            while (remainingT % digit == 0) {
                factors.push_back(char('0' + digit));
                remainingT /= digit;
            }
        }

        int requiredLength = max(n + 1, (int)factors.size());

        while ((int)factors.size() < requiredLength) {
            factors.push_back('1');
        }

        reverse(factors.begin(), factors.end());

        return string(factors.begin(), factors.end());

    }
};