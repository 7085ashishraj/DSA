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
        int count =  0;
        ListNode* temp = head;
        while(temp != nullptr){
            count++;
            temp = temp->next;
        }
        return count;
    }

    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int length = findLength(head);
        int rem_node = (length - n + 1);
        if(rem_node == 1){
            ListNode* newNode = head->next;
            return newNode;
        }
        ListNode* temp = head;
        for(int i=1;i<rem_node-1;i++){
            temp = temp->next;
        }
        temp->next = temp->next->next;
        return head;
    }
};