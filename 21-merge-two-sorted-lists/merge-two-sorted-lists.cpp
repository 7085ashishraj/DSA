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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        //solution using extra space
        // ListNode* tempA = list1;
        // ListNode* tempB = list2;
        // //created a new node
        // ListNode* c = new ListNode(100);
        // ListNode* tempC = c;

        // while(tempA!=nullptr && tempB!=nullptr){
        //     if(tempA->val <= tempB->val){
        //         ListNode* t = new ListNode(tempA->val);
        //         tempC->next = t;
        //         tempC = t;
        //         tempA = tempA->next;
        //     }
        //     else{
        //         ListNode* t = new ListNode(tempB->val);
        //         tempC->next = t;
        //         tempC = t;
        //         tempB = tempB->next;
        //     }
        // }
        // if(tempA == nullptr){
        //     tempC->next = tempB;
        // }else{
        //     tempC->next = tempA;
        // }
        // return c->next;

        //In O(1) space:-

        ListNode* c = new ListNode(100);
        ListNode* t = c;

        while(list1!=nullptr && list2!=nullptr){
            if(list1->val <= list2->val){
                t->next = list1;
                list1 = list1->next;
                t = t->next;
            }
            else{
                t->next = list2;
                list2 = list2->next;
                t = t->next;
            }
        }
        if(list1==nullptr) t->next = list2;
        else t->next = list1;
        return c->next;
    }
};