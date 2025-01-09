class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {
        int cnt = 0;
        for(auto &it : words)
            cnt += it.find(pref) == 0;
        return cnt;
    }
};