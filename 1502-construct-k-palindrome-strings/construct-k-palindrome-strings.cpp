class Solution {
public:
    bool canConstruct(string &s, int k) {
        if(k > s.size()) return false;
        bitset< 26 > freq;
        int odd = 0;
        for(char c : s){
            freq[ c - 'a' ] = not freq[ c - 'a' ];
            if( freq[ c - 'a' ] )
                odd ++;
            else
                odd --;
        }
        return odd <= k;
    }
};