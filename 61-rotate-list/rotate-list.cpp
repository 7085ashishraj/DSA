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
    ListNode* rotateRight(ListNode* head, int k) {
        ListNode* temp = head;
        ListNode* tail = nullptr;
        //if empty list or single node occurs
        if(head == nullptr || head->next == nullptr) return head;
        //count nodes
        int n = 0;
        while(temp != nullptr){
            if(temp->next == nullptr) tail = temp;
            temp = temp->next;
            n++;
        }

        k%=n; //just to avoid large rotation
        if(k==0) return head;

        temp = head;
        //place temp at (n-k) position
        for(int i=1;i<n-k;i++){
            temp = temp->next;
        }

        tail->next = head; //making it circular
        head = temp->next;
        temp->next = nullptr;

        return head;   
    }
};