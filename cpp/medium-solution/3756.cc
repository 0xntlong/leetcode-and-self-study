/**
3756. Concatenate Non-Zero Digits and Multiply by Sum II
    You are given a string s of length m consisting of digits. You are also given a 2D integer array queries, where queries[i] = [li, ri].
    For each queries[i], extract the substring s[li..ri]. Then, perform the following:
    Form a new integer x by concatenating all the non-zero digits from the substring in their original order. If there are no non-zero digits, x = 0.
    Let sum be the sum of digits in x. The answer is x * sum.
    Return an array of integers answer where answer[i] is the answer to the ith query.
    Since the answers may be very large, return them modulo 109 + 7.

    Example :
    Input: s = "10203004", queries = [[0,7],[1,3],[4,6]]
    Output: [12340, 4, 9]
    Explanation:
    s[0..7] = "10203004"
    x = 1234
    sum = 1 + 2 + 3 + 4 = 10
    Therefore, answer is 1234 * 10 = 12340.
    s[1..3] = "020"
    x = 2
    sum = 2
    Therefore, the answer is 2 * 2 = 4.
    s[4..6] = "300"
    x = 3
    sum = 3
    Therefore, the answer is 3 * 3 = 9.
 */


#include <vector>
#include <string>
using namespace std;
class Solution {
public:
    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
        const int MOD = 1000000007;
        int n = s.size();

        vector<int> idx(n + 1, 0);
        vector<long long> val(n + 1, 0);
        vector<long long> total(n + 1, 0);
        vector<long long> pow10(n + 1, 1);

        for (int i = 1; i <= n; i++) {
            pow10[i] = pow10[i - 1] * 10 % MOD;
        }

        int count = 0;

        for (int i = 0; i < n; i++) {
            int digit = s[i] - '0';

            if (digit != 0) {
                count++;
                val[count] = (val[count - 1] * 10 + digit) % MOD;
                total[count] = total[count - 1] + digit;
            }

            idx[i + 1] = count;
        }

        vector<int> ans;

        for (auto& q : queries) {
            int left = q[0];
            int right = q[1];

            int a = idx[left];
            int b = idx[right + 1];

            if (a == b) {
                ans.push_back(0);
                continue;
            }

            int length = b - a;

            long long num = (val[b] - val[a] * pow10[length]) % MOD;
            if (num < 0) num += MOD;

            long long digitSum = total[b] - total[a];

            ans.push_back(num * digitSum % MOD);
        }

        return ans;
    }
};