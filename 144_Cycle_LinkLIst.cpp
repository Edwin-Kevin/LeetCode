/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode* fastPtr = head;
        ListNode* slowPtr = head;
        while(fastPtr != NULL && fastPtr->next != NULL){
            // 移动是无条件的，因为一开始两个指针都指向head
            fastPtr = fastPtr->next->next;
            slowPtr = slowPtr->next;
            if(fastPtr == slowPtr)
                break;
        }

        if(fastPtr == NULL || fastPtr->next == NULL){
            return NULL;
        }

        slowPtr = head;
        while(fastPtr != slowPtr){
            fastPtr = fastPtr->next;
            slowPtr = slowPtr->next;
        }
        return slowPtr;
    }
};