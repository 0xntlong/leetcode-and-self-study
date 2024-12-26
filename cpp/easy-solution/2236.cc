/*
2236. Root with Equal Sum of Children
    You are given the root of a binary tree that consists of exactly 3 nodes: the root, its left child, and its right child.
    Return true if the value of the root is equal to the sum of the values of its two children, or false otherwise.

    Example :
    Input: root = [10,4,6]
    Output: true
    Explanation: The values of the root, its left child, and its right child are 10, 4, and 6, respectively.
    10 is equal to 4 + 6, so we return true.
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
class Solution {
public:
    bool checkTree(TreeNode* root) {
        if (!root || !root->left || !root->right)
            return false;
        int total = root->left->val + root->right->val;
        return total == root->val;
    }
};