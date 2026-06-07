/**
2196. Create Binary Tree From Descriptions
    You are given a 2D integer array descriptions where descriptions[i] = [parenti, childi, isLefti] indicates that parenti is the parent of childi in a binary tree of unique values. Furthermore,
    If isLefti == 1, then childi is the left child of parenti.
    If isLefti == 0, then childi is the right child of parenti.
    Construct the binary tree described by descriptions and return its root.
    The test cases will be generated such that the binary tree is valid.

    Example :
    Input: descriptions = [[20,15,1],[20,17,0],[50,20,1],[50,80,0],[80,19,1]]
    Output: [50,20,80,15,17,19]
    Explanation: The root node is the node with value 50 since it has no parent.
    The resulting binary tree is shown in the diagram.
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

function createBinaryTree(descriptions: number[][]): TreeNode | null {
    const nodes = new Map();
    const children = new Set();
    for (const [parent, child, isLeft] of descriptions) {
        if (!nodes.has(parent))
            nodes.set(parent, new TreeNode(parent));
        if (!nodes.has(child))
            nodes.set(child, new TreeNode(child));
        children.add(child);
        if (isLeft === 1)
            nodes.get(parent).left = nodes.get(child);
        else
            nodes.get(parent).right = nodes.get(child);
    }
    for (const [val, node] of nodes) {
        if (!children.has(val))
            return node;
    }
    return null;
};