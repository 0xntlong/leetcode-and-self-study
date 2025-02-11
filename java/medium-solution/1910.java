/**
1910. Remove All Occurrences of a Substring
    Given two strings s and part, perform the following operation on s until all occurrences of the substring part are removed:
    Find the leftmost occurrence of the substring part and remove it from s.
    Return s after removing all occurrences of part.
    A substring is a contiguous sequence of characters in a string.
    Example 
    Input: s = "daabcbaabcbc", part = "abc"
    Output: "dab"
    Explanation: The following operations are done:
    - s = "daabcbaabcbc", remove "abc" starting at index 2, so s = "dabaabcbc".
    - s = "dabaabcbc", remove "abc" starting at index 4, so s = "dababc".
    - s = "dababc", remove "abc" starting at index 3, so s = "dab".
    Now s has no occurrences of "abc".
*/


class Solution {
    public String removeOccurrences(String s, String part) {
        StringBuilder curr = new StringBuilder();
        int n = part.length();
        char end = part.charAt(n - 1);
        for (char c : s.toCharArray()){
            curr.append(c);
            if (c == end && curr.length() >= n){
                if (curr.substring(curr.length() - n).equals(part)){
                    curr.delete(curr.length() - n, curr.length());
                }
            }
        }
        return curr.toString();
    }
}