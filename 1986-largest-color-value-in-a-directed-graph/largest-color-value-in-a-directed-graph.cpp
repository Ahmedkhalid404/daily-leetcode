class Solution {
public:
    int largestPathValue(string colors, vector<vector<int>>& edges) {
        int n = colors.size();
        vector<vector<int>> graph(n);
        vector<int> inDegree(n, 0);

        for (auto& e : edges) {
            graph[e[0]].push_back(e[1]);
            inDegree[e[1]]++;
        }

        vector<vector<int>> dp(n, vector<int>(26, 0));
        queue<int> q;

        for (int i = 0; i < n; ++i) {
            if (inDegree[i] == 0) {
                q.push(i);
            }
        }

        int visited = 0, res = 0;
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            visited++;

            int color = colors[u] - 'a';
            dp[u][color]++;
            res = max(res, dp[u][color]);

            for (int v : graph[u]) {
                for (int c = 0; c < 26; ++c) {
                    dp[v][c] = max(dp[v][c], dp[u][c]);
                }
                if (--inDegree[v] == 0) {
                    q.push(v);
                }
            }
        }

        return (visited == n) ? res : -1;
    }
};