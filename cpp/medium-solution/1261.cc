/*
1261. Find Elements in a Contaminated Binary Tree
    Given a binary tree with the following rules:
    root.val == 0
    For any treeNode:
    If treeNode.val has a value x and treeNode.left != null, then treeNode.left.val == 2 * x + 1
    If treeNode.val has a value x and treeNode.right != null, then treeNode.right.val == 2 * x + 2
    Now the binary tree is contaminated, which means all treeNode.val have been changed to -1.
    Implement the FindElements class:
    FindElements(TreeNode* root) Initializes the object with a contaminated binary tree and recovers it.
    bool find(int target) Returns true if the target value exists in the recovered binary tree.
    
    Example :
    Input
    ["FindElements","find","find"]
    [[[-1,null,-1]],[1],[2]]
    Output
    [null,false,true]
    Explanation
    FindElements findElements = new FindElements([-1,null,-1]); 
    findElements.find(1); // return False 
    findElements.find(2); // return True 
*/

#include <unordered_set>
#include <queue>
#include <iostream>
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
class FindElements {
    public:
        unordered_set<int> hashSet;
        
        void bfs(TreeNode* root){
            queue<TreeNode*> q;
            root->val = 0;
            q.push(root);
                
            while (!q.empty()){
                TreeNode* node = q.front();
                int x = node->val;
                hashSet.insert(x);
                q.pop();
                if (node->left){
                    node->left->val = 2 * x + 1;
                    q.push(node->left);
                }
                if (node->right){
                    node->right->val = 2 * x + 2;
                    q.push(node->right);
                }
            }
        }
        FindElements(TreeNode* root) {
            if (root)
                bfs(root);
        }
        
        bool find(int target) {
            return hashSet.count(target);
        }
    };
    
    /**
     * Your FindElements object will be instantiated and called as such:
     * FindElements* obj = new FindElements(root);
     * bool param_1 = obj->find(target);
     */