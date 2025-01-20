class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        int n = int(mat.size());
        int m = int(mat[0].size());
        int size = n * m;

        pair< int , int > mapping[ n * m + 1 ];
        int row[n + 1], col[m + 1];
        fill(row, row + n + 1, 0);
        fill(col, col + m + 1, 0);
        
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                mapping[ mat[i][j] ] = {i,j};
            }
        }

        for (int i = 0; i < size; ++i) {

            auto [y, x] = mapping[ arr[i] ];
            row[ y ] ++;
            col[ x ] ++;


            if( (row[y] == m) or (col[x] == n) )
                return i;
        }

        assert(false); // we should return before the loop end
        return -1;
    }
};