class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();

        vector dp(n + 5, vector(m + 5, 0));

        /*
         * dp[i][j] = maximum side length of square we can get
         *            if the bottom right corner is `i,j`
         */
        int mx = 0;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (matrix[i - 1][j - 1] == '0')
                    continue;
                dp[i][j] = 1;
                mx = 1;
            }
        }

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (matrix[i - 1][j - 1] == '0')
                    continue;

                if (!dp[i][j - 1] or !dp[i - 1][j])
                    continue;

                dp[i][j] =
                    min({dp[i][j - 1], dp[i - 1][j], dp[i - 1][j - 1]}) + 1;

                mx = max(mx, dp[i][j]);
            }
        }

        return mx * mx;
    }
};