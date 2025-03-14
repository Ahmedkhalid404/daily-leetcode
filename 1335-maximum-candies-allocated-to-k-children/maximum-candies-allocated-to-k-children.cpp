class Solution {
public:
    int maximumCandies(const vector<int>& candies,const long long &k) {

        int n = static_cast<int>(candies.size());

        int64_t st = 0;
        int64_t ed = 1e12;
        int64_t md, ans = -1;

        auto valid = [&]() {
            if( !md ) return true;
            int64_t can = 0;
            for (auto &candi : candies) {
                can += candi / md;

                //cout << can << ' ' << md << '\n';

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

        return ans;

    }
};
