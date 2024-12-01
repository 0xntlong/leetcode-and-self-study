/*
1859. Sorting the Sentence
    A sentence is a list of words that are separated by a single space with no leading or trailing spaces. Each word consists of lowercase and uppercase English letters.
    A sentence can be shuffled by appending the 1-indexed word position to each word then rearranging the words in the sentence.
    For example, the sentence "This is a sentence" can be shuffled as "sentence4 a3 is2 This1" or "is2 sentence4 This1 a3".
    Given a shuffled sentence s containing no more than 9 words, reconstruct and return the original sentence.

    Example :
    Input: s = "is2 sentence4 This1 a3"
    Output: "This is a sentence"
    Explanation: Sort the words in s to their original positions "This1 is2 a3 sentence4", then remove the numbers.
*/

#include <string>
#include <iostream>
using namespace std;
class Solution {
public:
    string sortSentence(string s) {
        string ans = "";
        for (int i = 1; i <= 9; i++){
            if (s.find(to_string(i)) == string::npos)
                break;
            int end = s.find(to_string(i));
            cout << "end " << end << endl;
            int start = end;
            while (start >= 0 and s[start] != ' ')
                start--;
            if (start < 0)
                start = 0;
            int l = end - start;
            string temp = s.substr(start, l);
            cout << temp << endl;
            ans += temp;
            ans.push_back(' ');
        }
        cout << ans << endl;
        ans.erase(ans.length() - 1, 1);
        if (ans[0] == ' ')
            ans.erase(0, 1);
        while (ans.find("  ") != string::npos){
            int idx = ans.find("  ");
            ans.erase(idx, 1);
        }
        return ans;
    }
};