/**
2106. Maximum Fruits Harvested After at Most K Steps   
    Fruits are available at some positions on an infinite x-axis. You are given a 2D integer array fruits where fruits[i] = [positioni, amounti] depicts amounti fruits at the position positioni. fruits is already sorted by positioni in ascending order, and each positioni is unique.
    You are also given an integer startPos and an integer k. Initially, you are at the position startPos. From any position, you can either walk to the left or right. It takes one step to move one unit on the x-axis, and you can walk at most k steps in total. For every position you reach, you harvest all the fruits at that position, and the fruits will disappear from that position.
    Return the maximum total number of fruits you can harvest.

    Example :
    Input: fruits = [[2,8],[6,3],[8,6]], startPos = 5, k = 4
    Output: 9
    Explanation: 
    The optimal way is to:
    - Move right to position 6 and harvest 3 fruits
    - Move right to position 8 and harvest 6 fruits
    You moved 3 steps and harvested 3 + 6 = 9 fruits in total.
 */


#include <vector>
#include <algorithm>
#include <climits>
using namespace std;
class Solution {
public:
    int maxTotalFruits(vector<vector<int>>& fruits, int startPos, int k) {
        int n = fruits.size();
        int res = 0;
        int curr_sum = 0;
        int left = lower_bound(fruits.begin(),  fruits.end(), vector<int>{startPos - k, INT_MIN}) - fruits.begin();
        int right = upper_bound(fruits.begin(),fruits.end(), vector<int>
        {startPos, INT_MIN}) - fruits.begin();
        for (int i = left; i < right; i++){
            curr_sum += fruits[i][1];
        }
        res = curr_sum;
        for (int i = right; i < n; i++){
            curr_sum += fruits[i][1];
            int r = fruits[i][0];
            if (r - startPos > k)
                break;
            while (left <= i && min(abs(r - startPos), abs(startPos - fruits[left][0])) + (r - fruits[left][0]) > k){
                curr_sum -= fruits[left][1];
                left++;
            }
            res = max(res, curr_sum);
        }
        return res;
    }
};