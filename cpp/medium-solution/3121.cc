/**
3121. Count the Number of Special Characters II
    You are given a string word. A letter c is called special if it appears both in lowercase and uppercase in word, and every lowercase occurrence of c appears before the first uppercase occurrence of c.
    Return the number of special letters in word.
    
    Example:
    Input: word = "aaAbcBC"
    Output: 3
    Explanation:

    The special characters are 'a', 'b', and 'c'.
 */



class Solution {
public:
    int numberOfSpecialChars(string word) {
        int count = 0;
        for (char w = 'a'; w <= 'z'; w++) {
            char up = toupper(w);
            int lastLower = word.rfind(w);
            int firstUpper = word.find(up);
            if (lastLower != string::npos &&
                firstUpper != string::npos &&
                lastLower < firstUpper) {
                count++;
            }
        }
        return count;
    }
};