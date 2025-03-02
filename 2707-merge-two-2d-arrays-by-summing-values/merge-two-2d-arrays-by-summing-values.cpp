class Solution {
public:
    vector<vector<int>> mergeArrays(vector<vector<int>>& a, vector<vector<int>>& b) {
        int n = int(a.size());
        int m = int(b.size());
        int i = 0, j = 0;
        vector<vector<int>> res;
        res.reserve(max(n,m));

        while( (i < n) and (j < m) ){
            if( a[i][0] == b[j][0] ){
                res.push_back( { a[i][0], a[i][1] + b[j][1] } );
                i++, j++;
            }
            else if(a[i][0] < b[j][0]){
                res.push_back(a[i ++]);
            }
            else{
                res.push_back(b[j ++]);
            }
        }

        while( i < n ){
            res.push_back(a[i ++]);
        }

        while( j < m ){
            res.push_back(b[j ++]);
        }

        return res;
    }
};
