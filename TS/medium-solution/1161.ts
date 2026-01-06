/**
1161. Maximum Level Sum of a Binary Tree
    Given the root of a binary tree, the level of its root is 1, the level of its children is 2, and so on.
    Return the smallest level x such that the sum of all the values of nodes at level x is maximal.


    Example :

    Input: root = [1,7,0,7,-8,null,null]
    Output: 2
    Explanation: 
    Level 1 sum = 1.
    Level 2 sum = 7 + 0 = 7.
    Level 3 sum = 7 + -8 = -1.
    So we return the level with the maximum sum which is level 2.
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

function maxLevelSum(root: TreeNode | null): number {
    if (!root) 
        return 0;

    const q: TreeNode[] = [root];
    let head = 0;

    let mx = Number.NEGATIVE_INFINITY;
    let curr = 1;
    let max_level = 1;

    while (head < q.length) {
        const sz = q.length - head;
        let sum = 0;

        for (let i = 0; i < sz; i++) {
            const node = q[head++];
            sum += node.val;
            if (node.left) 
                q.push(node.left);
            if (node.right) 
                q.push(node.right);
        }

        if (sum > mx) {
            mx = sum;
            max_level = curr;
        }
        curr++;
    }
    return max_level;
};