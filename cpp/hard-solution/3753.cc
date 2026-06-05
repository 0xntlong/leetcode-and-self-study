/**
3753. Total Waviness of Numbers in Range II
    You are given two integers num1 and num2 representing an inclusive range [num1, num2].
    The waviness of a number is defined as the total count of its peaks and valleys:
    A digit is a peak if it is strictly greater than both of its immediate neighbors.
    A digit is a valley if it is strictly less than both of its immediate neighbors.
    The first and last digits of a number cannot be peaks or valleys.
    Any number with fewer than 3 digits has a waviness of 0.
    Return the total sum of waviness for all numbers in the range [num1, num2].

    Example :
    Input: num1 = 120, num2 = 130
    Output: 3
    Explanation:
    In the range [120, 130]:

    120: middle digit 2 is a peak, waviness = 1.
    121: middle digit 2 is a peak, waviness = 1.
    130: middle digit 3 is a peak, waviness = 1.
    All other numbers in the range have a waviness of 0.
    Thus, total waviness is 1 + 1 + 1 = 3.
 */


#include <vector>
#include <algorithm>
using namespace std;

class Solution {
private:
    int getDir(int a, int b) {
        if (a < b) 
            return 0;
        if (a == b) 
            return 1;
        return 2;
    }

    bool matchDir(int dir1, int dir2) {
        return (dir1 == 0 && dir2 == 2) || (dir1 == 2 && dir2 == 0);
    }

    int getIndex(int pos, int tie, int lastDir, int lastDigit) {
        return ((pos * 2 + tie) * 3 + lastDir) * 10 + lastDigit;
    }

    long long helper(long long num) {
        if (num <= 0)
            return 0;
        vector<int> digits;
        while (num > 0) {
            digits.push_back(num % 10);
            num /= 10;
        }

        reverse(digits.begin(), digits.end());
        int m = digits.size();
        int size = m * 2 * 3 * 10;
        vector<long long> totalWaviness(size, 0);
        vector<long long> totalWays(size, 0);
        for (int firstPos = 0; firstPos < m; firstPos++) {
            int maxFirstDigit = firstPos == 0 ? digits[0] : 9;
            for (int firstDigit = 1; firstDigit <= maxFirstDigit; firstDigit++) {
                int tie = firstPos == 0 ? (firstDigit < digits[0]) : 1;
                int lastDir = 1;
                totalWays[getIndex(firstPos, tie, lastDir, firstDigit)]++;
            }
        }
        for (int pos = 0; pos + 1 < m; pos++) {
            for (int tie = 0; tie < 2; tie++) {
                for (int lastDir = 0; lastDir < 3; lastDir++) {
                    for (int lastDigit = 0; lastDigit < 10; lastDigit++) {
                        int idx = getIndex(pos, tie, lastDir, lastDigit);
                        if (totalWays[idx] == 0)
                            continue;
                        int maxNextDigit = tie ? 9 : digits[pos + 1];
                        for (int nextDigit = 0; nextDigit <= maxNextDigit; nextDigit++) {
                            int newTie = tie || (nextDigit < digits[pos + 1]);
                            int newDir = getDir(lastDigit, nextDigit);
                            int newIdx = getIndex(pos + 1, newTie, newDir, nextDigit);
                            totalWaviness[newIdx] += totalWaviness[idx] + totalWays[idx] * matchDir(lastDir, newDir);
                            totalWays[newIdx] += totalWays[idx];
                        }
                    }
                }
            }
        }

        long long ans = 0;
        for (int tie = 0; tie < 2; tie++) {
            for (int lastDir = 0; lastDir < 3; lastDir++) {
                for (int lastDigit = 0; lastDigit < 10; lastDigit++) {
                    ans += totalWaviness[getIndex(m - 1, tie, lastDir, lastDigit)];
                }
            }
        }
        return ans;
    }
public:
    long long totalWaviness(long long num1, long long num2) {
        return helper(num2) - helper(num1 - 1);
    }
};