class Solution {
public:
    int maxScore(string &s) {
        int sz = int(s.size());
        int right_ones = int(count(s.begin(), s.end(),'1'));
        int left_zeros = 0;
        int mx = 0;
        for (int i = 0; i < sz - 1; ++i) {
            if( s[ i ] == '1' )
                right_ones --;
            else
                left_zeros ++;

            mx = max(mx, left_zeros + right_ones);
        }
        return mx;
    }
};