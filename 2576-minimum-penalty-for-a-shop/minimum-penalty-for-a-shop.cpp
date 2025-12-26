class Solution {
public:
    int bestClosingTime(string customers) {
        int n = customers.size();
        int totalCustomers = 0;
        for(char c : customers){
            if(c == 'Y'){
                totalCustomers++;
            }
        }

        int mini_penalty = 1e9;
        int prefix = 0;
        int time = n;

        for(int i=0;i<=n;i++){
            int remCustomers = totalCustomers - prefix; //shop closed here
            int penalty = i - prefix;
            penalty += remCustomers;

            if(mini_penalty > penalty){
                mini_penalty = penalty;
                time = i;
            }

            if(i != n && customers[i] == 'Y'){
                prefix++;
            }
        }
        return time;
    }
};