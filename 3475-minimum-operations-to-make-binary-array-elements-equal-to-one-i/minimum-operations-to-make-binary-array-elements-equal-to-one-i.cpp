class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = static_cast<int>(nums.size());
        int ans = 0;

        for (int i = 0; i < n - 2; i++) {
            if (!nums[i]) {
                nums[i + 0] = !nums[i + 0];
                nums[i + 1] = !nums[i + 1];
                nums[i + 2] = !nums[i + 2];
                ans++;
            }
        }

        for (int i = 0; i < n; i++) {
            if (!nums[i])
                return -1;
        }

        return ans;
    }
};