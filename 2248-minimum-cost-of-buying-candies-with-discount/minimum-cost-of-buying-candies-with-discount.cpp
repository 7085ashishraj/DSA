class Solution {
public:
    int minimumCost(vector<int>& cost) {
        int n = cost.size();
        if(n <=2 ){
            return accumulate(cost.begin(), cost.end(),0);
        }
        sort(cost.begin(),cost.end());

        int i = n-1;
        int mini_cost = 0;
        int cnt = 0;
        while(i>=0){
            mini_cost += cost[i];
            cnt++;
            if(cnt == 2){
                i-=2;
                cnt = 0;
            }else{
                i--;
            }
        }
        return mini_cost;
    }
};