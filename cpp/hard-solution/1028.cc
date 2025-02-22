/*
1028. Recover a Tree From Preorder Traversal
    We run a preorder depth-first search (DFS) on the root of a binary tree.
    At each node in this traversal, we output D dashes (where D is the depth of this node), then we output the value of this node.  If the depth of a node is D, the depth of its immediate child is D + 1.  The depth of the root node is 0.
    If a node has only one child, that child is guaranteed to be the left child.
    Given the output traversal of this traversal, recover the tree and return its root.

    Example :
    Input: traversal = "1-2--3--4-5--6--7"
    Output: [1,2,5,3,4,6,7]
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
#include <string>
using namespace std;
 class Solution {
    public:
        TreeNode* recoverFromPreorder(string traversal) {
            vector<TreeNode*> stack;
            int i = 0;
            while (i < traversal.length()){
                int level = 0, val = 0;
                while (traversal[i] == '-'){
                    i++;
                    level++;
                }
                while( i < traversal.length() && traversal[i] != '-'){
                    val = val * 10 + traversal[i] - '0';
                    i++;
                }
    
                TreeNode* node = new TreeNode(val);
                while (stack.size() > level)
                    stack.pop_back();
                if (!stack.empty()){
                    if (!stack.back() -> left)
                        stack.back()->left = node;
                    else stack.back()->right = node;
                }
                stack.push_back(node);
            }
            return stack[0];
        }
    };