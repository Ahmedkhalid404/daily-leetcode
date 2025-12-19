class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector dp(n + 1, vector(m + 1, INT_MAX));

        /*
         * dp[i][j] -> minimum sum we can get if we start from `1,1` to `i,j`
         */

        dp[1][1] = grid[0][0];

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (i == 1 and j == 1)
                    continue;
                dp[i][j] = min(dp[i - 1][j] , dp[i][j - 1]) + grid[i - 1][j - 1];
            }
        }

        return dp[n][m];
    }
};