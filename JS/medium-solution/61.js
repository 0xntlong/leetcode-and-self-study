/**
61. Rotate List
    Given the head of a linked list, rotate the list to the right by k places.
    Example :
    Input: head = [1,2,3,4,5], k = 2
    Output: [4,5,1,2,3]
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
 * @param {number} k
 * @return {ListNode}
 */
var rotateRight = function(head, k) {
    if (!head || !head.next) 
        return head;
    let n = 1;
    let last = head;
    while (last.next) {
        n++;
        last = last.next;
    }
    k %= n;
    if (k === 0) 
        return head;
    let curr = head;
    let count = 1;
    while (count < n - k) {
        curr = curr.next;
        count++;
    }
    let newHead = curr.next;
    curr.next = null;
    last.next = head;
    return newHead;
};