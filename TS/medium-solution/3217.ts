/**
3217. Delete Nodes From Linked List Present in Array
    You are given an array of integers nums and the head of a linked list. Return the head of the modified linked list after removing all nodes from the linked list that have a value that exists in nums.
    Example 1:
    Input: nums = [1,2,3], head = [1,2,3,4,5]
    Output: [4,5]
    Explanation:
    Remove the nodes with values 1, 2, and 3.
 */


/**
 * Definition for singly-linked list.
 * class ListNode {
 *     val: number
 *     next: ListNode | null
 *     constructor(val?: number, next?: ListNode | null) {
 *         this.val = (val===undefined ? 0 : val)
 *         this.next = (next===undefined ? null : next)
 *     }
 * }
 */

function modifiedList(nums: number[], head: ListNode | null): ListNode | null {
    const deleteNode = new Set(nums);
    while (head && deleteNode.has(head.val))
        head = head.next;
    let curr = head;
    while (curr && curr.next) {
        if (deleteNode.has(curr.next.val))
            curr.next = curr.next.next;
        else
            curr = curr.next;
    }
    return head;
};