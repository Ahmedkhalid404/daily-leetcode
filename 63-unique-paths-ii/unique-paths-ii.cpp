class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n = obstacleGrid.size();
        int m = obstacleGrid[0].size();
        vector dp(n + 5, vector(m + 5, 0));

        /*
         * dp[i][j] -> number of distinct ways to go from `1,1` to `i,j`
         */

        if(obstacleGrid[0][0] == 0)
            dp[1][1] = 1;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if ((i == 1 and j == 1) or obstacleGrid[i - 1][j - 1])
                    continue;

                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
        }

        return dp[n][m];
    }
};