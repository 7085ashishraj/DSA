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
        if(head==nullptr || head->next == nullptr) return head;
        int n = 0; //finding length of LinkedList
        while(temp != nullptr){
            if(temp->next==nullptr) tail = temp;
            temp = temp->next;
            n++;
            
        }
        //just to avoid large rotation if k is having large value
        k = k%n;
        if(k==0) return head; // no rotation required

        //place temp at (n-k)th position
        temp = head;
        for(int i=1;i<n-k;i++){
            temp = temp->next;
        }

        tail->next = head;
        head = temp->next;
        temp->next = nullptr;
        return head;

    }
};