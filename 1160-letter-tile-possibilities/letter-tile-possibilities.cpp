class Solution {
public:
    int numTilePossibilities(string tiles) {
        int freq[26];
        fill(freq, freq + 26 , 0);

        for(auto it : tiles) freq[it - 'A'] ++;
        int cnt = 0;
        function<void(int)> rec = [&](int idx){
            if(idx >= tiles.size())
                return;
            
            for(int i = 0; i < 26; i ++){
                if( freq[i] > 0 ){
                    cnt ++;
                    freq[i] --;
                    rec(idx + 1);
                    freq[i] ++;
                }
            }
        };
        rec(0);
        return cnt;
    }
};