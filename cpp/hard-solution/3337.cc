/*
3337. Total Characters in String After Transformations II
    You are given a string s consisting of lowercase English letters, an integer t representing the number of transformations to perform, and an array nums of size 26. In one transformation, every character in s is replaced according to the following rules:
    Replace s[i] with the next nums[s[i] - 'a'] consecutive characters in the alphabet. For example, if s[i] = 'a' and nums[0] = 3, the character 'a' transforms into the next 3 consecutive characters ahead of it, which results in "bcd".
    The transformation wraps around the alphabet if it exceeds 'z'. For example, if s[i] = 'y' and nums[24] = 3, the character 'y' transforms into the next 3 consecutive characters ahead of it, which results in "zab".
    Return the length of the resulting string after exactly t transformations.
    Since the answer may be very large, return it modulo 109 + 7.
    Example :
    Input: s = "abcyy", t = 2, nums = [1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,2]
    Output: 7
    Explanation:
    First Transformation (t = 1):

    'a' becomes 'b' as nums[0] == 1
    'b' becomes 'c' as nums[1] == 1
    'c' becomes 'd' as nums[2] == 1
    'y' becomes 'z' as nums[24] == 1
    'y' becomes 'z' as nums[24] == 1
    String after the first transformation: "bcdzz"
    Second Transformation (t = 2):
    'b' becomes 'c' as nums[1] == 1
    'c' becomes 'd' as nums[2] == 1
    'd' becomes 'e' as nums[3] == 1
    'z' becomes 'ab' as nums[25] == 2
    'z' becomes 'ab' as nums[25] == 2
    String after the second transformation: "cdeabab"
    Final Length of the string: The string is "cdeabab", which has 7 characters.
 */

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
class Solution {
public:
    int lengthAfterTransformations(string s, int t, vector<int>& nums) {
        const int mod = 1e9 + 7;
        vector<vector<int>> matrix(26, vector<int>(26, 0));
        for (int c = 0; c < 26; c++) {
            int num = nums[c];
            for (int j = 1; j <= num; j++) {
                int next_c = (c + j) % 26;
                matrix[c][next_c]++;
            }
        }
        auto matrix_multi = [&](vector<vector<int>>& x, vector<vector<int>>& y) {
            vector<vector<int>> res(26, vector<int>(26, 0));
            for (int i = 0; i < 26; i++) {
                for (int j = 0; j < 26; j++) {
                    for (int l = 0; l < 26; l++) {
                        res[i][l] = (res[i][l] + 1LL * x[i][j] * y[j][l]) % mod;
                    }
                }
            }
            return res;
        };
        auto matrix_pol = [&](vector<vector<int>>& m, int n) {
            vector<vector<int>> total(26, vector<int>(26, 0));
            for (int i = 0; i < 26; i++) {
                total[i][i] = 1; 
            }

            while (n > 0) {
                if (n % 2 == 1) {
                    total = matrix_multi(total, m);
                }
                m = matrix_multi(m, m);
                n /= 2;
            }

            return total;
        };
        vector<vector<int>> compute = matrix_pol(matrix, t);
        vector<int> cnt(26, 0);
        for (char c : s) {
            cnt[c - 'a']++;
        }
        vector<int> new_cnt(26, 0);
        for (int i = 0; i < 26; i++) {
            for (int j = 0; j < 26; j++) {
                new_cnt[j] = (new_cnt[j] + 1LL * cnt[i] * compute[i][j]) % mod;
            }
        }
        int result = 0;
        for (int x : new_cnt) {
            result = (result + x) % mod;
        }
        return result;
    }
};