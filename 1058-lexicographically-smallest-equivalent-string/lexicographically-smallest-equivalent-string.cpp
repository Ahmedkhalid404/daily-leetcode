class Solution {
    class DSU {
    private:
        int size{};
        vector<int> parent;

        int getRoot(int x) {
            return parent[x] = (parent[x] == x ? x : getRoot(parent[x]));
        }

        bool isUnion(int a, int b) { return getRoot(a) == getRoot(b); }

        void Union(int a, int b) {
            int rootA = getRoot(a);
            int rootB = getRoot(b);

            if (rootA == rootB)
                return;

            if (rootA > rootB)
                swap(rootA, rootB);

            parent[rootB] = rootA;
        }

        void init(int n) {
            size = n;
            parent.resize(n);

            for (int i = 0; i < n; ++i) {
                parent[i] = i;
            }
        }

    public:
        explicit DSU() { init(int('z' - 'a' + 10)); }

        void connect(char a, char b) { Union(a - 'a', b - 'a'); }

        bool isConnected(char a, char b) { return isUnion(a - 'a', b - 'a'); }

        char getComponent(char a) { return char(getRoot(a - 'a') + 'a'); }
    };

public:
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        DSU dsu;
        for (int i = 0; i < s1.size(); ++i) {
            dsu.connect(s1[i], s2[i]);
        }

        for (int i = 0; i < baseStr.size(); ++i) {
            baseStr[i] = dsu.getComponent(baseStr[i]);
        }

        return baseStr;
    }
};