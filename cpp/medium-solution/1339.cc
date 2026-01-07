/**
1339. Maximum Product of Splitted Binary Tree
    Given the root of a binary tree, split the binary tree into two subtrees by removing one edge such that the product of the sums of the subtrees is maximized.
    Return the maximum product of the sums of the two subtrees. Since the answer may be too large, return it modulo 109 + 7.
    Note that you need to maximize the answer before taking the mod and not after taking it.

    Example :
    Input: root = [1,2,3,4,5,6]
    Output: 110
    Explanation: Remove the red edge and get 2 binary trees with sum 11 and 10. Their product is 110 (11*10)
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
using ll = long long;
ll mod = 1e9 + 7;
ll total = 0;
ll ans = 0;
    ll subTreeSum(TreeNode* root){
        if (root == NULL)
            return 0;
        ll leftSum = subTreeSum(root->left);
        ll rightSum = subTreeSum(root->right);
        ans = max(ans, (leftSum * (total - leftSum)));
        ans = max(ans, (rightSum * (total - rightSum)));
        return leftSum + rightSum + root->val;
    }
    void totalSum(TreeNode* root){
        if (root == NULL)
            return;
        total += root->val;
        totalSum(root->left);
        totalSum(root->right);
    }
    int maxProduct(TreeNode* root) {
        totalSum(root);
        subTreeSum(root);
        return ans % mod;
    }
};