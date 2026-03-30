/**
2840. Check if Strings Can be Made Equal With Operations II
    You are given two strings s1 and s2, both of length n, consisting of lowercase English letters.
    You can apply the following operation on any of the two strings any number of times:
    Choose any two indices i and j such that i < j and the difference j - i is even, then swap the two characters at those indices in the string.
    Return true if you can make the strings s1 and s2 equal, and false otherwise.

    Example :
    Input: s1 = "abcdba", s2 = "cabdab"
    Output: true
    Explanation: We can apply the following operations on s1:
    - Choose the indices i = 0, j = 2. The resulting string is s1 = "cbadba".
    - Choose the indices i = 2, j = 4. The resulting string is s1 = "cbbdaa".
    - Choose the indices i = 1, j = 5. The resulting string is s1 = "cabdab" = s2.

*/


class Solution {
public:
    bool checkStrings(string s1, string s2) {
        unordered_map<char, int> odds_s1, evens_s1;
        unordered_map<char, int> odds_s2, evens_s2;

        for (int i = 1; i < s1.size(); i += 2) {
            odds_s1[s1[i]]++;
        }
        for (int i = 0; i < s1.size(); i += 2) {
            evens_s1[s1[i]]++;
        }

        for (int i = 1; i < s2.size(); i += 2) {
            odds_s2[s2[i]]++;
        }
        for (int i = 0; i < s2.size(); i += 2) {
            evens_s2[s2[i]]++;
        }

        return odds_s1 == odds_s2 && evens_s1 == evens_s2;
    }
};