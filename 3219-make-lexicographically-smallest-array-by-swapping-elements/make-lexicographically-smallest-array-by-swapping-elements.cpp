class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        int n = nums.size();
        vector<int> vec = nums;
        sort(begin(vec), end(vec));

        int groupNum = 0;
        unordered_map<int, int> numToGroup;
        numToGroup[vec[0]] = groupNum;

        unordered_map<int, list<int>> groupToList;
        groupToList[groupNum].push_back(vec[0]);

        for (int i = 1; i < n; i++) {
            if (abs(vec[i] - vec[i - 1]) > limit) {
                // new group
                groupNum++;
            }

            // assign current element to group
            numToGroup[vec[i]] = groupNum;

            groupToList[groupNum].push_back(vec[i]);
        }

        // iterate through input and overwrite each element with the next
        // element in its corresponding group
        vector<int> result(n);
        for (int i = 0; i < n; i++) {
            int num = nums[i];
            int group = numToGroup[num];
            result[i] = *groupToList[group].begin();
            groupToList[group].pop_front();
        }

        return result;
    }
};