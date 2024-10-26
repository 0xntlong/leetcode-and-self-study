/*
2458. Height of Binary Tree After Subtree Removal Queries
    You are given the root of a binary tree with n nodes. Each node is assigned a unique value from 1 to n. You are also given an array queries of size m.
    You have to perform m independent queries on the tree where in the ith query you do the following:
    Remove the subtree rooted at the node with the value queries[i] from the tree. It is guaranteed that queries[i] will not be equal to the value of the root.
    Return an array answer of size m where answer[i] is the height of the tree after performing the ith query.
    Note:
    The queries are independent, so the tree returns to its initial state after each query.
    The height of a tree is the number of edges in the longest simple path from the root to some node in the tree.

    Example:
    Input: root = [1,3,4,2,null,6,5,null,null,null,null,null,7], queries = [4]
    Output: [2]
    Explanation: The diagram above shows the tree after removing the subtree rooted at node with value 4.
    The height of the tree is 2 (The path 1 -> 3 -> 2).
*/

#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
class Solution {
public:
    map<int, int> Left, Right, Max_Height;
    int calculateHeight(TreeNode* root){
        if (!root)
            return 0;
        int leftHeight = calculateHeight(root->left);
        int rightHeight = calculateHeight(root->right);
        Left[root->val] = leftHeight;
        Right[root->val] = rightHeight;
        return max(leftHeight, rightHeight) + 1;
    }
    void HeightMap(TreeNode* root, int maxAbove, int depth){
        if (!root)
            return;
        Max_Height[root->val] = maxAbove;
        HeightMap(root->left, max(maxAbove, depth + Right[root->val]), depth + 1);
        HeightMap(root->right, max(maxAbove, depth + Left[root->val]), depth + 1);
    }
    vector<int> treeQueries(TreeNode* root, vector<int>& queries) {
        int total = calculateHeight(root);
        HeightMap(root->left, Right[root->val], 1);
        HeightMap(root->right, Left[root->val], 1);
        vector<int> ans;
        for (int q : queries){
            ans.push_back(Max_Height[q]);
        }    
        return ans;
    }
};