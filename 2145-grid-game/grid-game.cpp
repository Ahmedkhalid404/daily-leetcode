class Solution {
public:
    long long gridGame(vector<vector<int>>& grid) {
        int size = int(grid[0].size());
        vector< int64_t > pref_down( size + 1 ), suf_top( size + 1 );

        // pref
        for (int i = 0; i < size; ++i) {
            pref_down[i + 1] = pref_down[i] + grid[1][i];
        }

        // suf
        for (int i = size - 1; ~i ; --i) {
            suf_top[i] = suf_top[i + 1] + grid[0][i];
        }

        int64_t mx = 1e15;
        for (int i = 0; i < size; ++i) {
            mx = min({mx, max( pref_down[i], suf_top[i + 1])});
        }

        return mx;

    }
};