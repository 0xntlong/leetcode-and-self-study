/*
904. Fruit Into Baskets
    You are visiting a farm that has a single row of fruit trees arranged from left to right. The trees are represented by an integer array fruits where fruits[i] is the type of fruit the ith tree produces.
    You want to collect as much fruit as possible. However, the owner has some strict rules that you must follow:
    You only have two baskets, and each basket can only hold a single type of fruit. There is no limit on the amount of fruit each basket can hold.
    Starting from any tree of your choice, you must pick exactly one fruit from every tree (including the start tree) while moving to the right. The picked fruits must fit in one of your baskets.
    Once you reach a tree with fruit that cannot fit in your baskets, you must stop.
    Given the integer array fruits, return the maximum number of fruits you can pick.

    Example :
    Input: fruits = [1,2,1]
    Output: 3
    Explanation: We can pick from all 3 trees.

*/

#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int n = fruits.size();
        int maxFruits = *max_element(fruits.begin(), fruits.end());
        vector<int> freq(maxFruits + 1, 0);
        int left = 0, count = 0, baskets = 0, res = 0;
        for (int right = 0; right < n; right++){
            int fruit = fruits[right];
            freq[fruit]++;
            if (freq[fruit] == 1){
                baskets++;
            }
            count++;
            while (baskets > 2){
                int removeFruit = fruits[left];
                freq[removeFruit]--;
                if (freq[removeFruit] == 0){
                    baskets--;
                }
                left++;
                count--;
            }
            res = max(res, count);
        }
        return res;
    }
};