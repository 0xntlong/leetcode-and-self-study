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


#include <vector>
#include <climits>

using namespace std;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        vector<int> nums;

        while (head) {
            nums.push_back(head->val);
            head = head->next;
        }

        vector<int> points;
        int n = nums.size();

        for (int i = 1; i < n - 1; i++) {
            if (nums[i] > nums[i - 1] && nums[i] > nums[i + 1]) {
                points.push_back(i);
            } else if (nums[i] < nums[i - 1] && nums[i] < nums[i + 1]) {
                points.push_back(i);
            }
        }

        int m = points.size();

        if (m < 2) {
            return {-1, -1};
        }

        int minDist = INT_MAX;
        int maxDist = points[m - 1] - points[0];

        for (int i = 1; i < m; i++) {
            minDist = min(minDist, points[i] - points[i - 1]);
        }

        return {minDist, maxDist};
    }
};