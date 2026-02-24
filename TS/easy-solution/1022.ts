/**
1022. Sum of Root To Leaf Binary Numbers
    You are given the root of a binary tree where each node has a value 0 or 1. Each root-to-leaf path represents a binary number starting with the most significant bit.
    For example, if the path is 0 -> 1 -> 1 -> 0 -> 1, then this could represent 01101 in binary, which is 13.
    For all leaves in the tree, consider the numbers represented by the path from the root to that leaf. Return the sum of these numbers.
    The test cases are generated so that the answer fits in a 32-bits integer.
    
    Example:
    Input: root = [1,0,1,0,1,0,1]
    Output: 22
    Explanation: (100) + (101) + (110) + (111) = 4 + 5 + 6 + 7 = 22
 */



/**
 * Definition for a binary tree node.
 * class TreeNode {
 *     val: number
 *     left: TreeNode | null
 *     right: TreeNode | null
 *     constructor(val?: number, left?: TreeNode | null, right?: TreeNode | null) {
 *         this.val = (val===undefined ? 0 : val)
 *         this.left = (left===undefined ? null : left)
 *         this.right = (right===undefined ? null : right)
 *     }
 * }
 */

function sumRootToLeaf(root: TreeNode | null): number {
    const dfs = (node : TreeNode | null, x: number): number => {
        if (node === null)
            return 0;
        x = (x << 1) + node.val;
        if (node.left === null && node.right === null)
            return x;
        return dfs(node.left, x) + dfs(node.right, x);
    };
    return dfs(root, 0);
};