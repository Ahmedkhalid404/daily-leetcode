class Solution {
public:
    void setZeroes(vector<vector<int>>& g) {
        int n = int(g.size());
        int m = int(g[0].size());

        set<int> row, col;

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(!g[i][j]) {
                    row.insert(i);
                    col.insert(j);
                }
            }
        }

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(row.contains(i) or col.contains(j)) {
                    g[i][j] = 0;
                }
            }
        }


    }
};