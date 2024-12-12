/*
2558. Take Gifts From the Rechest Pile
    You are given an integer array gifts denoting the number of gifts in various piles. Every second, you do the following:
    Choose the pile with the maximum number of gifts.
    If there is more than one pile with the maximum number of gifts, choose any.
    Leave behind the floor of the square root of the number of gifts in the pile. Take the rest of the gifts.
    Return the number of gifts remaining after k seconds.

    Example :
    Input: gifts = [25,64,9,4,100], k = 4
    Output: 29
    Explanation: 
    The gifts are taken in the following way:
    - In the first second, the last pile is chosen and 10 gifts are left behind.
    - Then the second pile is chosen and 8 gifts are left behind.
    - After that the first pile is chosen and 5 gifts are left behind.
    - Finally, the last pile is chosen again and 3 gifts are left behind.
    The final remaining gifts are [5,8,9,4,3], so the total number of gifts remaining is 29.
*/

#include <vector>
#include <queue>
#include <cmath>
using namespace std;
class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        priority_queue<int> queue;
        long long ans = 0;
        for (int i : gifts){
            queue.push(i);
            ans += i;
        }
        while (k--){
            int top = queue.top();
            ans -= (top - sqrt(top));
            queue.pop();
            queue.push(sqrt(top));
        }
        return ans;
    }
};