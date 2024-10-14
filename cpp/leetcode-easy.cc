/*
This file is a minimal set of EASY solutions to leetcode problems in C++.
No algorithms or reasoning are provided to save space.
For more details, readers are suggested to explore on their own or search on Threads platform : leetcodedaybyday . Thanks for reading.
*/

#include <vector>
#include <string>
#include <unordered_map>
#include <stack>
#include <algorithm>
using namespace std;

class Solution {
public:
    /*
    1. Two Sum
    Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.
    You may assume that each input would have exactly one solution, and you may not use the same element twice.
    You can return the answer in any order.
    
    Example:
    Input: nums = [2,7,11,15], target = 9
    Output: [0,1]
    Explanation: Because nums[0] + nums[1] == 9, we return [0, 1].
    */
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> num_dict;
        for (int i = 0; i < nums.size(); ++i) {
            int complement = target - nums[i];
            if (num_dict.find(complement) != num_dict.end()) {
                return {num_dict[complement], i};
            }
            num_dict[nums[i]] = i;
        }
        return {};
    }
    
    /*
    9. Palindrome Number
    Given an integer x, return true if x is a palindrome, and false otherwise.

    Example:
    Input: x = 121
    Output: true
    Explanation: 121 reads as 121 from left to right and from right to left.
    */
    bool isPalindrome(int x) {
        if (x < 0) return false;
        int reversed_num = 0, temp = x;
        while (temp != 0) {
            int digit = temp % 10;
            reversed_num = reversed_num * 10 + digit;
            temp /= 10;
        }
        return reversed_num == x;
    }
    
    /*
    13. Roman to Integer
    Roman numerals are represented by seven different symbols: I, V, X, L, C, D and M.
    Symbol       Value
    I             1
    V             5
    X             10
    L             50
    C             100
    D             500
    M             1000
    For example, 2 is written as II in Roman numeral, just two ones added together. 12 is written as XII, which is simply X + II. The number 27 is written as XXVII, which is XX + V + II.
    Roman numerals are usually written largest to smallest from left to right. However, the numeral for four is not IIII. Instead, the number four is written as IV. Because the one is before the five we subtract it making four. The same principle applies to the number nine, which is written as IX. There are six instances where subtraction is used:
    I can be placed before V (5) and X (10) to make 4 and 9. 
    X can be placed before L (50) and C (100) to make 40 and 90. 
    C can be placed before D (500) and M (1000) to make 400 and 900.
    Given a roman numeral, convert it to an integer.

    Example :
    Input: s = "III"
    Output: 3
    Explanation: III = 3.
    */
    int romanToInt(string s) {
        unordered_map<char, int> n = {
            {'I', 1}, {'V', 5}, {'X', 10}, {'L', 50},
            {'C', 100}, {'D', 500}, {'M', 1000}
        };
        int ans = 0;
        for (int i = 0; i < s.size(); ++i) {
            if (i < s.size() - 1 && n[s[i]] < n[s[i + 1]]) {
                ans -= n[s[i]];
            } else {
                ans += n[s[i]];
            }
        }
        return ans;
    }
    
    /*
    14. Longest Common Prefix
    Write a function to find the longest common prefix string amongst an array of strings.
    If there is no common prefix, return an empty string "".
    
    Example:
    Input: strs = ["flower","flow","flight"]
    Output: "fl"
    */
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty()) return "";
        sort(strs.begin(), strs.end());
        string first = strs[0], last = strs.back(), ans = "";
        for (int i = 0; i < min(first.size(), last.size()); ++i) {
            if (first[i] != last[i]) return ans;
            ans += first[i];
        }
        return ans;
    }
    
    /*
    20. Valid Parentheses
    Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.
    An input string is valid if:
    Open brackets must be closed by the same type of brackets.
    Open brackets must be closed in the correct order.
    Every close bracket has a corresponding open bracket of the same type.
    
    Example:
    Input: s = "()"
    Output: true
    */
    bool isValid(string s) {
        stack<char> sym;
        for (char c : s) {
            if (c == '(' || c == '[' || c == '{') {
                sym.push(c);
            } else {
                if (sym.empty()) return false;
                char top = sym.top();
                if ((c == ')' && top == '(') || (c == ']' && top == '[') || (c == '}' && top == '{')) {
                    sym.pop();
                } else {
                    return false;
                }
            }
        }
        return sym.empty();
    }
    
    /*
    21. Merge Two Sorted Lists
    You are given the heads of two sorted linked lists list1 and list2.
    Merge the two lists into one sorted list. The list should be made by splicing together the nodes of the first two lists.
    Return the head of the merged linked list.
    
    Example:
    Input: list1 = [1,2,4], list2 = [1,3,4]
    Output: [1,1,2,3,4,4]
    */
    struct ListNode {
        int val;
        ListNode *next;
        ListNode() : val(0), next(nullptr) {}
        ListNode(int x) : val(x), next(nullptr) {}
        ListNode(int x, ListNode *next) : val(x), next(next) {}
    };
    
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode dummy, *cur = &dummy;
        while (list1 && list2) {
            if (list1->val > list2->val) {
                cur->next = list2;
                list2 = list2->next;
            } else {
                cur->next = list1;
                list1 = list1->next;
            }
            cur = cur->next;
        }
        cur->next = list1 ? list1 : list2;
        return dummy.next;
    }
    
    /*
    26. Remove Duplicates from Sorted Array
    Given an integer array nums sorted in non-decreasing order, remove the duplicates in-place such that each unique element appears only once. The relative order of the elements should be kept the same. Then return the number of unique elements in nums.
    Consider the number of unique elements of nums to be k, to get accepted, you need to do the following things:
    Change the array nums such that the first k elements of nums contain the unique elements in the order they were present in nums initially. The remaining elements of nums are not important as well as the size of nums.
    Return k.
    Custom Judge:
    The judge will test your solution with the following code:
    int[] nums = [...]; // Input array
    int[] expectedNums = [...]; // The expected answer with correct length
    int k = removeDuplicates(nums); // Calls your implementation
    assert k == expectedNums.length;
    for (int i = 0; i < k; i++) {
        assert nums[i] == expectedNums[i];
    }
    If all assertions pass, then your solution will be accepted.
    Example:
    Input: nums = [1,1,2]
    Output: 2, nums = [1,2,_]
    Explanation: Your function should return k = 2, with the first two elements of nums being 1 and 2 respectively.
    It does not matter what you leave beyond the returned k (hence they are underscores).
    */
    int removeDuplicates(vector<int>& nums) {
        if (nums.empty()) return 0;
        int j = 1;
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] != nums[i - 1]) {
                nums[j++] = nums[i];
            }
        }
        return j;
    }
    /*  
    1295. Find Numbers with Even Number of Digits
    Given an array nums of integers, return how many of them contain an even number of digits.

    Example 1:
    Input: nums = [12,345,2,6,7896]
    Output: 2
    Explanation: 
    12 contains 2 digits (even number of digits). 
    345 contains 3 digits (odd number of digits). 
    2 contains 1 digit (odd number of digits). 
    6 contains 1 digit (odd number of digits). 
    7896 contains 4 digits (even number of digits). 
    Therefore only 12 and 7896 contain an even number of digits. 
    */
    int findNumbers(vector<int>& nums) {
        int res = 0;
        for (int i = 0; i < nums.size(); i++){
            if (to_string(nums[i]).length() % 2 == 0){
                res++;
            }
        }
        return res;
    }

    /*
    1299. Replace Elements with Greatest Element on Right Side
    Given an array arr, replace every element in that array with the greatest element among the elements to its right, and replace the last element with -1.
    After doing so, return the array.

    Example:
    Input: arr = {17,18,5,4,6,1}
    Output: {18,6,6,6,1,-1}
    Explanation: 
    - index 0 --> the greatest element to the right of index 0 is index 1 (18).
    - index 1 --> the greatest element to the right of index 1 is index 4 (6).
    - index 2 --> the greatest element to the right of index 2 is index 4 (6).
    - index 3 --> the greatest element to the right of index 3 is index 4 (6).
    - index 4 --> the greatest element to the right of index 4 is index 5 (1).
    - index 5 --> there are no elements to the right of index 5, so we put -1.
    */
    vector<int> replaceElements(vector<int>& arr) {
        int high = arr.back();
        for (int i = arr.size() - 2; i >= 0; --i) {
            int temp = arr[i];
            arr[i] = high;
            high = max(high, temp);
        }
        arr.back() = -1;
        return arr;
    }
};