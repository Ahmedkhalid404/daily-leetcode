class Solution {
public:
    int countPairs(vector<int>& a, int k) {
        // if (a % k = b)
        // and we want to find `x` such that ( (a * x) % k = 0 )
        // smallest `x` will verification is ( k / gcd(k,b) )
        // and any multable of `x`

        unordered_map<int, deque<int>> idx;

        int n = a.size();

        for (int i = 0; i < n; i++) {
            idx[a[i]].push_back(i);
        }

        int res = 0;

        for (int i = 0; i < n; i++) {
            idx[a[i]].pop_front();

            if (!(i % k))
                res += idx[a[i]].size();

            else {
                int x = k / gcd(k, i);

                int mul = 1;
                while (x * mul <= idx[a[i]].back()) {

                    int st = 0;
                    int ed = idx[a[i]].size() - 1;
                    int md;

                    int need = x * mul;

                    while (st <= ed) {
                        md = (st + ed) >> 1;
                        if (idx[a[i]][md] == need) {
                            res++;
                            break;
                        } else if (idx[a[i]][md] > need) {
                            ed = md - 1;
                        } else {
                            st = md + 1;
                        }
                    }

                    mul++;
                }
            }
        }

        return res;
    }
};