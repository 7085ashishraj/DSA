class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        int mid = (n-1)/2;
        int last = n-1;
        vector<int> res(n);
        for(int i=0;i<n;i++){
            if(i%2==0){
                res[i] = nums[mid--];
            }else{
                res[i] = nums[last--];
            }
        }
        nums = res;
    }
};