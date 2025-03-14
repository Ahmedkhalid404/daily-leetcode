class Solution {
public:
    int maximumCandies(const vector<int>& candies,const long long &k) {
        int64_t st = 1;
        int64_t ed = accumulate(candies.begin(), candies.end(), 0LL);
        int64_t md, ans = 0;

        auto valid = [&]() {
            int64_t can = 0;
            for (auto &candi : candies) {
                can += candi / md;

                if ( can >= k )
                    return true;

            }
            return false;
        };

        while ( st <= ed ) {

            md = (st + ed) >> 1;

            if ( valid() ) {
                ans = md;
                st = md + 1;
            }
            else {
                ed = md - 1;
            }

        }

        return static_cast<int>(ans);

    }
};