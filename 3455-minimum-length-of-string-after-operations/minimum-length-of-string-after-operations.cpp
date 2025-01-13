class Solution {
public:
    static int minimumLength(string &s) {
        map<char, int> freq;
        for(auto &ch : s){
            freq[ch] ++;
        }

        int res = 0;
        for(auto &[k, v] : freq){
            res += v < 3 ? v : ( v & 1 ? 1 : 2 );
        }
        
        return res;
    }
};