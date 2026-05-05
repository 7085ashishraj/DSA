class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int n = customers.size();

        int maxUnsat_cus = 0;
        int curr_unsat_cus = 0;

        for(int i=0;i<minutes;i++){
            curr_unsat_cus += customers[i] * grumpy[i];
        }

        maxUnsat_cus = curr_unsat_cus;

        //khandani template of sliding window
        int i = 0;
        int j = minutes;
        while(j<n){
            curr_unsat_cus += customers[j] * grumpy[j];
            curr_unsat_cus -= customers[i] * grumpy[i];
            maxUnsat_cus = max(maxUnsat_cus, curr_unsat_cus);
            i++;
            j++;
        }

        int totalSat = maxUnsat_cus; //since they were unsatisfied we can use power to satisfy
        for(int i=0;i<n;i++){
            totalSat += customers[i] * (1 - grumpy[i]);
        }
        return totalSat;    
    }

};