class Solution {
private:
    class DSU {
    private:
        vector<int> parent, sz;
        int size;

        int getRoot(const int& x) {
            return parent[x] = (parent[x] == x ? x : getRoot(parent[x]));
        }

        bool marge(int a, int b) {

            int rootA = getRoot(a);
            int rootB = getRoot(b);

            if (rootA == rootB)
                return false;

            if (sz[rootA] < sz[rootB])
                swap(rootA, rootB);

            parent[rootB] = rootA;
            sz[rootA] += sz[rootB];

            return true;
        }

        void init() {
            parent.resize(size);
            sz.resize(size);
            for (int i = 0; i < size; i++) {
                parent[i] = i;
                sz[i] = 1;
            }
        }

    public:
        explicit DSU(int n) {
            size = n + 5;
            init();
        }

        bool connect(int a, int b) { return marge(a, b); }

        bool isConnected(int a, int b) { return getRoot(a) == getRoot(b); }

        int getParent(int x) { return getRoot(x); }
    };

public:
    vector<int> minimumCost(int n, vector<vector<int>>& edges,
                            vector<vector<int>>& queries) {

        DSU dsu(n);
        vector<vector<pair<int, int>>> graph(n + 1);

        map<pair<int, int>, pair<int, int>> mapping;

        for (auto& it : edges) {
            int u = it[0];
            int v = it[1];
            int c = it[2];

            if ( u > v )
                swap(u, v);

            if ( mapping.contains({u, v}) ) {
                auto [i, j] = mapping[{u,v}];
                graph[u][i].second &= c;
                graph[v][j].second &= c;
            }
            else {
                graph[u].emplace_back(v, c);
                graph[v].emplace_back(u, c);

                mapping[ {u, v} ] = {graph[u].size() - 1, graph[v].size() - 1};
            }

        }

        bitset<int(1e5 + 5)> vis;
        map<int, unsigned int> res;
        auto dfs = [&](auto&& dfs, int node, int root) -> int {
            vis[node] = true;

            dsu.connect(root, node);

            int ret = INT_MAX;
            for (auto it : graph[node]) {
                if (!vis[it.first]) {
                    ret &= it.second;
                    ret &= dfs(dfs, it.first, root);
                }
                else{
                    ret &= it.second;
                }
            }

            cout << node << ' ' << ret << '\n';

            return ret;
        };

        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                int x = int(dfs(dfs, i, i));
                res[dsu.getParent(i)] = x;
            }
        }

        vector<int> ans;
        ans.reserve(queries.size());
        for (auto it : queries) {
            if (dsu.isConnected(it[0], it[1])) {
                ans.push_back(res[dsu.getParent(it[0])]);
            } else {
                ans.push_back(-1);
            }
        }

        return ans;
    }
};