#include <algorithm>
class MyLinkedList {
public:
    struct ListNode{
        int val;
        ListNode* next;
        ListNode(int val):val(val), next(nullptr){}
    };

    MyLinkedList() {
        dummyHead = new ListNode(0);
        size = 0;
    }
    
    int get(int index) {
        if(index > (size - 1) || index < 0){
            return -1;
        }
        ListNode* cur = dummyHead->next;
        while(index > 0){
            cur = cur->next;
            index--;
        }
        return cur->val;
    }
    
    void addAtHead(int val) {
        ListNode* newListNode = new ListNode(val);
        newListNode->next = dummyHead->next;
        dummyHead->next = newListNode;
        size++;
    }
    
    void addAtTail(int val) {
        ListNode* newListNode = new ListNode(val);
        ListNode* cur = dummyHead;
        while(cur->next != nullptr){
            cur = cur->next;
        }
        cur->next = newListNode;
        size++;
    }
    
    void addAtIndex(int index, int val) {
        if(index > size) return;
        index = std::max(0, index);
        ListNode* newListNode = new ListNode(val);
        ListNode* cur = dummyHead;
        while(index > 0){
            cur = cur->next;
            index--;
        }
        newListNode->next = cur->next;
        cur->next = newListNode;
        size++;
    }
    
    void deleteAtIndex(int index) {
        if(index >= size || index < 0) return;
        ListNode* cur = dummyHead;
        while(index > 0){
            cur = cur->next;
            index--;
        }
        ListNode* tmp = cur->next;
        cur->next = tmp->next;
        delete tmp;
        tmp = nullptr;
        size--;
    }
private:
    int size;
    ListNode* dummyHead;

};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */