class Solution {
public:
    bool isPossible(vector<int>& weights, int mid, int days){
        int sum = 0, ship = 1;
        for(int i=0;i<weights.size();i++){
            if(sum + weights[i] <= mid){
                sum += weights[i];
            }
            else{
                ship++;
                sum = weights[i];
            }
        }
        if(ship <= days){
            return true;
        }
        return false;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int n = weights.size();
        int low = 0;
        int high = 0;

        for(int i=0;i<n;i++){
            if(weights[i] > low){
                low = weights[i];
            }
            high += weights[i];
        }
        while(low <= high){
            int mid = low + (high - low) / 2;
            if(isPossible(weights,mid,days)){
                high = mid - 1;
            }
            else{
                low = mid+1;
            }

        }
        return low;
    }
};