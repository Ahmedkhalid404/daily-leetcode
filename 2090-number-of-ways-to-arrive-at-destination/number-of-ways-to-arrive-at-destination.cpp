class Solution {
    const static int MOD = 1e9 + 7;
    int64_t add(const int64_t &a, const int64_t &b) {
        return ( (a % MOD) + (b % MOD) ) % MOD;
    }
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int, int>>> graph(n);
        for (auto& it : roads) {
            graph[it[0]].emplace_back(it[1], it[2]);
            graph[it[1]].emplace_back(it[0], it[2]);
        }

        vector<int64_t> dist(n, LLONG_MAX), ways(n, 0);
        priority_queue<pair<int64_t, int>, vector<pair<int64_t, int>>, greater<>> pq;

        dist[0] = 0;
        ways[0] = 1;
        pq.emplace(0, 0);

        while (!pq.empty()) {
            auto [d, u] = pq.top(); pq.pop();
            if (d > dist[u]) continue;

            for (auto& [v, w] : graph[u]) {
                if (dist[v] > dist[u] + w) {
                    dist[v] = dist[u] + w;
                    pq.emplace(dist[v], v);
                    ways[v] = ways[u];
                }else if ( dist[v] == dist[u] + w ) {
                    ways[v] = add(ways[v], ways[u]);
                }
            }
        }

        return ways[n - 1];
    }
};