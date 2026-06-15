/**
2095. Delete the Middle Node of a Linked List
    You are given the head of a linked list. Delete the middle node, and return the head of the modified linked list.
    The middle node of a linked list of size n is the ⌊n / 2⌋th node from the start using 0-based indexing, where ⌊x⌋ denotes the largest integer less than or equal to x.
    For n = 1, 2, 3, 4, and 5, the middle nodes are 0, 1, 1, 2, and 2, respectively.
    Example :
    Input: head = [1,3,4,7,1,2,6]
    Output: [1,3,4,1,2,6]
    Explanation:
    The above figure represents the given linked list. The indices of the nodes are written below.
    Since n = 7, node 3 with value 7 is the middle node, which is marked in red.
    We return the new list after removing this node. 
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
 * @return {ListNode}
 */
var deleteMiddle = function(head) {
    if (!head || !head.next) {
        return null;
    }
    let slow = head;
    let fast = head;
    let prev = null;
    while (fast && fast.next) {
        prev = slow;
        slow = slow.next;
        fast = fast.next.next;
    }
    prev.next = slow.next;
    return head;
};