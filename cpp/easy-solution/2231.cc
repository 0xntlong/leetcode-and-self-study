/*
2231. Largest Number After Digit Swaps by Parity
    You are given a positive integer num. You may swap any two digits of num that have the same parity (i.e. both odd digits or both even digits).
    Return the largest possible value of num after any number of swaps.

    Example :
    Input: num = 1234
    Output: 3412
    Explanation: Swap the digit 3 with the digit 1, this results in the number 3214.
    Swap the digit 2 with the digit 4, this results in the number 3412.
    Note that there may be other sequences of swaps but it can be shown that 3412 is the largest possible number.
    Also note that we may not swap the digit 4 with the digit 1 since they are of different parities.
*/

#include <queue>
#include <vector>
using namespace std;

class Solution {
public:
    int largestInteger(int num) {
        priority_queue<int> odd;
        priority_queue<int> even;
        vector<int> digit, res;
        while (num){
            int n = num % 10;
            digit.push_back(n);
            if (n % 2 == 0)
                even.push(n);
            else 
                odd.push(n);
            num /= 10;
        }
        for (int i = digit.size() - 1; i >= 0; i--){
            if (digit[i] % 2 == 0){
                res.push_back(even.top());
                even.pop();
            } else {
                res.push_back(odd.top());
                odd.pop();
            }
        }
        int maxNum = 0;
        for (int i = 0; i < res.size(); i++){
            maxNum = maxNum * 10 + res[i];
        }
        return maxNum;
    }
};