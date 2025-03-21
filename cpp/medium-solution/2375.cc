/*
2375. Construct Smallest Number From DI String
    You are given a 0-indexed string pattern of length n consisting of the characters 'I' meaning increasing and 'D' meaning decreasing.
    A 0-indexed string num of length n + 1 is created using the following conditions:
    num consists of the digits '1' to '9', where each digit is used at most once.
    If pattern[i] == 'I', then num[i] < num[i + 1].
    If pattern[i] == 'D', then num[i] > num[i + 1].
    Return the lexicographically smallest possible string num that meets the conditions.

    Example :
    Input: pattern = "IIIDIDDD"
    Output: "123549876"
    Explanation:
    At indices 0, 1, 2, and 4 we must have that num[i] < num[i+1].
    At indices 3, 5, 6, and 7 we must have that num[i] > num[i+1].
    Some possible values of num are "245639871", "135749862", and "123849765".
    It can be proven that "123549876" is the smallest possible num that meets the conditions.
    Note that "123414321" is not possible because the digit '1' is used more than once.
*/

#include <string>
#include <vector>
using namespace std;
class Solution {
    public:
        string smallestNumber(string pattern) {
            int n = pattern.size();
            vector<int> prefix(n, 0);
            if (pattern[n - 1] == 'D')
                prefix[n - 1] = 1;
    
            for (int i = n - 2; i >= 0; i--){
                prefix[i] = (pattern[i] == 'D') ? prefix[i + 1] + 1 : 0;
            }
    
            string ans;
            for (int i = 0; i <= n; i++){
                ans += (char)(i + '1');
            }
            int i = 0;
            while (i < n){
                if (pattern[i] == 'D'){
                    int l = i, r = i + prefix[i];
                    while (l < r){
                        swap(ans[l], ans[r]);
                        l++;
                        r--;
                    }
                }
                i += prefix[i] + 1;
            }
            return ans;
        }
    };