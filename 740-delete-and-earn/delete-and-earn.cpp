class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        map<int, int> mp;
        for (int i = 0; i < nums.size(); i++) {
            mp[nums[i]]++;
        }

        sort(nums.begin(), nums.end());
        auto it = unique(nums.begin(), nums.end());
        nums.resize(distance(nums.begin(), it));

        vector dp(nums.size(), 0);

        /*
         * dp[i] : maximum value we can get if the array from index 0 to i and
         * the numbers is distinct and sorted
         */

        auto getVal = [&](int i) { return mp[nums[i]] * nums[i]; };

        dp[0] = getVal(0);
        if (nums.size() > 1) {
            if (nums[1] - nums[0] > 1) {
                dp[1] = getVal(0) + getVal(1);
            } else {
                dp[1] = max(getVal(0), getVal(1));
            }
        }
        for (int i = 2; i < nums.size(); i++) {
            if (nums[i] - nums[i - 1] > 1) {
                dp[i] = getVal(i) + dp[i - 1];
            } else {
                dp[i] = max(dp[i - 1], getVal(i) + dp[i - 2]);
            }

        }

        return dp[nums.size() - 1];
    }
};