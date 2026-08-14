/**
3090. Maximum Length Substring With Two Occurrences
    Given a string s, return the maximum length of a substring such that it contains at most two occurrences of each character.
    Example :
    Input: s = "bcbbbcba"
    Output: 4
    Explanation:
    The following substring has a length of 4 and contains at most two occurrences of each character: "bcbbbcba".
 */

#include <vector>
using namespace std;

class Solution {
public:
    int maximumLengthSubstring(string s) {
        vector<int> count(26, 0);
        int left = 0;
        int ans = 0;

        for (int right = 0; right < s.size(); right++) {
            count[s[right] - 'a']++;

            while (count[s[right] - 'a'] > 2) {
                count[s[left] - 'a']--;
                left++;
            }

            ans = max(ans, right - left + 1);
        }

        return ans;
    }
};