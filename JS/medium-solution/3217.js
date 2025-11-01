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
 * function ListNode(val, next) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.next = (next===undefined ? null : next)
 * }
 */
/**
 * @param {number[]} nums
 * @param {ListNode} head
 * @return {ListNode}
 */
var modifiedList = function(nums, head) {
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