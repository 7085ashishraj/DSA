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
    ListNode* reverseList(ListNode* head) {
        //using three pointers
        ListNode* prev = nullptr;
        ListNode* curr = head;
        ListNode* Next = head;

        while(curr != nullptr){
            Next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = Next; 
        }
        return prev;
    }
    bool isPalindrome(ListNode* head) {
        //creating FARZI node
        ListNode* c = new ListNode(100);
        ListNode* tempC = c;
        ListNode* temp = head;
        while(temp != NULL){
            ListNode* node = new ListNode(temp->val);
            tempC->next = node;
            temp = temp->next;
            tempC = tempC->next;
        }
        c = c->next;
        c = reverseList(c);

        ListNode* a = head;
        ListNode* b = c;
        while(a){
            if(a->val != b->val) return false;
            a = a->next;
            b = b->next;
        }
        return true;
    }
};