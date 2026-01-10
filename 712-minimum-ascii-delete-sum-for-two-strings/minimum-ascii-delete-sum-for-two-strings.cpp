class Solution {
public:
int getLCS(const string &a, const string &b) {
    int n = a.size(), m = b.size();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (a[i - 1] == b[j - 1])
                dp[i][j] = dp[i - 1][j - 1] + int(a[i - 1]);
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }

    return dp[n][m];
}

    int minimumDeleteSum(string s1, string s2) {
        int sum = 0;
        for(int i = 0; i < s1.size(); i++){
            sum = sum + int(s1[i]);
        }
        for(int i = 0; i < s2.size(); i++){
            sum = sum + int(s2[i]);
        }

        return sum - 2 * getLCS(s1, s2);
    }
};