class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector dp(2, vector(m + 5, INT_MAX));

        /*
         * dp[i][j] = minimum summation if we start from any point in first row
         *            to `i,j`
         */

        for (int j = 1; j <= m; j++)
            dp[1 & 1][j] = matrix[0][j - 1];

        for (int i = 2; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                dp[i & 1][j] =
                    min({dp[(i - 1) & 1][j], dp[(i - 1) & 1][j - 1], dp[(i - 1) & 1][j + 1]}) +
                    matrix[i - 1][j - 1];
            }
        }

        return *ranges::min_element(dp[n & 1]);
    }
};