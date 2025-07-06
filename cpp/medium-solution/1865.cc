/**
1865. Finding Pairs With a Certain Sum
    You are given two integer arrays nums1 and nums2. You are tasked to implement a data structure that supports queries of two types:

    Add a positive integer to an element of a given index in the array nums2.
    Count the number of pairs (i, j) such that nums1[i] + nums2[j] equals a given value (0 <= i < nums1.length and 0 <= j < nums2.length).
    Implement the FindSumPairs class:

    FindSumPairs(int[] nums1, int[] nums2) Initializes the FindSumPairs object with two integer arrays nums1 and nums2.
    void add(int index, int val) Adds val to nums2[index], i.e., apply nums2[index] += val.
    int count(int tot) Returns the number of pairs (i, j) such that nums1[i] + nums2[j] == tot.

    Example 1:
    Input
    ["FindSumPairs", "count", "add", "count", "count", "add", "add", "count"]
    [[[1, 1, 2, 2, 2, 3], [1, 4, 5, 2, 5, 4]], [7], [3, 2], [8], [4], [0, 1], [1, 1], [7]]
    Output
    [null, 8, null, 2, 1, null, null, 11]
 */
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;


class FindSumPairs {
private:
    unordered_map<int, int> freq1;
    unordered_map<int, int> freq2;
    vector<int> keys;
    vector<int> nums2;

public:
    FindSumPairs(vector<int>& nums1, vector<int>& nums2) {
        for (int num : nums1){
            freq1[num]++;
        }
        for (int num : nums2){
            freq2[num]++;
        }
        keys = nums1;
        sort(keys.begin(), keys.end());
        keys.erase(unique(keys.begin(), keys.end()), keys.end());
        this -> nums2 = nums2;
    }
    void add(int index, int val) {
        int oldVal = nums2[index];
        freq2[oldVal]--;
        nums2[index] += val;
        freq2[nums2[index]]++;
    }
    int count(int tot) {
        int cnt = 0;
        for (int num1 : keys){
            if (num1 > tot)
                break;
            int rem = tot - num1;
            if (freq2.count(rem)){
                cnt += freq1[num1] * freq2[rem];
            }
        }
        return cnt;
    }
};

/**
 * Your FindSumPairs object will be instantiated and called as such:
 * FindSumPairs* obj = new FindSumPairs(nums1, nums2);
 * obj->add(index,val);
 * int param_2 = obj->count(tot);
 */