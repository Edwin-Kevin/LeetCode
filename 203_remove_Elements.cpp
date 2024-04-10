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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* dummyHead = new ListNode(0, head);
        ListNode* cur = dummyHead;
        while(cur->next != NULL){
            if(cur->next->val == val){
                ListNode* tmp = cur->next;
                // 如果是最后一个元素了，就会返回 NULL
                cur->next = cur->next->next;
                delete tmp;
            }
            else{
                cur = cur->next;
            }
        }
        head = dummyHead->next;
        delete dummyHead;
        return head;
    }
};