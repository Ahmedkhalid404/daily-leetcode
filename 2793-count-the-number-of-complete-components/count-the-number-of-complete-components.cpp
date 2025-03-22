class Solution {
public:
    int countCompleteComponents(int n, vector<vector<int>>& g) {

        vector graph(n + 1, vector<int>{});

        for(auto it : g) {

            int u = it[0];
            int v = it[1];

            graph[ u ].push_back(v);
            graph[ v ].push_back(u);

        }

        bitset<50 + 5> vis;
        int nodes = 0;
        int edges = 0;
        int ans = 0;

        auto dfs = [&](auto &&dfs, int node) -> void{

            vis[node] = true;
            nodes ++;
            edges += graph[node].size();


            for (auto it : graph[node]) {

                if ( !vis[it] ) {
                    dfs(dfs, it);
                }

            }

        };

        for (int i = 0; i < n; i++) {
            if ( !vis[i] ) {
                dfs(dfs, i);
                ans += ( nodes * (nodes - 1LL) ) == edges;
                nodes = 0;
                edges = 0;
            }
        }

        return ans;

    }
};