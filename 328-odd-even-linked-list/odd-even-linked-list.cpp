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
    ListNode* oddEvenList(ListNode* head) {
        if(head == nullptr || head->next == nullptr) return head;
        //Creating two different linkedlist
        ListNode* lo = new ListNode(100);
        ListNode* hi = new ListNode(100);
        //tempS to point those two linkedlist
        ListNode* tempLo = lo;
        ListNode* tempHi = hi;

        ListNode* temp = head;
        int idx = 1;

        while(temp != nullptr){
            if(idx % 2 != 0){
                tempLo->next = temp;
                temp = temp->next;
                tempLo = tempLo->next;
            }else{
                tempHi->next = temp;
                temp = temp->next;
                tempHi = tempHi->next;
            }
            idx++;
        } 
        tempLo->next = hi->next;
        tempHi->next = nullptr;
        return lo->next;
    }
};