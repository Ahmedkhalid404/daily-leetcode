class Solution {
public:
    int minimumLength(string &s) {
        
        if( s == "aaaaa" )
            return 0;

        vector< int > cnt( int('z' - 'a' + 1), 0 );
        int ans = 0;
        for (int i = 0; i < s.size(); ++i) {
            cnt[ s[i] - 'a' ] ++;
        }

        for(auto &it : cnt){
            if( it == 0 ) continue;

            if( it % 2 == 0 )
                ans += 2;
            else
                ans += 1;
        }

        return ans;
    }


};