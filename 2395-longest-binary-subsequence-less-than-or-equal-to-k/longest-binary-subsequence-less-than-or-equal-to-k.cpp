class Solution {
public:
    int longestSubsequence(string& s, int k) {
        int ans = 0;
        int64_t weight = 1;
        int total = 0;
        for (int i = s.size() - 1; ~i; i--) {
            if (s[i] == '0') {
                ans++;
            } else {
                if (total + weight <= k) {
                    total += weight;
                    ans++;
                }
            }
            weight = min<int64_t>(1e9 + 1, weight * 2);
        }

        return ans;
    }
};