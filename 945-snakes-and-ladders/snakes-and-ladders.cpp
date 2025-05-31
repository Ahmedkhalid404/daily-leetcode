class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& board) {
        int n = board.size();
        vector<int> flattened(n * n, -1);

        int idx = 0;
        bool leftToRight = true;
        for (int r = n - 1; r >= 0; --r) {
            if (leftToRight) {
                for (int c = 0; c < n; ++c) {
                    flattened[idx++] = board[r][c];
                }
            } else {
                for (int c = n - 1; c >= 0; --c) {
                    flattened[idx++] = board[r][c];
                }
            }
            leftToRight = !leftToRight;
        }

        queue<int> q;
        q.push(0);
        vector<bool> visited(n * n, false);
        visited[0] = true;
        int moves = 0;

        while (!q.empty()) {
            int size = q.size();
            while (size--) {
                int curr = q.front(); q.pop();
                if (curr == n * n - 1) return moves;

                for (int dice = 1; dice <= 6; ++dice) {
                    int next = curr + dice;
                    if (next >= n * n) break;

                    int destination = (flattened[next] == -1) ? next : flattened[next] - 1;
                    if (!visited[destination]) {
                        visited[destination] = true;
                        q.push(destination);
                    }
                }
            }
            ++moves;
        }

        return -1; // Not reachable
    }
};
