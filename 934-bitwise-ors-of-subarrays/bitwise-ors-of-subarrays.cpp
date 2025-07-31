class Solution {
public:
    int subarrayBitwiseORs(vector<int>& arr) {
        int n = arr.size();
        vector dp(n, set<int>());
        dp[0] = {arr[0]};

        for (int i = 1; i < n; i++) {

            dp[i].insert(arr[i]);
            for (auto it : dp[i - 1]) {
                dp[i].insert(it | arr[i]);
            }
        }

        set<int> ans;
        for (int i = 0; i < n; i++) {
            ans.insert(dp[i].begin(), dp[i].end());
        }

        return ans.size();
    }
};