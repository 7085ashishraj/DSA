class Solution {
public:
    int sumFourDivisors(vector<int>& nums) {
        int totalSum = 0;

        for(int ele : nums){
            int cnt = 0;
            int curr_sum = 0; //will be updated in totalSum after passing all cases

            for(int i = 1; i*i <= ele ; i++){
                if(ele%i == 0){
                    if(i*i == ele){ //perfect square case (16 = 4 * 4)
                        cnt += 1;
                        curr_sum += i;
                    }
                    else{
                        cnt += 2;
                        curr_sum += (i + ele/i); //(21 = 7 * 3) 7 and 3 both will be added 
                    }
                }

                if(cnt > 4) break;  //no need to check further
            }

            if(cnt == 4){
                totalSum += curr_sum;
            }
        }
        return totalSum; //returning totalSum
        
    }
};