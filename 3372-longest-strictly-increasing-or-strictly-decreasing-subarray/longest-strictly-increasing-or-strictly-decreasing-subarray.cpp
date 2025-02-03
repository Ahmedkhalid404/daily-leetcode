class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int n = int(nums.size());
        
        int lcs = 1; // longest increasing subarray
        int lds = 1; // longest decreasing subarray
        int dp_lcs = 1;
        int dp_lds = 1;
        for (int i = n - 2; ~i ; --i) {
            dp_lcs = (nums[i] > nums[i + 1]) ? dp_lcs + 1 : 1;
            dp_lds = (nums[i] < nums[i + 1]) ? dp_lds + 1 : 1;
            
            lcs = max(lcs, dp_lcs);
            lds = max(lds, dp_lds);
        }
        
        
        return max(lcs, lds);
    }
};