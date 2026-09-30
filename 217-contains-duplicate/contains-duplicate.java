class Solution {
    public boolean containsDuplicate(int[] nums) {
        HashMap<Integer, Integer> mp = new HashMap<>();
        for(int i=0;i<nums.length;i++){
            mp.put(nums[i], mp.getOrDefault(nums[i],0)+1);
        }
        for(int freq : mp.values()){
            if(freq > 1) return true;
        }
        return false;
    }
}