class Solution {
public:
    long long gridGame(vector<vector<int>>& grid) {
        int size = int(grid[0].size());
        int64_t pref_down = 0, suf_top = accumulate(grid[0].begin() + 1, grid[0].end(), 0LL);
        int64_t mx = 1e15;
        
        for (int i = 0; i < size; ++i) {
            mx = min({mx, max( pref_down, suf_top)});

            if( i + 1 < size ) suf_top = suf_top - grid[0][i + 1];
            pref_down = pref_down + grid[1][i];
        }
        return mx;

    }
};