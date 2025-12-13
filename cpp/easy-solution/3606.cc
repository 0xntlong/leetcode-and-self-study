/**
3606. Coupon Code Validator
    You are given three arrays of length n that describe the properties of n coupons: code, businessLine, and isActive. The ith coupon has:
    code[i]: a string representing the coupon identifier.
    businessLine[i]: a string denoting the business category of the coupon.
    isActive[i]: a boolean indicating whether the coupon is currently active.
    A coupon is considered valid if all of the following conditions hold:
    code[i] is non-empty and consists only of alphanumeric characters (a-z, A-Z, 0-9) and underscores (_).
    businessLine[i] is one of the following four categories: "electronics", "grocery", "pharmacy", "restaurant".
    isActive[i] is true.
    Return an array of the codes of all valid coupons, sorted first by their businessLine in the order: "electronics", "grocery", "pharmacy", "restaurant", and then by code in lexicographical (ascending) order within each category.

    Example :

    Input: code = ["SAVE20","","PHARMA5","SAVE@20"], businessLine = ["restaurant","grocery","pharmacy","restaurant"], isActive = [true,true,true,true]

    Output: ["PHARMA5","SAVE20"]

    Explanation:

    First coupon is valid.
    Second coupon has empty code (invalid).
    Third coupon is valid.
    Fourth coupon has special character @ (invalid).
 */



#include <vector>
#include <string>
#include <unordered_set>
#include <tuple>
#include <algorithm>
using namespace std;
class Solution {
public:
    vector<string> validateCoupons(vector<string>& code, vector<string>& businessLine, vector<bool>& isActive) {
        unordered_set<string> hashMap = {"electronics", "grocery", "restaurant", "pharmacy"};
        vector<tuple<string, string, bool>> coupons;
        auto isAlnum = [](const string& s) {
            if (s.empty()) 
                return false;
            for (char c : s) {
                char ch = (c == '_') ? 'a' : c;
                if (!isalnum(ch)) return false;
            }
            return true;
        };
        for (size_t i = 0; i < code.size(); ++i) {
            if (hashMap.count(businessLine[i]) && isActive[i] && isAlnum(code[i])) {
                coupons.emplace_back(businessLine[i], code[i], isActive[i]);
            }
        }
        sort(coupons.begin(), coupons.end());
        vector<string> result;
        for (const auto& tup : coupons) {
            result.push_back(get<1>(tup));
        }
        return result;
    }
};