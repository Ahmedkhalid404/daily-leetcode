class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int n = int(nums.size());
        int dp = nums.back();
        int mx = dp;

        for (int i = n - 2; ~i ; --i) {
            dp = nums[i] < nums[i + 1] ? dp + nums[i] : nums[i];
            
            mx = max(mx, dp);
        }
        
        return mx;
    }
};