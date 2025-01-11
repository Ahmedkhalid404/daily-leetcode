class Solution {
public:
    bool canConstruct(string &s, int cnt) {
        if( s.size() < cnt ){
            return false;
        }

        array<int, int('z' - 'a' + 1)> freq{};

        for(auto &ch : s){
            freq[ch - 'a']++;
        }

        int odd = 0;
        for(auto it : freq){
            odd += (it & 1);
            if( odd > cnt ) return false;
        }

        return true;
    }
};