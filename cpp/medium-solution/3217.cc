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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        bitset<100001> map;
        for (int i = 0, n = nums.size(); i < n; i++){
            map.set(nums[i]);
        }
        while (head && map.test(head->val)){
            head = head->next;
        }
        ListNode *curr = head;
        while (curr && curr->next){
            if (map.test(curr->next->val))
                curr->next = curr->next->next;
            else
                curr = curr->next;
        }
        return head;
    }
};