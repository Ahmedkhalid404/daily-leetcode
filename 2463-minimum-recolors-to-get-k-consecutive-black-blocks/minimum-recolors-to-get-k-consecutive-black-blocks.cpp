class Solution {
public:
    int minimumRecolors(string blocks, int k) {

        int n = static_cast<int>(blocks.size());
        vector prefix_white(n, 0);

        prefix_white[0] = blocks[0] == 'W';

        for (int i = 1; i < n; i++) {
            prefix_white[i] = prefix_white[i - 1] + (blocks[i] == 'W');
        }

        auto numberOfWhiteBlocks = [&](int l, int r) {
            return prefix_white[r] - (!l ? 0 : prefix_white[l - 1]);
        };

        int mn = INT_MAX;

        for (int i = 0; i <= n - k; i++) {
            mn = min(mn, numberOfWhiteBlocks(i, i + k - 1));
        }

        return mn;
    }
};