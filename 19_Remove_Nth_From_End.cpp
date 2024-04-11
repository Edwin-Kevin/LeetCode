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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* dummyHead = new ListNode(0, head);
        ListNode* fastPtr = dummyHead;
        ListNode* slowPtr = dummyHead;

        while(n-- && fastPtr != nullptr){
            fastPtr = fastPtr->next;
        }
        fastPtr = fastPtr->next;
        while(fastPtr != nullptr){
            fastPtr = fastPtr->next;
            slowPtr = slowPtr->next;
        }
        ListNode* tmp = slowPtr->next;
        slowPtr->next = slowPtr->next->next;
        ListNode* result = dummyHead->next;
        delete tmp, dummyHead;
        return result;
    }
};