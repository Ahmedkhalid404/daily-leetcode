/*
 q[i][0]

 dp[i] -> max points you can get if you start from index `i` to end

 dp[i] -> max( dp[i + 1], q[i][0] + dp[q[i][1] + i + 1] )

 dp[n] -> q[n][0]
 */

public class Solution
{
    public long MostPoints(int[][] q)
    {
        int n = q.Length;

        var dp = new long[n];

        // basecase
        dp[n - 1] = q[n - 1][0];

        for (int i = n - 2; i > -1 ; i --)
        {

            long leave = dp[i + 1];

            long take = q[i][0];

            int nxt = q[i][1] + i + 1;
            if( nxt < n )
            {
                take = take + dp[nxt];
            }

            dp[i] = long.Max(take, leave);
        }

        return dp[0];
    }
}