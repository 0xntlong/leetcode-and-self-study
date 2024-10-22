/*
2583. Kth Largest Sum in a Binary Tree
    You are given the root of a binary tree and a positive integer k.
    The level sum in the tree is the sum of the values of the nodes that are on the same level.
    Return the kth largest level sum in the tree (not necessarily distinct). If there are fewer than k levels in the tree, return -1.
    Note that two nodes are on the same level if they have the same distance from the root.

    Example :
    Input: root = [5,8,9,2,1,3,7,4,6], k = 2
    Output: 13
    Explanation: The level sums are the following:
    - Level 1: 5.
    - Level 2: 8 + 9 = 17.
    - Level 3: 2 + 1 + 3 + 7 = 13.
    - Level 4: 4 + 6 = 10.
    The 2nd largest level sum is 13.
*/


//Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };
 

#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    long long* q;
    int depth(TreeNode* root){
        if(!root)
            return 0;
        return 1 + max(depth(root->left), depth(root->right));
    }
    void traverse(TreeNode* root, int l){
        if(!root)
            return;
        q[l++] += root->val;
        traverse(root->left, l);
        traverse(root->right, l);
    }

    long long kthLargestLevelSum(TreeNode* root, int k) {
        int max_depth = depth(root);
        if (max_depth < k)
            return -1;
        q = new long long [max_depth];
        for (int i = 0; i < max_depth; i++)
            q[i] = 0;
        traverse(root, 0);
        sort(q, q + max_depth, greater<long long>());
        return q[k -1];
    }
};