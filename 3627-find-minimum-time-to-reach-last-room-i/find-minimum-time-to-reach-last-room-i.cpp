class Solution {
public:
    int minTimeToReach(vector<vector<int>>& g) {
        const int n = int(g.size());
        const int m = int(g[0].size());

        auto dijkstra = [&](pair<int, int> start) {
            priority_queue<pair<int, pair<int, int>>,
                           vector<pair<int, pair<int, int>>>, greater<>>
                pq;

            vector dist(n + 1, vector(m + 1, -1));

            pq.emplace(0, start);
            dist[start.first][start.second] = 0;

            while (!pq.empty()) {
                auto top = pq.top();
                pq.pop();
                auto cost = top.first;
                auto node = top.second;

                if (dist[node.first][node.second] != cost)
                    continue;

                for (auto it :
                     vector<pair<int, int>>{{0, 1}, {0, -1}, {1, 0}, {-1, 0}}) {
                    auto isValid = [&]() -> bool {
                        auto new_node = make_pair(node.first + it.first,
                                                  node.second + it.second);

                        return (new_node.first >= 0 && new_node.first < n &&
                                new_node.second >= 0 && new_node.second < m);
                    };

                    if (isValid()) {
                        auto new_node = make_pair(node.first + it.first,
                                                  node.second + it.second);
                        int mx = max(cost, g[new_node.first][new_node.second]);
                        if (dist[new_node.first][new_node.second] == -1 or
                            mx + 1 < dist[new_node.first][new_node.second]) {
                            pq.emplace(mx + 1, new_node);
                            dist[new_node.first][new_node.second] = mx + 1;
                        }
                    }
                }
            }

            return dist[n - 1][m - 1];
        };

        return dijkstra({0, 0});
    }
};