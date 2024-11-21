/*
1736. Latest Time by Replacing Hidden Digits
    You are given a string time in the form of  hh:mm, where some of the digits in the string are hidden (represented by ?).
    The valid times are those inclusively between 00:00 and 23:59.
    Return the latest valid time you can get from time by replacing the hidden digits.

    Example :
    Input: time = "2?:?0"
    Output: "23:50"
    Explanation: The latest hour beginning with the digit '2' is 23 and the latest minute ending with the digit '0' is 50.
*/

#include <string>
using namespace std;
class Solution {
public:
    string maximumTime(string &time) {
        if ((time[0] == '?') && (time[1] > '3' && time[1] < '?')){
            time[0] = '1';
        }
        if ((time[0] == '?') && (time[1] < '4')){
            time[0] = '2';
        }
        if ((time[0] == '?') && (time[1] == '?')){
            time[0] = '2';
            time[1] = '3';
        }
        if ((time[1] == '?') && (time[0] != '?')){
            if (time[0] == '2'){
                time[1] = '3';
            } 
            else {
                time[1] = '9';
            }
        }
        if ((time[3] == '?') && (time[4] == '?')){
            time[3] = '5';
            time[4] = '9';
        }
        if ((time[3] == '?') && (time[4] != '?')){
            time[3] = '5';
        }
        if ((time[3] != '?') && (time[4] == '?')){
            time[4] = '9';
        }
        return time;
    }
};