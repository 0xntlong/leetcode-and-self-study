/*
2471. Minimum Number of Operations to Sort a Binary Tree by Level
    You are given the root of a binary tree with unique values.
    In one operation, you can choose any two nodes at the same level and swap their values.
    Return the minimum number of operations needed to make the values at each level sorted in a strictly increasing order.
    The level of a node is the number of edges along the path between it and the root node.

    Example :
    Input: root = [1,4,3,7,6,8,5,null,null,null,null,9,null,10]
    Output: 3
    Explanation:
    - Swap 4 and 3. The 2nd level becomes [3,4].
    - Swap 7 and 5. The 3rd level becomes [5,6,8,7].
    - Swap 8 and 7. The 3rd level becomes [5,6,7,8].
    We used 3 operations so return 3.
    It can be proven that 3 is the minimum number of operations needed.
*/


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    int minimumOperations(TreeNode* root) {
        int ans = 0;
        queue<TreeNode*> q{{root}};
        while (!q.empty()){
            vector<int> vals;
            vector<int> child(q.size());
            for (int size = q.size(); size > 0; size--){
                TreeNode* node = q.front();
                q.pop();
                vals.push_back(node->val);
                if (node->left != nullptr)
                    q.push(node->left);
                if (node->right != nullptr)
                    q.push(node->right);
            }
            iota(child.begin(), child.end(), 0);
            ranges::sort(child, [&vals](int i, int j){ return vals[i] < vals[j]; });
            for (int i = 0; i < child.size(); i++)
                for ( ;child[i] != i; ans++)
                    swap(child[i], child[child[i]]);
        }
        return ans;
    }
};