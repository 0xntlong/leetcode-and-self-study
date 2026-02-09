/**
1382. Balance a Binary Search Tree
    Given the root of a binary search tree, return a balanced binary search tree with the same node values. If there is more than one answer, return any of them.
    A binary search tree is balanced if the depth of the two subtrees of every node never differs by more than 1.

    Example :
    Input: root = [1,null,2,null,3,null,4,null,null]
    Output: [2,1,3,null,null,null,4]
    Explanation: This is not the only correct answer, [3,1,4,null,2] is also correct.
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
 * @return {TreeNode}
 */
var balanceBST = function(root) {
    if (root === null) 
        return null;

    const nodes = [];
    const inorder = (node) => {
        if (node === null) 
            return;
        inorder(node.left);
        nodes.push(node);
        inorder(node.right);
    };
    inorder(root);

    const build = (left, right) => {
        if (left > right) return null;
        const mid = (left + right) >> 1;
        const node = nodes[mid];
        node.left = build(left, mid - 1);
        node.right = build(mid + 1, right);
        return node;
    };

    return build(0, nodes.length - 1);
};