class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        vector<int> mx_freq(26, 0), freq(26, 0);

        for (auto& word : words2) {
            fill(freq.begin(), freq.end(), 0);
            for (auto& ch : word) {
                freq[ch - 'a']++;
                mx_freq[ch - 'a'] = max(mx_freq[ch - 'a'], freq[ch - 'a']);
            }
        }

        vector<string> res;
        res.reserve(words1.size());

        for (auto& word : words1) {
            fill(freq.begin(), freq.end(), 0);
            for (auto& ch : word) {
                freq[ch - 'a']++;
            }
            bool valid = true;
            for (int i = 0; i < 26; ++i) {
                if (mx_freq[i] > freq[i]) {
                    valid = false;
                    break;
                }
            }
            if (valid) {
                res.push_back(word);
            }
        }

        return res;
    }
};