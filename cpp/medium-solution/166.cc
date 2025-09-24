/**
166. Fraction to Recurring Decimal
    Given two integers representing the numerator and denominator of a fraction, return the fraction in string format.
    If the fractional part is repeating, enclose the repeating part in parentheses.
    If multiple answers are possible, return any of them.
    It is guaranteed that the length of the answer string is less than 104 for all the given inputs.

    Example:
    Input: numerator = 1, denominator = 2
    Output: "0.5"

 */




#include <string>
#include <unordered_map>
#include <cmath>
using namespace std;
class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        if (numerator == 0){
            return "0";
        }
        string res = (numerator < 0) ^ (denominator < 0) ? "-" : "";
        long long n = abs((long long) numerator);
        long long d = abs((long long) denominator);
        long long integer = n / d;
        long long rem = n % d;
        res += to_string(integer);
        if (rem == 0){
            return res;
        }
        res += ".";
        unordered_map<long long, int> pos;
        while (rem) {
            if (pos.find(rem) != pos.end()){
                int idx = pos[rem];
                res.insert(idx, "(");
                res += ")";
                break;
            }
            pos[rem] = res.length();
            rem *= 10;
            res += to_string(rem / d);
            rem %= d;
        }
        return res;
    }
};