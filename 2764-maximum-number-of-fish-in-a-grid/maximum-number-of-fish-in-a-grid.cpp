class Solution {
private:
    vector<int> dx = { 1 , -1 , 0 , 0 },
            dy = { 0 , 0 , 1 , -1 };
    
public:
    int findMaxFish(vector<vector<int>>& grid) {

        int n = int(grid.size());
        int m = int(grid.front().size());

        auto valid = [&](int i,int j,int k){
            int new_i = i + dy[ k ];
            int new_j = j + dx[ k ];

            return (
                    ( ( new_i < n ) && ( new_i > -1) ) &&
                    ( ( new_j < m ) && ( new_j > -1 ) ) &&
                    ( grid[ new_i ][ new_j ] != 0 )
            );
        };

        function<int(int,int)> dfs = [&](int i, int j){
            int val = grid[i][j];
            grid[i][j] = 0; // vis
            
            int sum = val;

            for (int k = 0; k < 4; ++k) {
                if(valid(i, j, k)){
                    int new_i = i + dy[ k ];
                    int new_j = j + dx[ k ];
                    
                    sum += dfs(new_i, new_j);
                }
            }
            
            return sum;
        };

        int mx = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if( grid[i][j] )
                    mx = max(mx, dfs(i, j));
            }
        }

        return mx;
    }
};