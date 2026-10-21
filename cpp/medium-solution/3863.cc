/**
3863. Minimum Operations to Sort a String
    You are given a string s consisting of lowercase English letters.
    In one operation, you can select any substring of s that is not the entire string and sort it in non-descending alphabetical order.
    Return the minimum number of operations required to make s sorted in non-descending order. If it is not possible, return -1.

    Example :
    Input: s = "dog"
    Output: 1
    Explanation:
    Sort substring "og" to "go".
    Now, s = "dgo", which is sorted in ascending order. Thus, the answer is 1.
 */


#include <algorithm>
#include <string>
using namespace std;
class Solution {
public:
    int minOperations(string s) {
        int n = s.size();

        if (n == 2 && s[0] > s[1]) {
            return -1;
        }

        if (is_sorted(s.begin(), s.end())) {
            return 0;
        }

        auto [mnIt, mxIt] = minmax_element(
            s.begin() + 1, s.end() - 1
        );

        char mn = *mnIt;
        char mx = *mxIt;

        char left = s[0];
        char right = s.back();

        if (left <= min(right, mn) ||
            right >= max(left, mx)) {
            return 1;
        } else if (right >= mn || left <= mx) {
            return 2;
        } else {
            return 3;
        }
    }
};