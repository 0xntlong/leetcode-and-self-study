/**
2092. Find All People With Secret
    You are given an integer n indicating there are n people numbered from 0 to n - 1. You are also given a 0-indexed 2D integer array meetings where meetings[i] = [xi, yi, timei] indicates that person xi and person yi have a meeting at timei. A person may attend multiple meetings at the same time. Finally, you are given an integer firstPerson.
    Person 0 has a secret and initially shares the secret with a person firstPerson at time 0. This secret is then shared every time a meeting takes place with a person that has the secret. More formally, for every meeting, if a person xi has the secret at timei, then they will share the secret with person yi, and vice versa.
    The secrets are shared instantaneously. That is, a person may receive the secret and share it with people in other meetings within the same time frame.
    Return a list of all the people that have the secret after all the meetings have taken place. You may return the answer in any order.
    Example :
    Input: n = 6, meetings = [[1,2,5],[2,3,8],[1,5,10]], firstPerson = 1
    Output: [0,1,2,3,5]
    Explanation:
    At time 0, person 0 shares the secret with person 1.
    At time 5, person 1 shares the secret with person 2.
    At time 8, person 2 shares the secret with person 3.
    At time 10, person 1 shares the secret with person 5.​​​​
    Thus, people 0, 1, 2, 3, and 5 know the secret after all the meetings.
 */


#include <vector>
#include <queue>
#include <climits>
using namespace std;
class Solution {
public:
    vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int firstPerson) {
        vector<vector<pair<int, int>>> adj(n);
        for (auto& meet : meetings){
            int x = meet[0], y = meet[1], time = meet[2];
            adj[x].emplace_back(time, y);
            adj[y].emplace_back(time, x);
        }
        vector<int> know(n, INT_MAX);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        vector<int> result;
        pq.emplace(0, 0);
        pq.emplace(0, firstPerson);

        while (!pq.empty()){
            auto [time, person] = pq.top();
            pq.pop();
            if (know[person] <= time) 
                continue;
            
            know[person] = time;
            result.push_back(person);
            
            for (auto& [t, nei] : adj[person]) {
                if (know[nei] != INT_MAX || t < time) 
                    continue;
                pq.push({t, nei});  
            }
        }
        return result;
    }
};