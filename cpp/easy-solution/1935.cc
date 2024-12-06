/*
1935. Maximum Number of Words You Can Type
    There is a malfunctioning keyboard where some letter keys do not work. All other keys on the keyboard work properly.
    Given a string text of words separated by a single space (no leading or trailing spaces) and a string brokenLetters of all distinct letter keys that are broken, return the number of words in text you can fully type using this keyboard.

    Example :
    Input: text = "hello world", brokenLetters = "ad"
    Output: 1
    Explanation: We cannot type "world" because the 'd' key is broken.
*/

#include <vector>
using namespace std;
class Solution {
public:
    int canBeTypedWords(string text, string brokenLetters) {
        vector<int> chr(26, 0);
        for (int i = 0; i < brokenLetters.size(); i++){
            chr[brokenLetters[i] - 'a'] = 1;
        }
        int count = 0;
        bool flag = true;
        for (int i = 0; i < text.size(); i++){
            if (text[i] == ' '){
                if (flag == true)
                    count++;
                flag = true;
            }
            else {
                if (chr[text[i] - 'a'] != 0){
                    flag = false;
                }
            }
        }
        if (flag == true)
            count++;
        return count++;
    }
};