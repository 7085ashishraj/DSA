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
    int cntNode(ListNode* head){
        int n = 0;
        ListNode* temp = head;
        while(temp){
            n++;
            temp = temp->next;
        }
        return n;
    }
    ListNode* deleteMiddle(ListNode* head) {
        if(head == nullptr || head->next == nullptr){
            return nullptr;
        }
        int length = cntNode(head);
        int middle = length / 2;
        ListNode* temp = head;
        for(int i=0;i<middle-1;i++){
            temp = temp->next;
        }
        temp->next = temp->next->next;
        return head;
        
    }
};