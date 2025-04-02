class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        const int n = static_cast<int>(nums.size());

        int64_t mx_i = nums[0];
        int64_t d = 0;

        int64_t ans = 0;

        for (int k = 2; k < n; k++) {
            d = max(d, (mx_i - nums[k - 1]));
            ans = max(ans,  d * nums[k] );
            mx_i = max<int64_t>(mx_i, nums[k - 1]);
        }

        return ans;
    }
};