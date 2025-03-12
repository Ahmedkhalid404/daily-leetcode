class Solution {
public:
    int maximumCount(const vector<int>& nums) {

        int n = static_cast<int>(nums.size());

        // first pos
        int st = 0;
        int ed = n - 1;
        int md, ans = -1;

        while ( st <= ed ) {
            md = (st + ed) >> 1;

            if ( nums[md] > 0 ) {
                ans = md;
                ed = md - 1;
            }
            else {
                st = md + 1;
            }

        }

        const int firstPos = ans;

        // last neg

        st = 0;
        ed = n - 1;
        ans = -1;

        while ( st <= ed ) {
            md = (st + ed) >> 1;

            if ( nums[md] < 0 ) {
                ans = md;
                st = md + 1;
            }
            else {
                ed = md - 1;
            }

        }

        const int lastNeg = ans;


        const int pos = firstPos == -1 ? 0 : n - firstPos;
        const int neg = lastNeg + 1;

        return max(pos, neg);
    }
};
