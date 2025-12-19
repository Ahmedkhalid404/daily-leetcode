class Solution {
public:
    int uniquePaths(int m, int n) {
        vector dp(m + 2, vector(n + 2, 0));

        /*
         * dp[i][j] -> number of distinct ways to go from `1,1` --1-based-- to
         * `i,j`
         */

        dp[1][1] = 1;

        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (i == 1 and j == 1)
                    continue;
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
        }

        return dp[m][n];
    }
};