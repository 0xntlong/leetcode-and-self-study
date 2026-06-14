/**
2130. Maximum Twin Sum of a Linked List
    In a linked list of size n, where n is even, the ith node (0-indexed) of the linked list is known as the twin of the (n-1-i)th node, if 0 <= i <= (n / 2) - 1.
    For example, if n = 4, then node 0 is the twin of node 3, and node 1 is the twin of node 2. These are the only nodes with twins for n = 4.
    The twin sum is defined as the sum of a node and its twin.
    Given the head of a linked list with even length, return the maximum twin sum of the linked list.

    Example :
    Input: head = [5,4,2,1]
    Output: 6
    Explanation:
    Nodes 0 and 1 are the twins of nodes 3 and 2, respectively. All have twin sum = 6.
    There are no other nodes with twins in the linked list.
    Thus, the maximum twin sum of the linked list is 6. 
 */


/**
 * Definition for singly-linked list.
 * function ListNode(val, next) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.next = (next===undefined ? null : next)
 * }
 */
/**
 * @param {ListNode} head
 * @return {number}
 */
var pairSum = function(head) {
    const temp = [];
    let node = head;
    while (node) {
        temp.push(node.val);
        node = node.next;
    }
    const n = temp.length;
    node = head;
    let res = -Infinity;
    for (let i = 0; i < Math.floor(n / 2); i++) {
        res = Math.max(res, node.val + temp.pop());
        node = node.next;
    }
    return res;
};