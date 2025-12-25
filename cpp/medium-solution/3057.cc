/**
3075. Maximize Happiness of Selected Children
    You are given an array happiness of length n, and a positive integer k.
    There are n children standing in a queue, where the ith child has happiness value happiness[i]. You want to select k children from these n children in k turns.
    In each turn, when you select a child, the happiness value of all the children that have not been selected till now decreases by 1. Note that the happiness value cannot become negative and gets decremented only if it is positive.
    Return the maximum sum of the happiness values of the selected children you can achieve by selecting k children.

    Example :
    Input: happiness = [1,2,3], k = 2
    Output: 4
    Explanation: We can pick 2 children in the following way:
    - Pick the child with the happiness value == 3. The happiness value of the remaining children becomes [0,1].
    - Pick the child with the happiness value == 1. The happiness value of the remaining child becomes [0]. Note that the happiness value cannot become less than 0.
    The sum of the happiness values of the selected children is 3 + 1 = 4.
 */


#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        sort(happiness.begin(), happiness.end(), greater<int>());
        long long total = 0;
        for (int i = 0; i < k; i++){
            int value = happiness[i] - i;
            if (value > 0)
                total += value;
        }
        return total;
    }
};