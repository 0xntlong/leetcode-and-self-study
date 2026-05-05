"""
61. Rotate List
    Given the head of a linked list, rotate the list to the right by k places.
    Example :
    Input: head = [1,2,3,4,5], k = 2
    Output: [4,5,1,2,3]
"""
from typing import Optional
    
# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next
class Solution:
    def rotateRight(self, head: Optional[ListNode], k: int) -> Optional[ListNode]:
        if head is None or head.next is None:
            return head
        n = 1
        last = head
        while (last.next != None):
            n += 1
            last = last.next
        k = k % n
        if k == 0:
            return head
        curr = head
        count = 1
        while curr is not None:
            if count == (n - k):
                break
            count += 1
            curr = curr.next
        new = curr.next
        curr.next = None
        last.next = head
        return new