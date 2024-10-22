/*
1379. Find a Corresponding Node of a Binary Tree in a Clone of That Tree
    Given two binary trees original and cloned and given a reference to a node target in the original tree.
    The cloned tree is a copy of the original tree.
    Return a reference to the same node in the cloned tree.
    Note that you are not allowed to change any of the two trees or the target node and the answer must be a reference to a node in the cloned tree.

    Example:
    Input: tree = [7,4,3,null,null,6,19], target = 3
    Output: 3
    Explanation: In all examples the original and cloned trees are shown. The target node is a green node from the original tree. The answer is the yellow node from the cloned tree.
*/
#ifndef NULL
#define NULL 0
#endif

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        if (original == nullptr) {
            return nullptr;
        }
        if (original == target) {
            return cloned;
        }
        TreeNode* leftResult = getTargetCopy(original->left, cloned->left, target);
        if (leftResult != nullptr) {
            return leftResult;
        }
        return getTargetCopy(original->right, cloned->right, target);
    }
};