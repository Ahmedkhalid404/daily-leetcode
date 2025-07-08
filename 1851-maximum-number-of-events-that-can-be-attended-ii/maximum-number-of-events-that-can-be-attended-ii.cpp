class Solution {
public:
    int maxValue(vector<vector<int>>& events, int k) {
        sort(events.begin(), events.end());
        int n = events.size();
        dp = vector<vector<int>>(n, vector<int>(k + 1, -1));
        return dfs(0, k, events);
    }

private:
    vector<vector<int>> dp;

    int dfs(int curIndex, int count, const vector<vector<int>>& events) {
        if (count == 0 || curIndex == events.size()) {
            return 0;
        }
        if (dp[curIndex][count] != -1) {
            return dp[curIndex][count];
        }

        int nextIndex = bisectRight(events, events[curIndex][1]);
        int take = events[curIndex][2] + dfs(nextIndex, count - 1, events);
        int skip = dfs(curIndex + 1, count, events);

        dp[curIndex][count] = max(take, skip);
        return dp[curIndex][count];
    }

    int bisectRight(const vector<vector<int>>& events, int target) {
        int left = 0, right = events.size();
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (events[mid][0] <= target) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        return left;
    }
};
