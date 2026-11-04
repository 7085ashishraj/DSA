class Solution {
public:
    typedef long long ll;
    vector<ll> slidingWindowMedian(vector<int> &nums, int x) {
        vector<ll> medians;

        multiset<int> left, right; //why -> coz we can easily handle duplicate ele as well  why not heap --->we need to delete ele as well when we slide window size so, in heap deletion---a bit muskill

        ll leftSum = 0;
        ll rightSum = 0;

        int i = 0;
        int j = 0;
        int n = nums.size();

        //created custom-function for balancing
        auto balance = [&]() {

            int required = (left.size() + right.size() + 1) / 2;

            while(left.size() > required) {

                int val = *left.rbegin();

                left.erase(prev(left.end()));
                leftSum -= val;

                right.insert(val);
                rightSum += val;
            }

            while(left.size() < required && !right.empty()) {

                int val = *right.begin();

                right.erase(right.begin());
                rightSum -= val;

                left.insert(val);
                leftSum += val;
            }

            // Maintain ordering
            while(!left.empty() && !right.empty() &&
                  *left.rbegin() > *right.begin()) {

                int a = *left.rbegin();
                int b = *right.begin();

                left.erase(prev(left.end()));
                right.erase(right.begin());

                leftSum -= a;
                rightSum -= b;

                left.insert(b);
                right.insert(a);

                leftSum += b;
                rightSum += a;
            }

            // size can become invalid after swaps
            required = (left.size() + right.size() + 1) / 2;

            while(left.size() > required) {

                int val = *left.rbegin();

                left.erase(prev(left.end()));
                leftSum -= val;

                right.insert(val);
                rightSum += val;
            }

            while(left.size() < required && !right.empty()) {

                int val = *right.begin();

                right.erase(right.begin());
                rightSum -= val;

                left.insert(val);
                leftSum += val;
            }
        };

        while(j < n){

            //insert new ele in sliding window
            if(left.empty() || nums[j] <= *left.rbegin()){

                left.insert(nums[j]);
                leftSum += nums[j];

            }else{

                right.insert(nums[j]);
                rightSum += nums[j];
            }

            balance();

            // int leftSize = left.size();
            // int rightSize = right.size();

            // //now we need to balance multiset to maintain median
            // while(leftSize > 0 && rightSize > 0){
            //     int leftMax = *left.rbegin(); //rbegin-> pointer pointer to reverse
            //     int rightMin = *right.begin();
            //     if(leftMax > rightMin){
            //         //swap element to balance
            //         left.insert(rightMin);
            //         right.insert(leftMax);

            //         //ab delete ek line me hojaayega
            //         left.erase(left.find(leftMax));
            //         right.erase(right.find(rightMin));

            //         leftSize = left.size();
            //         rightSize = right.size();
            //     } else{
            //         break;
            //     }
            // }

            //check if we have a valid subaaray
            if (j - i + 1 == x) {

                ll median = *left.rbegin();

                long long cost =
                    (median * (ll)left.size() - leftSum) +
                    (rightSum - median * (ll)right.size());

                medians.push_back(cost);

                // Remove leftmost element
                auto it = left.find(nums[i]);

                if(it != left.end()) {

                    left.erase(it);
                    leftSum -= nums[i];

                } else {

                    it = right.find(nums[i]);

                    if(it != right.end()) {
                        right.erase(it);
                        rightSum -= nums[i];
                    }
                }

                i++;

                balance();
            }

            j++;
        }

        return medians;
    }

    long long minOperations(vector<int>& nums, int x, int k) {

        int n = nums.size();

        //calculating cost req. for every window
        vector<long long> cost = slidingWindowMedian(nums, x);

        int m = cost.size();

        const long long INF = 1e18;

        vector<vector<long long>> dp(
            m + 1,
            vector<long long>(k + 1, INF)
        );

        // Base case
        for(int i = 0; i <= m; i++) {
            dp[i][0] = 0;
        }

        //DP
        for(int i = m - 1; i >= 0; i--) {

            for(int j = 1; j <= k; j++) {

                //Ist choice:- Skip current window
                dp[i][j] = dp[i + 1][j];

                // IInd choice:- Pick current window
                int nxt = min(m, i + x);

                if(dp[nxt][j - 1] != INF) {

                    dp[i][j] = min(
                        dp[i][j],
                        cost[i] + dp[nxt][j - 1]
                    );
                }
            }
        }

        return dp[0][k];
    }
};