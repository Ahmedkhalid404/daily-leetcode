class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        int n = int(grid.size());
        int m = int(grid.front().size());
        vector row(n, 0), col(m, 0);

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if(grid[i][j])
                    row[i] ++, col[j] ++;
            }
        }

        int res = 0;
        for (int i = 0; i < n; ++i) {

            for (int j = 0; j < m; ++j) {
                if( (grid[i][j]) and (row[i] > 1 or col[j] > 1) )
                    res ++;
            }

        }
        
        return res;
    }
};
