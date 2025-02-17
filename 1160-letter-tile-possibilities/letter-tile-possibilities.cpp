class Solution {
public:
    int numTilePossibilities(string tiles) {
        map<char, int> freq;
        for(auto it : tiles) freq[it] ++;
        string curr = ""s;
        set<string> ans;
        function<void(int)> rec = [&](int idx){
            if(!curr.empty()) ans.insert(curr);
            if(idx >= tiles.size())
                return;
            
            for(auto &it : freq){
                if(it.second > 0){
                    curr.push_back(it.first);
                    it.second --;
                    rec(idx + 1);
                    curr.pop_back();
                    it.second ++;
                }
            }
        };
        rec(0);
        return ans.size();
    }
};