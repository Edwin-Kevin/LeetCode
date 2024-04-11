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
// 迭代法
class Solution1 {
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode* dummyNode = new ListNode(0, head);
        ListNode* cur = dummyNode;
        while(cur->next != nullptr && cur->next->next != nullptr){
            ListNode* leftPtr = cur->next;
            ListNode* rightPtr = cur->next->next;

            // Exchange the nodes.
            cur->next = rightPtr;
            leftPtr->next = rightPtr->next;
            rightPtr->next = leftPtr;

            cur = cur->next->next;
        }
        ListNode* result = dummyNode->next;
        delete dummyNode;
        return result;
    }
};

// 递归法
class Solution2 {
public:
    ListNode* swapPairs(ListNode* head) {
        // base case
        if(head == nullptr || head->next == nullptr){
            return head;
        }

        ListNode* firstPtr = head;
        ListNode* secondPtr = head->next;
        ListNode* thirdPtr = head->next->next;

        secondPtr->next = firstPtr;
        firstPtr->next = swapPairs(thirdPtr);
        return secondPtr;
    }
};