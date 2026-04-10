class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        int n = nums.size();
        int min_dis = INT_MAX;

        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                for(int k=j+1;k<n;k++){
                    if(nums[i] == nums[j] && nums[j] == nums[k]){
                        int dis = abs(i-j) + abs(j-k) + abs(k-i);
                        min_dis = min(dis, min_dis);
                    }
                }
            }
        }
        if(min_dis == INT_MAX) return -1;
        else return min_dis;
    }
};