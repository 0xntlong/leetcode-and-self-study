/**
1733. Minimum Number of People to Teach
    On a social network consisting of m users and some friendships between users, two users can communicate with each other if they know a common language.

    You are given an integer n, an array languages, and an array friendships where:

    - There are n languages numbered 1 through n.
    - languages[i] is the set of languages the i-th user knows.
    - friendships[i] = [ui, vi] denotes a friendship between the users ui and vi.
    You can choose one language and teach it to some users so that all friends can communicate with each other. Return the minimum number of users you need to teach.

    Note that friendships are not transitive, meaning if x is a friend of y and y is a friend of z, this doesn't guarantee that x is a friend of z.
    

    Example :
    Input: n = 2, languages = [[1],[2],[1,2]], friendships = [[1,2],[1,3],[2,3]]
    Output: 1
    Explanation: You can either teach user 1 the second language or user 2 the first language.
 */


#include <vector>
#include <bitset>
#include <unordered_set>
#include <algorithm>
using namespace std;

class Solution {
public:
    int minimumTeachings(int n, vector<vector<int>>& languages, vector<vector<int>>& friendships) {
        int m = (int)languages.size();
        vector<bitset<512>> dp(m + 1);
        for (int i = 0; i < m; i++){
            for (int lang : languages[i])
                dp[i + 1].set(lang - 1);
        }   
        unordered_set<int> visited;
        for (auto & f : friendships){
            int u = f[0], v = f[1];
            bitset<512> inter = dp[u] & dp[v];
            if (inter.none()){
                visited.insert(u);
                visited.insert(v);
            }
        }
        if (visited.empty())
            return 0;
        vector<int> cnt(n + 1, 0);
        for (int u : visited){
            for (int lang = 1; lang <= n; lang++){
                if (dp[u].test(lang - 1))
                    cnt[lang]++;
            }
        }
        int best = *max_element(cnt.begin(), cnt.end());
        return (int)visited.size() - best;
    }
};