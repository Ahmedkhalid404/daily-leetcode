class Solution {
public:
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        vector graph(numCourses, vector< int >());

        for(auto &it : prerequisites){
            auto [u, v] = make_pair(it[0],it[1]);
            graph[v].push_back(u);
        }

        vector dp(numCourses + 1, vector(numCourses + 1, -1)); // -1 -> no answer

        function<bool(int, int, int)> dfs = [&dp, &graph, &dfs](int node, int a, int b) -> bool{ // if there is a path `a` -> `b`
            if(node == b)
                return true;
            
            if( dp[node][b] != -1 )
                return dp[node][b];

            dp[a][node] = 1;
            dp[node][b] = 0;

            for(auto &child : graph[node]){
                dp[node][b] = dp[node][b] || dfs(child, a, b);
            }

            return dp[node][b];
        };

        vector<bool> res;
        res.reserve(queries.size());
        for (auto it: queries) {
            auto [a, b] = make_pair(it[0], it[1]);
            dfs(b,b,a);
            res.push_back(dp[b][a]);
        }

        return res;
    }
};