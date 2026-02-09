/**
1382. Balance a Binary Search Tree
    Given the root of a binary search tree, return a balanced binary search tree with the same node values. If there is more than one answer, return any of them.
    A binary search tree is balanced if the depth of the two subtrees of every node never differs by more than 1.

    Example :
    Input: root = [1,null,2,null,3,null,4,null,null]
    Output: [2,1,3,null,null,null,4]
    Explanation: This is not the only correct answer, [3,1,4,null,2] is also correct.
*/

#include <iostream>
#include <vector>
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
    void inorder(TreeNode* node, vector<TreeNode*>& nodes){
        if (!node) return;
        inorder(node->left, nodes);
        nodes.push_back(node);
        inorder(node->right, nodes);
    }
    TreeNode* build(vector<TreeNode*>& nodes, int left, int right){
        if (left > right) return nullptr;
        int mid = left + (right - left) / 2;
        TreeNode* root = nodes[mid];
        root->left = build(nodes, left, mid - 1);
        root->right = build(nodes, mid + 1, right);
        return root;
    }
    TreeNode* balanceBST(TreeNode* root) {
        if (!root) 
            return nullptr;
        vector<TreeNode*> nodes;
        inorder(root, nodes);
        return build(nodes, 0, (int)nodes.size() - 1);
    }
};