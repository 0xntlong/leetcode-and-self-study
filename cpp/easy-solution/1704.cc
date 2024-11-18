/*
1704. Determine if String Halves Are Alike
    You are given a string s of even length. Split this string into two halves of equal lengths, and let a be the first half and b be the second half.
    Two strings are alike if they have the same number of vowels ('a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'). Notice that s contains uppercase and lowercase letters.
    Return true if a and b are alike. Otherwise, return false.

    Example :
    Input: s = "book"
    Output: true
    Explanation: a = "bo" and b = "ok". a has 1 vowel and b has 1 vowel. Therefore, they are alike.
*/

#include <string>
using namespace std;
class Solution {
    bool isVowel(char c){
        if ( c == 'A' || c == 'E' || c == 'I' || c == 'O'|| c == 'U' ||
             c == 'a' || c == 'e' || c == 'i' || c == 'o'|| c == 'u')
            return true;
        return false;
    }
public:
    bool halvesAreAlike(string s) {
        int n = s.size();
        string first = s.substr(0, n/2);
        string second = s.substr(n/2);
        int F = 0;
        int S = 0;
        for (char c : first)
            if (isVowel(c))
                F++;
        for (char c : second)
            if (isVowel(c))
                S++;
        if (F == S)
            return true;
        return false;
    }
};