class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {
        map< int , int > freq, color;
        int res = 0;

        vector<int> ans;ans.reserve(queries.size());
        for(auto &q : queries){

            auto [x, y] = make_pair(q[0], q[1]);

            if( color[x] != 0 ){
                freq[ color[ x ] ] --;

                if( freq[ color[ x ] ] < 1 )
                    res --;
            }

            color[ q[0] ] = q[1];
            if( !freq[ color[ x ] ] )
                res ++;
            
            freq[ color[ x ] ] ++;
            
            ans.push_back(res);
        }

        return ans;
    }
};
