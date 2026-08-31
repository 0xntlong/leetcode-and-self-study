"""
2058. Find the Minimum and Maximum Number of Nodes Between Critical Points
    A critical point in a linked list is defined as either a local maxima or a local minima.
    A node is a local maxima if the current node has a value strictly greater than the previous node and the next node.
    A node is a local minima if the current node has a value strictly smaller than the previous node and the next node.
    Note that a node can only be a local maxima/minima if there exists both a previous node and a next node.
    Given a linked list head, return an array of length 2 containing [minDistance, maxDistance] where minDistance is the minimum distance between any two distinct critical points and maxDistance is the maximum distance between any two distinct critical points. If there are fewer than two critical points, return [-1, -1].

    Example :
    Input: head = [3,1]
    Output: [-1,-1]
"""


from typing import Optional, List

# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

class Solution:
    def nodesBetweenCriticalPoints(self, head: Optional[ListNode]) -> List[int]:
        result = [-1, -1]
        min_distance = float('inf')

        previous_node = head
        current_node = head.next
        current_index = 1

        previous_current_index = 0
        first_current_index = 0

        while current_node.next is not None:

            if ((current_node.val < previous_node.val and
                 current_node.val < current_node.next.val) or
                (current_node.val > previous_node.val and
                 current_node.val > current_node.next.val)):

                if first_current_index == 0:
                    first_current_index = current_index
                    previous_current_index = current_index
                else:
                    distance = current_index - previous_current_index

                    min_distance = min(min_distance, distance)

                    previous_current_index = current_index

            previous_node = current_node
            current_node = current_node.next
            current_index += 1

        if min_distance != float('inf'):

            max_distance = previous_current_index - first_current_index

            result[0] = min_distance
            result[1] = max_distance

        return result