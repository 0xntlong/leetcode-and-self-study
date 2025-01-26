/*
2127. Maximum Employees to Be Invited to a Meeting
    A company is organizing a meeting and has a list of n employees, waiting to be invited. They have arranged for a large circular table, capable of seating any number of employees.
    The employees are numbered from 0 to n - 1. Each employee has a favorite person and they will attend the meeting only if they can sit next to their favorite person at the table. The favorite person of an employee is not themself.
    Given a 0-indexed integer array favorite, where favorite[i] denotes the favorite person of the ith employee, return the maximum number of employees that can be invited to the meeting.

    Example :
    Input: favorite = [2,2,1,2]
    Output: 3
*/

#include <vector>
#include <queue>
using namespace std;
class Solution {
public:
    int maximumInvitations(vector<int>& favorite) {
        int n = favorite.size();
        vector<int> deg(n, 0);

        for (int i : favorite){
            deg[i]++;
        }
        queue<int> q;
        for (int i = 0; i < n; i++){
            if (deg[i] == 0){
                q.push(i);
            }
        }
        vector<int> chain(n, 1);
        int d = 1;
        while (!q.empty()){
            int qSize = q.size();
            for (int k = 0; k < qSize; k++){
                int i = q.front();
                q.pop();
                int j = favorite[i];
                chain[j] = max(d + 1, chain[j]);
                deg[j]--;
                if (deg[j] == 0){
                    q.push(j);
                }
            }
            d++;
        }
        int maxCycle = 0, turn = 0;
        for (int i = 0; i < n; i++){
            if (deg[i] == 0)
                continue;
            int sizeCycle = 0, j = i;
            while (deg[j] != 0){
                deg[j] = 0;
                sizeCycle++;
                j = favorite[j];
            }
            if (sizeCycle > 2){
                maxCycle = max(maxCycle, sizeCycle);
            } else {
                turn += chain[i] + chain[favorite[i]];
            }
        }
        return max(maxCycle, turn);
    }
};