/**
2071. Maximum Number of Tasks You Can Assign
    You have n tasks and m workers. Each task has a strength requirement stored in a 0-indexed integer array tasks, with the ith task requiring tasks[i] strength to complete. The strength of each worker is stored in a 0-indexed integer array workers, with the jth worker having workers[j] strength. Each worker can only be assigned to a single task and must have a strength greater than or equal to the task's strength requirement (i.e., workers[j] >= tasks[i]).
    Additionally, you have pills magical pills that will increase a worker's strength by strength. You can decide which workers receive the magical pills, however, you may only give each worker at most one magical pill.
    Given the 0-indexed integer arrays tasks and workers and the integers pills and strength, return the maximum number of tasks that can be completed.
    Example :
    Input: tasks = [3,2,1], workers = [0,3,3], pills = 1, strength = 1
    Output: 3
    Explanation:
    We can assign the magical pill and tasks as follows:
    - Give the magical pill to worker 0.
    - Assign worker 0 to task 2 (0 + 1 >= 1)
    - Assign worker 1 to task 1 (3 >= 2)
    - Assign worker 2 to task 0 (3 >= 3)
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <deque>
using namespace std;
 class Solution {
    public:
        bool canAssign(int k, const vector<int>& tasks, const vector<int>&workers, int pills, int strength){
            deque<int> q;
            int cnt = 0;
            int p = pills;
            for (int i = k - 1; i >= 0; i--){
                if (q.empty() && workers[cnt] >= tasks[i]){
                    cnt++;
                    continue;
                }
                if (!q.empty() && q.front() >= tasks[i]){
                    q.pop_front();
                    continue;
                }
                while (cnt < k && workers[cnt] + strength >= tasks[i]){
                    q.push_back(workers[cnt]);
                    cnt++;
                }
                if (!q.empty() && p > 0){
                    q.pop_back();
                    p--;
                    continue;
                }
                return false;
            }
            return true;
        }
        int maxTaskAssign(vector<int>& tasks, vector<int>& workers, int pills, int strength) {
            sort(tasks.begin(), tasks.end());
            sort(workers.begin(), workers.end(), greater<int>());
            int left = 0;
            int right = min((int)tasks.size(), (int)workers.size());
            int res = 0;
            while (left <= right){
                int mid = (left + right) / 2;
                if (canAssign(mid, tasks, workers, pills, strength)){
                    res = mid;
                    left = mid + 1;
                } else {
                    right = mid - 1;
                }
            }
            return res;
        }
    };