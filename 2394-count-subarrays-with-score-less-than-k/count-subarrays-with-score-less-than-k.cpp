class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        int n = int(nums.size());
        int l = 0, r = -1;
        int64_t sum = 0;
        int64_t ans = 0;
        while( (r + 1) < n ){
            sum = sum + nums[ ++r ];

            while( (l <= r) and ((sum * (r - l + 1)) >= k) ){
                sum = sum - nums[l ++];
            }

            ans = ans + (r - l + 1);
        }
        return ans;
    }
};