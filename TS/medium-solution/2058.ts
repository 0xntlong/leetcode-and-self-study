/**
2058. Find the Minimum and Maximum Number of Nodes Between Critical Points
    A critical point in a linked list is defined as either a local maxima or a local minima.
    A node is a local maxima if the current node has a value strictly greater than the previous node and the next node.
    A node is a local minima if the current node has a value strictly smaller than the previous node and the next node.
    Note that a node can only be a local maxima/minima if there exists both a previous node and a next node.
    Given a linked list head, return an array of length 2 containing [minDistance, maxDistance] where minDistance is the minimum distance between any two distinct critical points and maxDistance is the maximum distance between any two distinct critical points. If there are fewer than two critical points, return [-1, -1].

    Example :
    Input: head = [3,1]
    Output: [-1,-1]
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

function nodesBetweenCriticalPoints(head: ListNode | null): number[] {
    const nums: number[] = [];

    while (head) {
        nums.push(head.val);
        head = head.next;
    }

    const points: number[] = [];
    const n: number = nums.length;

    for (let i = 1; i < n - 1; i++) {
        if (nums[i] > nums[i - 1] && nums[i] > nums[i + 1]) {
            points.push(i);
        } else if (nums[i] < nums[i - 1] && nums[i] < nums[i + 1]) {
            points.push(i);
        }
    }

    const m: number = points.length;

    if (m < 2) {
        return [-1, -1];
    }

    let minDist: number = Infinity;
    const maxDist: number = points[m - 1] - points[0];

    for (let i = 1; i < m; i++) {
        minDist = Math.min(minDist, points[i] - points[i - 1]);
    }

    return [minDist, maxDist];
};