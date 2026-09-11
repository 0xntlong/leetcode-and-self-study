/**
3483. Unique 3-Digit Even Numbers
    You are given an array of digits called digits. Your task is to determine the number of distinct three-digit even numbers that can be formed using these digits.
    Note: Each copy of a digit can only be used once per number, and there may not be leading zeros.

    Example :
    Input: digits = [1,2,3,4]
    Output: 12
    Explanation: The 12 distinct 3-digit even numbers that can be formed are 124, 132, 134, 142, 214, 234, 312, 314, 324, 342, 412, and 432. Note that 222 cannot be formed because there is only 1 copy of the digit 2.
 */


#include <vector>
using namespace std;

class Solution {
public:
    int totalNumbers(vector<int>& digits) {
        int freq[10] = {0};
        bool uniqEven[10] = {false};
        int count = 0;

        for (int d : digits) {
            if (d % 2 == 0) {
                uniqEven[d] = true;
            }
            freq[d]++;
        }

        for (int e = 0; e <= 9; e++) {
            if (!uniqEven[e]) {
                continue;
            }

            freq[e]--;

            vector<int> keys;

            for (int d = 0; d <= 9; d++) {
                if (freq[d] > 0) {
                    keys.push_back(d);
                }
            }

            for (int i = 0; i < keys.size(); i++) {
                for (int j = i + 1; j < keys.size(); j++) {
                    int a = keys[i];
                    int b = keys[j];

                    if (a != 0) {
                        count++;
                    }

                    if (b != 0) {
                        count++;
                    }
                }
            }

            for (int num : keys) {
                if (freq[num] >= 2 && num != 0) {
                    count++;
                }
            }

            freq[e]++;
        }

        return count;
    }
};