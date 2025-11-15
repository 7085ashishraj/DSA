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
    ListNode* merge(ListNode* a, ListNode* b){
        ListNode* c = new ListNode(100);
        ListNode* t = c;
        while(a != nullptr && b != nullptr){
            if(a->val <= b->val){
                t->next = a;
                a = a->next;
                t = t->next;
            }
            else{
                t->next = b;
                b = b->next;
                t = t->next;
            }
        }
        if(a==nullptr) t->next = b;
        else t->next = a;
        return c->next;
    }
    ListNode* sortList(ListNode* head) {
        if(head == nullptr || head->next == nullptr) return head;
        ListNode* slow = head;
        ListNode* fast = head;

        //finding left middle of the Listnode
        while(fast->next != nullptr && fast->next->next != nullptr){
            slow = slow->next;
            fast = fast->next->next;
        }
        //Now slow is pointing at the left middle 
        ListNode* a = head;
        ListNode* b = slow->next;
        slow->next = nullptr;

        //Dividing the list through recursion
        a = sortList(a);
        b = sortList(b);

        ListNode* c = merge(a,b);
        return c;
    }
};