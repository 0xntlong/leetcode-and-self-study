/**
1339. Maximum Product of Splitted Binary Tree
    Given the root of a binary tree, split the binary tree into two subtrees by removing one edge such that the product of the sums of the subtrees is maximized.
    Return the maximum product of the sums of the two subtrees. Since the answer may be too large, return it modulo 109 + 7.
    Note that you need to maximize the answer before taking the mod and not after taking it.

    Example :
    Input: root = [1,2,3,4,5,6]
    Output: 110
    Explanation: Remove the red edge and get 2 binary trees with sum 11 and 10. Their product is 110 (11*10)
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

function maxProduct(root: TreeNode | null): number {
    const MOD = 1000000007n;

    let total = 0n;
    let ans = 0n;

    const totalSum = (node: TreeNode | null): void => {
        if (!node) return;
        total += BigInt(node.val);
        totalSum(node.left);
        totalSum(node.right);
    };

    const subTreeSum = (node: TreeNode | null): bigint => {
        if (!node) return 0n;

        const leftSum = subTreeSum(node.left);
        const rightSum = subTreeSum(node.right);

        const p1 = leftSum * (total - leftSum);
        if (p1 > ans) ans = p1;

        const p2 = rightSum * (total - rightSum);
        if (p2 > ans) ans = p2;

        return leftSum + rightSum + BigInt(node.val);
    };

    totalSum(root);
    subTreeSum(root);

    return Number(ans % MOD);
};