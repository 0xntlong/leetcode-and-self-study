/**
3161. Block Placement Queries
    There exists an infinite number line, with its origin at 0 and extending towards the positive x-axis.
    You are given a 2D array queries, which contains two types of queries:
    For a query of type 1, queries[i] = [1, x]. Build an obstacle at distance x from the origin. It is guaranteed that there is no obstacle at distance x when the query is asked.
    For a query of type 2, queries[i] = [2, x, sz]. Check if it is possible to place a block of size sz anywhere in the range [0, x] on the line, such that the block entirely lies in the range [0, x]. A block cannot be placed if it intersects with any obstacle, but it may touch it. Note that you do not actually place the block. Queries are separate.
    Return a boolean array results, where results[i] is true if you can place the block specified in the ith query of type 2, and false otherwise.
    Example :
    Input: queries = [[1,2],[2,3,3],[2,3,1],[2,2,2]]
    Output: [false,true,true]
    Explanation:
    For query 0, place an obstacle at x = 2. A block of size at most 2 can be placed before x = 3.
 */
#include <vector>
#include <set>
using namespace std;


class SegTree {
    int n;
    vector<int> tree;
public:
    SegTree(int size) {
        n = 1;
        while (n <= size) n *= 2;
        tree.assign(2 * n, 0);
    }
    
    void update(int i, int val) {
        for (tree[i += n] = val; i > 1; i >>= 1)
            tree[i >> 1] = max(tree[i], tree[i ^ 1]);
    }
    
    int query(int r) {
        int res = 0;

        for (int l = n, r_idx = r + n + 1; l < r_idx; l >>= 1, r_idx >>= 1) {
            if (l & 1) 
                res = max(res, tree[l++]);
            if (r_idx & 1) 
                res = max(res, tree[--r_idx]);
        }
        return res;
    }
};

class Solution {
public:
    vector<bool> getResults(vector<vector<int>>& queries) {
        int max_x = 0;
        for (const auto& q : queries) 
            max_x = max(max_x, q[1]);
        
        SegTree st(max_x + 1);
        set<int> obstacles = {0}; 
        vector<bool> res;
        
        for (const auto& q : queries) {
            if (q[0] == 1) {
                int x = q[1];
                auto it = obstacles.lower_bound(x);
                int nxt = (it != obstacles.end()) ? *it : -1;
                int prev = *(--it); 
                st.update(x, x - prev);
                
                if (nxt != -1) {
                    st.update(nxt, nxt - x);
                }
                obstacles.insert(x);
            } else {
                int x = q[1];
                int sz = q[2];
            
                auto it = obstacles.upper_bound(x);
                int prev = *(--it);

                int mx = max(x - prev, st.query(prev));
                res.push_back(sz <= mx);
            }
        }
        return res;
    }
};