/**
110. Balanced Binary Tree
    Given a binary tree, determine if it is height-balanced.

    Example :
    Input: root = [3,9,20,null,null,15,7]
    Output: true
 */
#include <iostream>
#include <algorithm>
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
    bool balanced;
    int dfs(TreeNode* node){
        if (!node)
            return 0;
        int l = dfs(node->left);
        int r = dfs(node->right);
        if (abs(l - r) > 1)
            balanced = false;
        return max(l, r) + 1;
    }
    bool isBalanced(TreeNode* root) {
        balanced = true;
        dfs(root);
        return balanced;
    }
};