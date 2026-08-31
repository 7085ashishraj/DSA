class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        //starting from 1 coz it's sure that first and last will not be critical point
        int idx = 1;

        //creating 3 node to compare each node
        ListNode* a = head;
        ListNode* b = head->next;
        if(!b) return {-1,-1};
        ListNode* c = head->next->next;

        //two indexes to find the max distance
        int f_idx = -1;
        int s_idx = -1;

        //comparing
        if(c==NULL) return {-1,-1};

        while(c != NULL){
            if((b->val > a->val && b->val > c->val) || (b->val < a->val && b->val < c->val)){
                if(f_idx == -1) f_idx = idx; //first critical point
                 s_idx = idx; //last critical point
               
            }
            //incrementing indxes

            a = a->next;
            b = b->next;
            c = c->next;
            idx++;
        }

        //If less than 2 critical points found
        if(s_idx == -1 || f_idx == s_idx) return {-1,-1};
        //calculate max distance
        int max_dis = s_idx - f_idx;

        //MINIMUM DISTANCE

        int min_dis = INT_MAX;

        //Reinitializing
        f_idx = -1;
        s_idx = -1;

        idx = 1;

        a = head;
        b = head->next;
        c = head->next->next;

        //comparing
        while(c != NULL){
            if((b->val > a->val && b->val > c->val) || b->val < a->val && b->val < c->val){
               f_idx = s_idx;
               s_idx = idx;

               if(f_idx != -1){
                int d = s_idx - f_idx;
                min_dis = min(min_dis, d); 
               }
            }
            //incrementing indxes

            a = a->next;
            b = b->next;
            c = c->next;
            idx++;
        }
        return{min_dis, max_dis};
    }
};