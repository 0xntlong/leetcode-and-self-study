/**
3499. Maximize Active Section with Trade I
    You are given a binary string s of length n, where:

    '1' represents an active section.
    '0' represents an inactive section.
    You can perform at most one trade to maximize the number of active sections in s. In a trade, you:

    Convert a contiguous block of '1's that is surrounded by '0's to all '0's.
    Afterward, convert a contiguous block of '0's that is surrounded by '1's to all '1's.
    Return the maximum number of active sections in s after making the optimal trade.

    Note: Treat s as if it is augmented with a '1' at both ends, forming t = '1' + s + '1'. The augmented '1's do not contribute to the final count.

    Example 1:
    Input: s = "01"
    Output: 1
    Explanation:
    Because there is no block of '1's surrounded by '0's, no valid trade is possible. The maximum number of active sections is 1.
 */

#include <string>
#include <vector>
#include <algorithm> 
using namespace std;

class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        int ones = count(s.begin(), s.end(), '1');

        string paddedS = "1" + s + "1";
        vector<int> zeroRuns;

        int length = 0;

        for (char c : paddedS) {
            if (c == '0') {
                length++;
            } else if (length > 0) {
                zeroRuns.push_back(length);
                length = 0;
            }
        }

        if (zeroRuns.size() < 2) {
            return ones;
        }

        int best = 0;

        for (int i = 0; i + 1 < zeroRuns.size(); i++) {
            best = max(best, zeroRuns[i] + zeroRuns[i + 1]);
        }

        return ones + best;
    }
};