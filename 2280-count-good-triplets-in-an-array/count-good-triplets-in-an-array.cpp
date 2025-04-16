template <class T = long long> struct BIT { // 1-based
    vector<T> tree;
    explicit BIT(int size = 1e6) { tree.resize(size + 1); }

    void update(int i, T val) {
        assert(i > 0);
        while (i < tree.size()) {
            tree[i] += val;
            i += (i & -i);
        }
    }

    T query(int i) {
        T sum = 0;
        while (i > 0) {
            sum += tree[i];
            i -= (i & -i);
        }
        return sum;
    }

    T rangeQuery(int l, int r) { return query(r) - query(l - 1); }
};

class Solution {
public:
    long long goodTriplets(vector<int>& a, vector<int>& b) {

        int n = a.size();

        BIT ds(n + 5);

        vector<int> idx_a(n);
        for (int i = 0; i < n; i++) {
            idx_a[a[i]] = i;
        }

        vector<int64_t> ans_before(n), ans_after(n);

        ds.update(idx_a[b[0]] + 1, 1);

        for (int i = 1; i < n; i++) {
            ans_before[i] = ds.rangeQuery(1, idx_a[b[i]] + 1);

            ds.update(idx_a[b[i]] + 1, 1);
        }

        BIT ds_back(n + 5);

        ds_back.update(idx_a[b[n - 1]] + 1, 1);

        for (int i = n - 2; ~i; i--) {
            ans_after[i] = ds_back.rangeQuery(idx_a[b[i]] + 1, n);

            ds_back.update(idx_a[b[i]] + 1, 1);
        }

        int64_t ans = 0;

        for (int i = 0; i < n; i++) {
            ans += ans_before[i] * ans_after[i];
        }

        return ans;
    }
};