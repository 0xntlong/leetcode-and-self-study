"""
3129. Find All Possible Stable Binary Arrays I
    You are given 3 positive integers zero, one, and limit.
    A binary array arr is called stable if:
    The number of occurrences of 0 in arr is exactly zero.
    The number of occurrences of 1 in arr is exactly one.
    Each subarray of arr with a size greater than limit must contain both 0 and 1.
    Return the total number of stable binary arrays.
    Since the answer may be very large, return it modulo 109 + 7.
    Example :

    Input: zero = 1, one = 1, limit = 2

    Output: 2

    Explanation:

    The two possible stable binary arrays are [1,0] and [0,1], as both arrays have a single 0 and a single 1, and no subarray has a length greater than 2.
 """