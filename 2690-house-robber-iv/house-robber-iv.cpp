class Solution {
public:
    int minCapability(vector<int> nums, int k) {

        const int n = static_cast<int>(nums.size());

        auto [mn, mx] = std::minmax_element(nums.begin(), nums.end());

        int st = *mn;
        int ed = *mx;
        int md, ans = -1;

        auto valid = [&]() {
            int cnt = 0;

            for (int i = 0; i < n; i++) {
                if (nums[i] <= md)
                    cnt++, i++;
            }

            return cnt >= k;
        };

        while (st <= ed) {

            md = (st + ed) >> 1;

            if (valid()) {
                ans = md;
                ed = md - 1;
            } else {
                st = md + 1;
            }
        }

        return ans;
    }
};