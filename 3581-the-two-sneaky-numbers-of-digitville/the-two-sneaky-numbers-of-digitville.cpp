class Solution {
public:
    vector<int> getSneakyNumbers(vector<int>& nums) {
        vector<int> count(101, 0); // to count the number of occurence 
        vector<int> ans; //store resultant array

        for(int num : nums){
            count[num]++;   //count the frequency of each element
            if(count[num] == 2){
                ans.push_back(num);  
            }
        }

        
        return ans;

    }
};