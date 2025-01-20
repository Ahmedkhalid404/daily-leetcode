class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        int n = int(mat.size());
        int m = int(mat[0].size());
        int size = n * m;

        map< int, pair< int, int > > mapping;
        map< int , int > row, col;
        
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                mapping[ mat[i][j] ] = {i,j};
            }
        }

        for (int i = 0; i < size; ++i) {
            
            auto [y, x] = mapping[ arr[i] ];
            row[ y ] --;
            col[ x ] --;
            
            cout << y << ' ' << x << ' ' << row[y] << ' ' << col[ x ] << '\n';

            if( (abs( row[y] ) == m) or (abs( col[x] ) == n ) )
                return i;
        }
        
        assert(false); // we should return before the loop end
        return -1;
    }
};