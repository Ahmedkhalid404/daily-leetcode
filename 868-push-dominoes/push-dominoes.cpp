class Solution {
public:
    string pushDominoes(string dominoes) {
        vector<pair<int, char>> symbols;
        for (int i = 0; i < dominoes.size(); ++i) {
            if (dominoes[i] != '.') {
                symbols.emplace_back(i, dominoes[i]);
            }
        }

        symbols.insert(symbols.begin(), {-1, 'L'});
        symbols.emplace_back(dominoes.size(), 'R');

        string ans = dominoes;
        for (int idx = 0; idx < symbols.size() - 1; ++idx) {
            int i = symbols[idx].first;
            char x = symbols[idx].second;
            int j = symbols[idx + 1].first;
            char y = symbols[idx + 1].second;

            if (x == y) {
                for (int k = i + 1; k < j; ++k) {
                    ans[k] = x;
                }
            } else if (x == 'R' && y == 'L') {
                int l = i + 1, r = j - 1;
                while (l < r) {
                    ans[l++] = 'R';
                    ans[r--] = 'L';
                }
            }
        }

        return ans;
    }
};
