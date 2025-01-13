class Solution {
public:
    static int minimumLength(string &s) {
        ios::sync_with_stdio(false);
        vector< int > freq( int('z' - 'a' + 1) );
        for(auto &ch : s){
            freq[ch - 'a'] ++;
        }

        int res = 0;
        for(auto &it : freq){
            res += it < 3 ? it : ( it & 1 ? 1 : 2 );
        }

        return res;
    }
};