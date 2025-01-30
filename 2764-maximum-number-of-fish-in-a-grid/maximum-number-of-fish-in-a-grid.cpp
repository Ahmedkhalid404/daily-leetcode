class Solution {
private:
    vector<int> dx = { 1 , -1 , 0 , 0 },
            dy = { 0 , 0 , 1 , -1 };

public:
    int findMaxFish(vector<vector<int>>& grid) {

        int n = int(grid.size());
        int m = int(grid.front().size());

        auto valid = [&](int i,int j,int k)-> optional<pair<int, int>>{
            int new_i = i + dy[ k ];
            int new_j = j + dx[ k ];

            if(
                ( ( new_i < n ) && ( new_i > -1) ) &&
                ( ( new_j < m ) && ( new_j > -1 ) ) &&
                ( grid[ new_i ][ new_j ] != 0 )
                ){
                return make_pair(new_i, new_j);
            }

            return nullopt;
        };

        function<int(int,int)> dfs = [&](int i, int j){

            if( (i < 0) or (i >= n) )
                return 0;
            if( (j < 0) or (j >= m) )
                return 0;


            int val = grid[i][j];
            grid[i][j] = 0; // vis

            int sum = val;

            for (int k = 0; k < 4; ++k) {
                if(auto pos = valid(i, j, k)){
                    sum += dfs(pos->first, pos->second);
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
