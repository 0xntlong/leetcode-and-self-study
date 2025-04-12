/*
3272. Find the Count of Good Integers
    You are given two positive integers n and k.
    An integer x is called k-palindromic if:
    x is a palindrome.
    x is divisible by k.
    An integer is called good if its digits can be rearranged to form a k-palindromic integer. For example, for k = 2, 2020 can be rearranged to form the k-palindromic integer 2002, whereas 1010 cannot be rearranged to form a k-palindromic integer.
    Return the count of good integers containing n digits.
    Note that any integer must not have leading zeros, neither before nor after rearrangement. For example, 1010 cannot be rearranged to form 101.

    Example :
    Input: n = 3, k = 5
    Output: 27
    Explanation:
    Some of the good integers are:
    551 because it can be rearranged to form 515.
    525 because it is already k-palindromic.
*/

#include <iostream>
#include <vector>
#include <set>
#include <string>
#include <algorithm>
#include <cmath>
using namespace std;


long long factorial(int n){
    long long result = 1;
    for (int i = 1; i <= n; i++){
        result *= i;
    }
    return result;
}
class Solution {
public:
    long long countGoodIntegers(int n, int k) {
        set<string> dict;
        long long base = pow(10, (n -1)/ 2);
        int skip = n % 2;
        for (long long i = base; i < base * 10; i++){
            string s = to_string(i);
            string palindString = s + string(s.rbegin() + skip, s.rend());
            long long palindInt = stoll(palindString);
            if (palindInt % k == 0){
                sort(palindString.begin(), palindString.end());
                dict.insert(palindString);
            }
        }
        vector<long long> fac(n + 1);
        for(int i = 0; i <= n; i++){
            fac[i] = factorial(i);
        }
        long long ans = 0;
        for (const string& s : dict){
            vector<int> cnt(10, 0);
            for (char c : s){
                cnt[c - '0']++;
            }
            long long total = (n - cnt[0]) * fac[n - 1];
            for (int x : cnt){
                if (x > 1){
                    total /= fac[x];
                }
            }
            ans += total;
        }
        return ans;
    }
};