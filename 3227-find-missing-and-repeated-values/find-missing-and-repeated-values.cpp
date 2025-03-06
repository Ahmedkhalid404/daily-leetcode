class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {

        int n = static_cast<int>(grid.size());
        
        int freq[ 2500 + 1 ] = {};

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j ++) {

                freq[ grid[i][j] ] ++;
                
            }
        }

        vector<int> res = {-1,-1};
        for (int i = 1; i <= n * n; i++) {
            if ( freq[ i ] == 0 )
                res[1] = i;
            if ( freq[ i ] == 2 )
                res[0] = i;
        }

        return res;
    }
};