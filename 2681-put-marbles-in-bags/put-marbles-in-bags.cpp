class Solution {
public:
    long long putMarbles(vector<int> & weights, int k) {
        const int n = static_cast<int>(weights.size());
        vector<int> cuts;cuts.reserve(weights.size());

        for (int i = 1; i < n; i++) {
            cuts.push_back(weights[i] + weights[i - 1]);
        }

        ranges::sort(cuts);

        int64_t mn = 0, mx = 0;
        for (int i = 0; i < k - 1; i++) {
            mn = mn + cuts[i];
            mx = mx + cuts[cuts.size() - 1 - i];
        }

        return mx - mn;
    }
};