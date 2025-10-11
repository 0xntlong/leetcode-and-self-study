/**
3186. Maximum Total Damage With Spell Casting
    A magician has various spells.
    You are given an array power, where each element represents the damage of a spell. Multiple spells can have the same damage value.
    It is a known fact that if a magician decides to cast a spell with a damage of power[i], they cannot cast any spell with a damage of power[i] - 2, power[i] - 1, power[i] + 1, or power[i] + 2.
    Each spell can be cast only once.
    Return the maximum possible total damage that a magician can cast.

    Example :
    Input: power = [1,1,3,4]
    Output: 6
    Explanation:
    The maximum possible damage of 6 is produced by casting spells 0, 1, 3 with damage 1, 1, 4.
*/

#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution {
public:
    long long maximumTotalDamage(vector<int>& power) {
        unordered_map<long long, long long> cnt;
        for (int i : power){
            cnt[i]++;
        }
        vector<long long> arr;
        arr.reserve(cnt.size());
        for (auto &p : cnt)
            arr.push_back(p.first);

        sort(arr.begin(), arr.end());
        int n = (int)arr.size();
        if (n == 1)
            return arr[0] * cnt[arr[0]];
        vector<long long> dp(n + 1, 0);
        dp[0] = 0;
        dp[1] = arr[0] * cnt[arr[0]];
        if (arr[1] - arr[0] > 2){
            dp[2] = dp[1] + arr[1] * cnt[arr[1]];
        } else { 
            dp[2] = max(dp[1], arr[1] * cnt[arr[1]]);
        }
        for (int i = 3; i <= n; i++){
            long long a_im1 = arr[i - 1], a_im2 = arr[i - 2], a_im3 = arr[i - 3];
            if ((a_im1 - a_im2 > 2) && (a_im1 - a_im3 > 2)) {
                dp[i] = dp[i - 1] + a_im1 * cnt[a_im1];
            } else if ((a_im1 - a_im3 > 2) && (a_im1 - a_im2 < 3)) {
                dp[i] = max(dp[i - 2] + a_im1 * cnt[a_im1], dp[i - 1]);
            } else if ((a_im1 - a_im3 < 3) && (a_im1 - a_im2 < 3)) {
                dp[i] = max(dp[i - 3] + a_im1 * cnt[a_im1], dp[i - 1]);
            }
        }
        return dp[n];
    }
};