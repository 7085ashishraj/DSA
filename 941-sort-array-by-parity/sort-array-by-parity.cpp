class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        vector<int> odd_ele;
        vector<int> even_ele;
        vector<int> res;
        for(int ele : nums){
            if(ele % 2 != 0){
                odd_ele.push_back(ele);
            }
            else {
                even_ele.push_back(ele);
            }
        }

        for(int i=0;i< even_ele.size(); i++){
            res.push_back(even_ele[i]);
        }

        for(int i=0;i< odd_ele.size(); i++){
            res.push_back(odd_ele[i]);
        }
        return res;

        
    }
};