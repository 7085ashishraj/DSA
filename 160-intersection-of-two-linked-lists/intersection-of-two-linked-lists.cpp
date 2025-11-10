/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    int findLength(ListNode* head) {
        int count = 0;
        ListNode* temp = head;
        while (temp != nullptr) {
            count++;
            temp = temp->next;
        }
        return count;
    }

    ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
        int lA = findLength(headA);
        int lB = findLength(headB);

        ListNode* temp1 = headA;
        ListNode* temp2 = headB;
        if (lA > lB) {
            int diff = lA - lB;
            for (int i = 1; i <= diff; i++) {
                temp1 = temp1->next;
            }
            while (temp1 != temp2) {
                temp1 = temp1->next;
                temp2 = temp2->next;
            }
            return temp1;
        } else {
            int diff = lB - lA;
            for(int i=1;i<=diff;i++){
                temp2 = temp2->next;
            }
            while (temp1 != temp2) {
                temp1 = temp1->next;
                temp2 = temp2->next;
            }
            return temp1;
        }
    }
};