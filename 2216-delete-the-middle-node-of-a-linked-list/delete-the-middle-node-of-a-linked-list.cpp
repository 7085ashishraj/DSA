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
    int findLength(ListNode* head){
        int count = 0;
        ListNode* temp = head;
        while(temp != nullptr){
            count++;
            temp = temp->next;
        }
        return count;
    }

    ListNode* deleteMiddle(ListNode* head) {
        if(head == nullptr || head->next == nullptr){
            return nullptr;
        }
        int length = findLength(head);
        int middle = length / 2;
        ListNode* temp = head;
        for(int i=0;i<middle-1;i++){
            temp = temp->next;
            
        }
        temp->next = temp->next->next;
        return head;
    }
};