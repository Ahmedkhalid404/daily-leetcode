class Solution {
public:
    string clearDigits(string s) {
        int cnt = 0;
        for(int i = s.size() - 1; ~i ; i--){
            cnt += isdigit(s[i]);
            if( !isdigit(s[i]) and cnt > 0 ) 
                s[i] = '-', cnt --;
        }
        string res;
        for(int i = 0; i < s.size(); i++){
            if( !isdigit(s[i]) and s[i] != '-' )
                res.push_back(s[i]);
        }
        return res;
    }
};