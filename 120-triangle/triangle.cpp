class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        int m = triangle[n - 1].size();
        vector dp(n + 1, vector(m + 1, INT_MAX));

        /**
         * dp[i][j] -> minimum summation if we start from `1,1` to `i,j`
         */

        dp[1][1] = triangle[0][0];

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= triangle[i - 1].size(); j++) {
                if (i == 1 and j == 1)
                    continue;

                dp[i][j] = min(dp[i - 1][j], dp[i - 1][j - 1]) +
                           triangle[i - 1][j - 1];
            }
        }

        return *ranges::min_element(dp[n]);
    }
};