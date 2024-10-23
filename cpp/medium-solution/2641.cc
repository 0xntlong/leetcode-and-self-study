/*
2641. Cousins in Binary Tree II
    Given the root of a binary tree, replace the value of each node in the tree with the sum of all its cousins' values.
    Two nodes of a binary tree are cousins if they have the same depth with different parents.
    Return the root of the modified tree.
    Note that the depth of a node is the number of edges in the path from the root node to it.

    Example:
    Input: root = [5,4,9,1,10,null,7]
    Output: [0,0,0,7,7,null,11]
    Explanation: The diagram above shows the initial binary tree and the binary tree after changing the value of each node.
    - Node with value 5 does not have any cousins so its sum is 0.
    - Node with value 4 does not have any cousins so its sum is 0.
    - Node with value 9 does not have any cousins so its sum is 0.
    - Node with value 1 has a cousin with value 7 so its sum is 7.
    - Node with value 10 has a cousin with value 7 so its sum is 7.
    - Node with value 7 has cousins with values 1 and 10 so its sum is 11.
*/

#include <vector>
#include <algorithm>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x): val(x), left(nullptr), right(nullptr){}
};

class Solution {
public:
    vector<int> sum;
    int h = 0;
    void f(TreeNode*& root, int level){
        if(!root)
            return;
        if(level >= sum.size())
            sum.resize(sum.size()*2);
        h = max(level, h);
        sum[level] += root->val;
        f(root->left, level + 1);
        f(root->right, level + 1);
    }
    void dfs(TreeNode*& root, int level){
        if (!root)
            return;
        if (level + 1 <= h){
            int x = sum[level + 1];
            bool Left=(root->left), Right=(root->right);
            x -= Left ? root->left->val:0;
            x -= Right ? root->right->val:0;
            if (Left) 
                root->left->val=x;
            if (Right) 
                root->right->val=x;
        }
        dfs(root->left, level + 1);
        dfs(root->right, level + 1);
    }
    TreeNode* replaceValueInTree(TreeNode* root) {
        sum.resize(256);
        f(root, 0);
        root->val = 0;
        dfs(root, 0);
        return root;
    }
};