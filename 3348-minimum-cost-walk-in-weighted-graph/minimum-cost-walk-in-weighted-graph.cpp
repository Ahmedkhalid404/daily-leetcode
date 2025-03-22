class Solution {
private:
    class DSU {
    private:
        vector<int> parent, weight, sz;
        int size;

        int getRoot(const int& x) {
            return parent[x] = (parent[x] == x ? x : getRoot(parent[x]));
        }

        bool marge(int a, int b, int c) {

            int rootA = getRoot(a);
            int rootB = getRoot(b);

            if (rootA == rootB) {
                weight[rootA] &= c;
                return false;
            }

            if (sz[rootA] < sz[rootB])
                swap(rootA, rootB);

            parent[rootB] = rootA;
            sz[rootA] += sz[rootB];
            weight[rootA] &= weight[rootB];
            weight[rootA] &= c;

            return true;
        }

        void init() {
            parent.resize(size);
            sz.resize(size);
            weight.resize(size);
            for (int i = 0; i < size; i++) {
                parent[i] = i;
                sz[i] = 1;
                weight[i] = INT_MAX;
            }
        }

    public:
        explicit DSU(int n) {
            size = n + 5;
            init();
        }

        bool connect(int a, int b, int c) { return marge(a, b, c); }

        bool isConnected(int a, int b) { return getRoot(a) == getRoot(b); }

        int getParent(int x) { return getRoot(x); }

        int mnCost(int a, int b) {
            int rootA = getRoot(a);
            int rootB = getRoot(b);
            if ( rootA != rootB )
                return -1;

            return weight[rootA];
        }
    };

public:
    vector<int> minimumCost(int n, vector<vector<int>>& edges,
                            vector<vector<int>>& queries) {

        DSU dsu(n);


        for (auto& it : edges) {
            int u = it[0];
            int v = it[1];
            int c = it[2];

            dsu.connect(u, v, c);
        }

        vector<int> ans;
        ans.reserve(queries.size());
        for (auto it : queries) {
            ans.push_back(dsu.mnCost(it[0], it[1]));
        }

        return ans;
    }
};
