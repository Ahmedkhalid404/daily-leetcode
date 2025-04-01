class Solution {
public:
    long long mostPoints(vector<vector<int>>& questions) {
        /*
            dp[i] = max points to solve from index `i` to end
            dp[i] = max( dp[i + 1] `leave`,  points[i] + dp[i + skip[i]] `take` )

            // basecase
                dp[n] = points[n]
        */

        int const n = static_cast<int>(questions.size());
        vector dp(n, 0LL);

        dp[n - 1] = questions[n - 1][0];

        for (int i = n - 2; ~i ; i--) {
            int points = questions[i][0];
            int skip   = questions[i][1] + 1;
            
            int64_t leave = dp[i + 1];
            int64_t take = points;
            if ( i + skip < n )
                take = take + dp[i + skip];

            dp[i] = max(take, leave);
        }

        return dp[0];
    }
};