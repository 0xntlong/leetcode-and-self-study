/**
1291. Sequential Digits
    An integer has sequential digits if and only if each digit in the number is one more than the previous digit.
    Return a sorted list of all the integers in the range [low, high] inclusive that have sequential digits.

    Example :
    Input: low = 100, high = 300
    Output: [123,234]
 */



class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        string digits = "123456789";
        vector<int> res;

        int n = to_string(low).size();
        int m = to_string(high).size();

        for (int length = n; length <= m; length++) {
            for (int i = 0; i < 10 - length; i++) {
                int num = stoi(digits.substr(i, length));

                if (low <= num && num <= high) {
                    res.push_back(num);
                }
            }
        }

        return res;
    }
};