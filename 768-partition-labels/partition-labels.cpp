class Solution {
public:
    vector<int> partitionLabels(string_view s) {
        array<int, 'z' - 'a' + 1> freq = {};

        for (auto &c : s) freq[c - 'a'] ++;

        const int n = static_cast<int>(s.size());
        
        vector<int> ans;ans.reserve(n);

        int curr = 0;
        map<int, int> letters ;
        
        for (auto &c : s) {
            curr ++;
            freq[c - 'a'] --;
            letters[c - 'a'] = freq[c - 'a'];

            if ( !letters[c - 'a'] )
                letters.erase(c - 'a');
            
            
            if ( letters.empty() ) {
                ans.push_back(curr);
                curr = 0;
            }
        }

        if (curr) {
            ans.push_back(curr);
        }

        return ans;
        
    }
};