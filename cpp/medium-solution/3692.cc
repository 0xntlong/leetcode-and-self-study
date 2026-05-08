/**
3629. Minimum Jumps to Reach End via Prime Teleportation
    You are given an integer array nums of length n.
    You start at index 0, and your goal is to reach index n - 1.
    From any index i, you may perform one of the following operations:
    Adjacent Step: Jump to index i + 1 or i - 1, if the index is within bounds.
    Prime Teleportation: If nums[i] is a prime number p, you may instantly jump to any index j != i such that nums[j] % p == 0.
    Return the minimum number of jumps required to reach index n - 1.
    Example :
    Input: nums = [1,2,4,6]
    Output: 2
    Explanation:
    One optimal sequence of jumps is:
    Start at index i = 0. Take an adjacent step to index 1.
    At index i = 1, nums[1] = 2 is a prime number. Therefore, we teleport to index i = 3 as nums[3] = 6 is divisible by 2.
 */

#include <vector>
#include <unordered_map>
#include <queue>
using namespace std;
class Solution {
public:
    int minJumps(vector<int>& nums) {
        unordered_map<int, vector<int>> port;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            int tmp = nums[i];
            for (int d = 2; d * d <= tmp; d++) {
                if (tmp % d == 0) {
                    port[d].push_back(i);
                    while (tmp % d == 0) {
                        tmp /= d;
                    }
                }
            }

            if (tmp > 1) {
                port[tmp].push_back(i);
            }

        }
        vector<bool> visited(n, false);
        queue<int> q;
        q.push(0);
        int steps = 0;
        while (!q.empty()) {
            int sz = q.size();
            while (sz--) {
                int i = q.front();
                q.pop();
                int num = nums[i];
                if (visited[i]) 
                    continue;
                visited[i] = true;
                if (i == n - 1) 
                    return steps;
                if (port.count(num)) {
                    for (int nei : port[num]) {
                        q.push(nei);
                    }
                    port.erase(num);
                }
                if (i + 1 < n) {
                    q.push(i + 1);
                }
                if (i - 1 >= 0) {
                    q.push(i - 1);
                }
            }
            steps++;
        }
        return steps;
    }
};