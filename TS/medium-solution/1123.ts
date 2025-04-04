/**
1123. Lowest Common Ancestor of Deepest Leaves
    Given the root of a binary tree, return the lowest common ancestor of its deepest leaves.
    Recall that:
    The node of a binary tree is a leaf if and only if it has no children
    The depth of the root of the tree is 0. if the depth of a node is d, the depth of each of its children is d + 1.
    The lowest common ancestor of a set S of nodes, is the node A with the largest depth such that every node in S is in the subtree with root A.

    Example :
    Input: root = [3,5,1,6,2,0,8,null,null,7,4]
    Output: [2,7,4]
    Explanation: We return the node with value 2, colored in yellow in the diagram.
    The nodes coloured in blue are the deepest leaf-nodes of the tree.
    Note that nodes 6, 0, and 8 are also leaf nodes, but the depth of them is 2, but the depth of nodes 7 and 4 is 3.
 */




class TreeNode {
    val: number
    left: TreeNode | null
    right: TreeNode | null
    constructor(val?: number, left?: TreeNode | null, right?: TreeNode | null) {
        this.val = (val===undefined ? 0 : val)
        this.left = (left===undefined ? null : left)
        this.right = (right===undefined ? null : right)
    }
}


function lcaDeepestLeaves(root: TreeNode | null): TreeNode | null {
    const dfs = (root: TreeNode | null): [number, TreeNode | null] => {
        if (!root) {
            return [0, null];
        }

        const left = dfs(root.left);
        const right = dfs(root.right);

        if (left[0] === right[0]) {
            return [left[0] + 1, root];
        } else if (left[0] > right[0]) {
            return [left[0] + 1, left[1]];
        } else {
            return [right[0] + 1, right[1]];
        }
    };

    return dfs(root)[1];
};