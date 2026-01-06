/**
1161. Maximum Level Sum of a Binary Tree
    Given the root of a binary tree, the level of its root is 1, the level of its children is 2, and so on.
    Return the smallest level x such that the sum of all the values of nodes at level x is maximal.


    Example :

    Input: root = [1,7,0,7,-8,null,null]
    Output: 2
    Explanation: 
    Level 1 sum = 1.
    Level 2 sum = 7 + 0 = 7.
    Level 3 sum = 7 + -8 = -1.
    So we return the level with the maximum sum which is level 2.
 */

#include <queue>
#include <climits>
using namespace std;

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
class Solution {
public:
    int maxLevelSum(TreeNode* root) {
        std::queue<TreeNode*> q;
        q.push(root);
        long long mx = LLONG_MIN; 
        int curr = 1;
        int max_level = 1;
        while (!q.empty()){
            int sz = (int)q.size();
            long long sum = 0;
            for (int i = 0; i < sz; i++){
                TreeNode* node = q.front(); q.pop();
                sum += node->val;
                if (node->left)
                    q.push(node->left);
                if (node->right)
                    q.push(node->right);
            }
            if (sum > mx){
                mx = sum;
                max_level = curr;
            }
            curr++;
        }
        return max_level;
    }
};