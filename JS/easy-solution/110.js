/**
110. Balanced Binary Tree
    Given a binary tree, determine if it is height-balanced.

    Example :
    Input: root = [3,9,20,null,null,15,7]
    Output: true
 */


/**
 * Definition for a binary tree node.
 * function TreeNode(val, left, right) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.left = (left===undefined ? null : left)
 *     this.right = (right===undefined ? null : right)
 * }
 */
/**
 * @param {TreeNode} root
 * @return {boolean}
 */
var isBalanced = function(root) {
    let balanced = true;
    function dfs(node){
        if (node === null)
            return 0;
        const l = dfs(node.left);
        const r = dfs(node.right);
        if (Math.abs(l - r) > 1)
            balanced = false;
        return Math.max(l, r) + 1;
    }
    dfs(root);
    return balanced;
};