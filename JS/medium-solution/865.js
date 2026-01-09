/**
865. Smallest Subtree with all the Deepest Nodes
    Given the root of a binary tree, the depth of each node is the shortest distance to the root.
    Return the smallest subtree such that it contains all the deepest nodes in the original tree.
    A node is called the deepest if it has the largest depth possible among any node in the entire tree.
    The subtree of a node is a tree consisting of that node, plus the set of all descendants of that node.

    Example :
    Input: root = [3,5,1,6,2,0,8,null,null,7,4]
    Output: [2,7,4]
    Explanation: We return the node with value 2, colored in yellow in the diagram.
    The nodes coloured in blue are the deepest nodes of the tree.
    Notice that nodes 5, 3 and 2 contain the deepest nodes in the tree but node 2 is the smallest subtree among them, so we return it.
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
var subtreeWithAllDeepest = function(root) {
    function dfs(node) {
        if (!node) {
            return [0, null];
        }
        
        const [leftDepth, leftNode] = dfs(node.left);
        const [rightDepth, rightNode] = dfs(node.right);
        
        if (leftDepth > rightDepth) {
            return [leftDepth + 1, leftNode];
        } else if (rightDepth > leftDepth) {
            return [rightDepth + 1, rightNode];
        } else {
            return [leftDepth + 1, node];
        }
    }
    
    return dfs(root)[1];
};