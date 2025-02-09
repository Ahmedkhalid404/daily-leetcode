class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        unordered_map<int, int> freq;
        int64_t ans = 0;
        for(int i = 0; i < nums.size(); i++)
            ans = ans + (i - freq[ nums[i] - i ] ++);
        return ans;
    }
};