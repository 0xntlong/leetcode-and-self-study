"""
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
"""

from typing import List


class Solution:
    def validateCoupons(self, code: List[str], businessLine: List[str], isActive: List[bool]) -> List[str]:
        def isValid(s):
            return (s[0] in hashMap and s[2] and s[1].replace('_', 'a').isalnum())

        hashMap = {"electronics", "grocery", "restaurant", "pharmacy"}

        res = sorted(filter(isValid, zip(businessLine, code, isActive)))
        return [coupId for _, coupId, _ in res]