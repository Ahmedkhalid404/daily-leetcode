class Solution {
public:
    int findLHS(vector<int>& nums) {
        unordered_map<int, int> freq;
        for (auto it : nums)
            freq[it]++;

        int ans = 0;
        for (auto it : freq) {
            ans = max<int>(ans, freq[it.first] + (!freq.contains(it.first + 1)
                                                 ? -1e9
                                                 : freq[it.first + 1]));
        }

        return ans;
    }
};