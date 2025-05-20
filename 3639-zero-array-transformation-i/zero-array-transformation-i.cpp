class Solution {
public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n = int(nums.size());
        vector<int> partial_sum(n + 1);
        for (auto& q : queries) {
            const int l = q[0], r = q[1];
            partial_sum[l] += 1;
            partial_sum[r + 1] -= 1;
        }
        for (int i = 1; i < n; i++) {
            partial_sum[i] = partial_sum[i - 1] + partial_sum[i];
            if (partial_sum[i] < nums[i])
                return false;
        }

        return (nums.front() <= partial_sum.front());
    }
};