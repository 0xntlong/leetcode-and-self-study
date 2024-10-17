/*
670. Maximum Swap
    You are given an integer num. You can swap two digits at most once to get the maximum valued number.
    Return the maximum valued number you can get.
    Example :
    Input: num = 2736
    Output: 7236
    Explanation: Swap the number 2 and the number 7.
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
// FRIST APPROACH
class Solution {
public:
    int maximumSwap(int num) {
        vector<int> digit;
        int current = num;
        while (current > 0){
            digit.push_back(current % 10);
            current /= 10;
        }
        reverse(digit.begin(), digit.end());
        int max_digit = num;
        int N = digit.size();
        for (int i = 0; i < N; i++){
            for (int j = i + 1; j < N; j++){
                swap(digit[i], digit[j]);
                int score = 0;
                for (int k = 0; k < N; k++){
                    score = score * 10 + digit[k];
                }
                max_digit = max(max_digit, score);
                swap(digit[i], digit[j]);
            }
        }
        return max_digit;
    }
};


//SECOND APPROACH
class Solution {
public:
    int maximumSwap(int num) {
        if(num <= 9){
            return num;
        }
        string number = to_string(num);
        int r = 1;
        while(r < number.length() && number[r-1] >= number[r])
            r++;
        if(r == number.length())
            return num;
        int current_r = r;
        for (int i = r; i < number.length(); i++){
            if ( number[i] >= number[current_r]){
                current_r = i;
            }
        }
        for (int i = 0; i < number.length(); i++){
            if ( number[i] < number[current_r]){
                swap(number[current_r],number[i]);
                return stoi(number);
            }
        }
        return stoi(number);
    }
};