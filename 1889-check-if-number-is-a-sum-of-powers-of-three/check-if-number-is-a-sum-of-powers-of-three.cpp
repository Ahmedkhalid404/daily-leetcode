class Solution {
private:
    int64_t fb(int64_t a, int64_t b) {
        if (!b) return 1;

        int64_t mul = 1;
        if (b & 1) mul = a;

        int64_t res = fb(a, b >> 1);
        return res * res * mul;
    }
public:
    bool checkPowersOfThree(int n) {
        bitset<20> vis;
        while ( n ) {

            int st = 0;
            int ed = 20;
            int md, ans = -1;
            while (st <= ed) {
                md = (st + ed) >> 1;
                if ( fb(3, md) <= n ) {
                    ans = md;
                    st = md + 1;
                }
                else {
                    ed = md - 1;
                }
            }
            if (ans == -1) return false;
            if ( vis[ans] ) return false;

            vis[ans] = true;

            n -= fb(3, ans);
        }

        return true;
    }
};