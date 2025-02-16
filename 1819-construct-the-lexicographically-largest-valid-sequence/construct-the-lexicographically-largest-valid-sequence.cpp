class Solution {
public:
    vector<int> constructDistancedSequence(int n) {
        vector<int> res(n * 2 - 1, -1);
        vector<bool> used(n + 1, false);
        
        function<bool(int)> backtrack = [&](int idx) {
            if (idx == res.size()) return true;
            
            if (res[idx] != -1) return backtrack(idx + 1);
            
            for (int num = n; num >= 1; num--) {
                if (used[num]) continue;

                if (num == 1) { 
                    res[idx] = 1;
                    used[1] = true;
                    if (backtrack(idx + 1)) return true;
                    res[idx] = -1;
                    used[1] = false;
                } else {
                    int secondIdx = idx + num;
                    if (secondIdx < res.size() && res[secondIdx] == -1) {
                        res[idx] = res[secondIdx] = num;
                        used[num] = true;

                        if (backtrack(idx + 1)) return true;

                        res[idx] = res[secondIdx] = -1;
                        used[num] = false;
                    }
                }
            }
            return false;
        };

        backtrack(0);
        return res;
    }
};    
