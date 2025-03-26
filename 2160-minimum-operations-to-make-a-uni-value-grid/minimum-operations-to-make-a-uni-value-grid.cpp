class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        int rem = grid[0][0] % x;
        const int n = static_cast<int>(grid.size());
        const int m = static_cast<int>(grid[0].size());

        if ( n * m == 1 ) return 0;

        vector<int> sorted_nums;sorted_nums.reserve(n * m);

        for (int i = 0; i < n; i++) {

            for (int j = 0; j < m; j++) {
                if ( (rem != (grid[i][j] % x)) and (x != 1) )
                    return -1;
                sorted_nums.push_back(grid[i][j]);
            }

        }

        ranges::sort(sorted_nums);

        int md = n * m / 2;

        auto getOp = [&](int num) {
            int64_t ans = 0;
            for (int i = 0; i < n; i++) {

                for (int j = 0; j < m; j++) {
                    int diff = abs(num - grid[i][j]);
                    ans = ans + (diff / x) + (diff % x != 0);
                }

            }
            return ans;
        };

        return min({
            getOp(sorted_nums[md]),
            md - 1 > -1 ? getOp(sorted_nums[md - 1]) : INT_MAX,
            md + 1 < sorted_nums.size() ? getOp(sorted_nums[md + 1]) : INT_MAX
        });


    }
};