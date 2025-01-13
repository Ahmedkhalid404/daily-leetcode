class Solution {
public:
    int minimumLength(string &s) {
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