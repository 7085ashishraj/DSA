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
    ListNode* merge(ListNode* list1, ListNode* list2){
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

    ListNode* mergeKLists(vector<ListNode*>& arr) {
        if(arr.size()==0) return nullptr;
        while(arr.size()>1){
            ListNode* a = arr[0];
            arr.erase(arr.begin());
            ListNode* b = arr[0];
            arr.erase(arr.begin());
            ListNode* c = merge(a, b);
            arr.push_back(c);
        }
        return arr[0];
    }
};