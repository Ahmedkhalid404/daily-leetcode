class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = int(nums.size());
        vector dp(n, 1);

        int mx = 1;
        for (int i = n - 2; ~i ; --i) {

            for (int j = i + 1; j < n ; ++j) {
                if( nums[j] > nums[i] )
                    dp[i] = max(dp[i], dp[j] + 1);
            }
            mx = max(mx, dp[i]);

        }

        return mx;
    }
};