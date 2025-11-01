"""
3217. Delete Nodes From Linked List Present in Array
    You are given an array of integers nums and the head of a linked list. Return the head of the modified linked list after removing all nodes from the linked list that have a value that exists in nums.
    Example 1:
    Input: nums = [1,2,3], head = [1,2,3,4,5]
    Output: [4,5]
    Explanation:
    Remove the nodes with values 1, 2, and 3.

"""


from typing import List, Optional

# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next
class Solution:
    def modifiedList(self, nums: List[int], head: Optional[ListNode]) -> Optional[ListNode]:
        deleteNode = set(nums)
        while head and head.val in deleteNode:
            head = head.next
        curr = head
        while curr and curr.next:
            if curr.next.val in deleteNode:
                curr.next = curr.next.next
            else:
                curr = curr.next
        return head
    




