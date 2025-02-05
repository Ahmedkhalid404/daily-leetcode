class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        int cnt = 0;
        int val = 0;
        int _xor = 0;
        for(int i = 0; i < s1.size(); i++){
            cnt += (s1[i] != s2[i]);
            val = val + s1[i];
            val = val - s2[i];
            _xor ^= (s1[i] - 'a');
            _xor ^= (s2[i] - 'a');
        }
        return cnt <= 2 and !val and !_xor;
    }
};