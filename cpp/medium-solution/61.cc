/**
61. Rotate List
    Given the head of a linked list, rotate the list to the right by k places.
    Example :
    Input: head = [1,2,3,4,5], k = 2
    Output: [4,5,1,2,3]
 */


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
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head || !head->next) 
            return head;

        int n = 1;
        ListNode* last = head;
        while (last->next) {
            n++;
            last = last->next;
        }
        k %= n;
        if (k == 0) 
            return head;
        ListNode* curr = head;
        int count = 1;
        while (count < n - k) {
            curr = curr->next;
            count++;
        }

        ListNode* newHead = curr->next;
        curr->next = nullptr;
        last->next = head;
        return newHead;
    }
};