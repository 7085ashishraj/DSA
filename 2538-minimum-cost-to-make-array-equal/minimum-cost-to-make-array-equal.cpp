class Solution {
public:
    //typedef long long ll;
    long long findCost(vector<int> &nums, vector<int> &cost, long long target){
        long long result = 0;
        for(int i=0;i<nums.size();i++){
            result += abs(target - nums[i]) * cost[i];
        }

        return result;
    }
    long long minCost(vector<int>& nums, vector<int>& cost) {
        int n = nums.size();
        long long minEle = *min_element(nums.begin(), nums.end());
        long long maxEle = *max_element(nums.begin(), nums.end());

        long long answer = INT_MAX;

        long long low = minEle;
        long long high = maxEle;

        while(low <= high){
            long long mid = low + (high - low)/2;

            long long cost1 = findCost(nums, cost, mid);
            long long cost2 = findCost(nums, cost, mid+1);

            answer = min(cost1, cost2);
            if(cost1 > cost2){
                low = mid + 1;
            }
            else{
                high = mid - 1;
            }
        }
        return answer == INT_MAX ? 0 : answer;
    }
};