/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
#include <array>
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* curA = headA;
        ListNode* curB = headB;
        int lenA = 0, lenB = 0;
        while(curA != NULL){
            curA = curA->next;
            lenA++;
        }
        while(curB != NULL){
            curB = curB->next;
            lenB++;
        }
        curA = headA;
        curB = headB;
        if(lenB > lenA){
            std::swap(lenA, lenB);
            std::swap(curA, curB);
        }
        int diff = lenA - lenB;
        while(diff--){
            curA = curA->next;
        }
        while(curA != NULL){
            if(curA == curB){
                return curA;
            }
            curA = curA->next;
            curB = curB->next;
        }
        return NULL;
    }
};

// 两段链表拼起来，两个指针分别走
class Solution2 {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* curA = headA;
        ListNode* curB = headB;
        while(curA != curB){
            if(curA != NULL) curA = curA->next;
            else curA = headB;
            if(curB != NULL) curB = curB->next;
            else curB = headA;
        }
        return curA;
    }
};