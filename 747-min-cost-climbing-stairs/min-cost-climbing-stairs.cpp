class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = (int)(cost.size());
        vector<int> dp(n + 5);
        dp[0] = cost[0];
        dp[1] = cost[1];
        cost.push_back(0);
        cost.push_back(0);


        for(int i = 2; i <= n + 1; i++){
            dp[i] = min(dp[i - 1], dp[i - 2]) + cost[i];
        }

        return dp[n + 1];
    }
};