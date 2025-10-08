/**
2300. Successful Pairs of Spells and Potions
    You are given two positive integer arrays spells and potions, of length n and m respectively, where spells[i] represents the strength of the ith spell and potions[j] represents the strength of the jth potion.
    You are also given an integer success. A spell and potion pair is considered successful if the product of their strengths is at least success.
    Return an integer array pairs of length n where pairs[i] is the number of potions that will form a successful pair with the ith spell.

    Example :

    Input: spells = [5,1,3], potions = [1,2,3,4,5], success = 7
    Output: [4,0,3]
    Explanation:
    - 0th spell: 5 * [1,2,3,4,5] = [5,10,15,20,25]. 4 pairs are successful.
    - 1st spell: 1 * [1,2,3,4,5] = [1,2,3,4,5]. 0 pairs are successful.
    - 2nd spell: 3 * [1,2,3,4,5] = [3,6,9,12,15]. 3 pairs are successful.
    Thus, [4,0,3] is returned.
 */


#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        int maxPotion = *max_element(potions.begin(), potions.end());
        vector<int> freq(maxPotion + 1, 0);
        for (int p : potions){
            freq[p]++;
        }
        for (int i = 1; i <= maxPotion; i++){
            freq[i] += freq[i - 1];
        }
        int n = spells.size(), m = potions.size();
        vector<int> res(n, 0);
        for (int i = 0; i < n; i++){
            long long s = spells[i];
            long long k = (success + s - 1) / s;
            if (k <= maxPotion){
                res[i] = m - freq[k - 1];
            } else {
                res[i] = 0;
            }
        }
        return res;
    }
};