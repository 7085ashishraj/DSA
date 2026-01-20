class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int n = numbers.size();

        int i = 0;
        int j = n-1;

        int sum = numbers[i] + numbers[j];

        while(target != sum){
            if(target < sum) j--;
            else i++;
            sum = numbers[i] + numbers[j];
        }
        return{i+1, j+1};
        
    }
};