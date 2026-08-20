class Solution {
public:
    vector<int> resultArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> arr1;
        vector<int> arr2;
        vector<int> result;
        // First operation
        arr1.push_back(nums[0]);
        // Second operation
        arr2.push_back(nums[1]);

        // Remaining elements
        for (int i = 2; i < n; i++) {
            if (arr1.back() > arr2.back()) {
                arr1.push_back(nums[i]);
            }
            else {
                arr2.push_back(nums[i]);
            }
        }

        // Concatenate arr1 and arr2
        result.insert(result.end(), arr1.begin(), arr1.end());
        result.insert(result.end(), arr2.begin(), arr2.end());

        return result;
    }
};