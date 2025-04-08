class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        int const n = nums.size();
        for(int i = 0; i < n; i ++){
            sum += nums[i];
        }
        if( sum & 1 ) return false;

        /*
            dp[i][j] -> can we form sum equal to `j` from index `i` to end
            
            dp[i][j] = (dp[i + 1][j]) or (dp[i + 1][j - nums[i]])
            
            dp[n][0] = dp[n][ nums[0] ] = true

        */

        vector<vector<int>> dp(n + 1, vector<int>(100 * 200 + 5));

        dp[n - 1][0] = dp[n - 1][ nums[n - 1] ] = true;

        for(int i = n - 2; ~i ; i--){
            dp[i][0] = true;
            for(int j = 1; j <= 100 * 200; j++){
                dp[i][j] = dp[i + 1][j]; // leave
                if(j >= nums[i]){
                    dp[i][j] |= dp[i + 1][j - nums[i]]; // take 
                }
            }
        }

        return dp[0][sum / 2];

    }
};
