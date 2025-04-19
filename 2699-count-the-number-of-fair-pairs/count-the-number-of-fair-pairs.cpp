class Solution {
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        ranges::sort(nums);
        const int n = static_cast<int>(nums.size());
        int64_t ans = 0;
        for (int i = 0; i < n - 1; i++) {

            int left = lower - nums[i];
            int right = upper - nums[i];

            auto it1 = lower_bound(nums.begin() + i + 1, nums.end(), left);
            auto it2 = upper_bound(nums.begin() + i + 1, nums.end(), right);

            ans = ans + (it2 - it1);
        }

        return ans;
    }
};