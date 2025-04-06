class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = int(nums.size());
        sort(nums.begin(), nums.end());

        vector<int> dp(n, 1), p(n, -1);
        for(int i = 1; i < n; i++) {
            for(int j = 0; j < i; j++) {
                if(nums[i] % nums[j] == 0 && dp[j] + 1 > dp[i]) {
                    dp[i] = dp[j] + 1;
                    p[i] = j;
                }
            }
        }
        int Ians = max_element(dp.begin(), dp.end()) - dp.begin();
        vector<int> ans; ans.reserve(dp[Ians]);
        while(~Ians) {
            ans.push_back(nums[Ians]);
            Ians = p[Ians];
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};