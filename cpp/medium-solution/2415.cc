/*
2415. Reverse Odd Levels of Binary Tree
    Given the root of a perfect binary tree, reverse the node values at each odd level of the tree.
    For example, suppose the node values at level 3 are [2,1,3,4,7,11,29,18], then it should become [18,29,11,7,4,3,1,2].
    Return the root of the reversed tree.
    A binary tree is perfect if all parent nodes have two children and all leaves are on the same level.
    The level of a node is the number of edges along the path between it and the root node.

    Example :
    Input: root = [2,3,5,8,13,21,34]
    Output: [2,5,3,8,13,21,34]
    Explanation: 
    The tree has only one odd level.
    The nodes at level 1 are 3, 5 respectively, which are reversed and become 5, 3.
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
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
class Solution {
private:
    void DFS(TreeNode* child_left, TreeNode* child_right, int level) {
            if (!child_left || !child_right){
                return;
            }
            if (level % 2 == 1){
                int temp = child_left->val;
                child_left->val = child_right->val;
                child_right->val = temp; 
            }
            DFS(child_left->left, child_right->right, level + 1);
            DFS(child_left->right, child_right->left, level + 1);
        }
public:
    TreeNode* reverseOddLevels(TreeNode* root) {
        if (!root){
            return nullptr;
        }
        DFS(root->left, root->right, 1);
        return root;
    }
};