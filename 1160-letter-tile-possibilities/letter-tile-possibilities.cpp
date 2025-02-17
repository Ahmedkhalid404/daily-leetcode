class Solution {
public:
    int numTilePossibilities(string tiles) {
        unordered_map<char, int> freq;
        
        for(auto it : tiles) freq[it] ++;

        int cnt = 0;
        function<void(int)> rec = [&](int idx){
            if(idx >= tiles.size())
                return;
            
            for(auto &it : freq){
                if( it.second > 0 ){
                    cnt ++;
                    it.second --;
                    rec(idx + 1);
                    it.second ++;
                }
            }
        };
        rec(0);
        return cnt;
    }
};