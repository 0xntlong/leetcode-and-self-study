/*
889. Construct Binary Tree from Preorder and Postorder Traversal
    Given two integer arrays, preorder and postorder where preorder is the preorder traversal of a binary tree of distinct values and postorder is the postorder traversal of the same tree, reconstruct and return the binary tree.
    If there exist multiple answers, you can return any of them.

    Example :
    Input: preorder = [1,2,4,5,3,6,7], postorder = [4,5,2,6,7,3,1]
    Output: [1,2,3,4,5,6,7]
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
#include <vector>
#include <iostream>
using namespace std;
class Solution {
    int preIdx = 0, postIdx = 0;
public:
    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        TreeNode* node = new TreeNode(preorder[preIdx++]);

        if (node->val != postorder[postIdx]){
            node->left = constructFromPrePost(preorder, postorder);
        }
        if (node->val != postorder[postIdx]){
            node->right = constructFromPrePost(preorder, postorder);
        }
        postIdx++;
        return node;
    }
};