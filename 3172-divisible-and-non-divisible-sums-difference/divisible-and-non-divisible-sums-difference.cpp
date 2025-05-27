class Solution {
    int sum_from_1_to_n(int n){
        return (n * (n + 1) / 2);
    }
public:
    int differenceOfSums(int n, int m) {

        int st = 0;
        int ed = 1000;
        int md , ans = -1;
        while(st <= ed){
            md = (st + ed) >> 1;
            if( m * md <= n ){
                ans = md;
                st = md + 1;
            } else{
                ed = md - 1;
            }
        }

        return ( sum_from_1_to_n(n) - ( sum_from_1_to_n(ans) * m ) ) - ( sum_from_1_to_n(ans) * m );

        
        
    }
};