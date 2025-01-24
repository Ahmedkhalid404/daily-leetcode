class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = int(graph.size());

        vector< int > dp(1e4 + 4, -1);
        bitset< int(1e4 + 4) > vis;
        
        function<int(int)> dfs = [&](int node) -> int {

            if( graph[node].size() == 0 ) {// leaf
                dp[node] = true;
                return 1;
            }

            if( dp[node] != -1 )
                return dp[node];

            vis[node] = true;
            int cnt = 0;
            dp[node] = 0;
            
            for(auto &it : graph[node]){
                if(!vis[it])
                    cnt += (dfs(it) != 0);
                else
                    cnt += (dp[it] != 0);
            }

            return dp[node] = (cnt == graph[node].size());
        };

        for (int i = 0; i < n; ++i) {
            if( !vis[i] )
                dfs(i);
        }

        vector< int > res;

        for (int i = 0; i < n; ++i) {
            if( dp[i] == 1 )
                res.push_back(i);
        }

        return res;
    }
};