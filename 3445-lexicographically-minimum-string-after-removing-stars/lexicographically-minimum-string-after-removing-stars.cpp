class Solution {
public:
    string clearStars(string& s) {
        map<char, stack<int>> freq;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '*') {
                s[freq.begin()->second.top()] = '-';
                freq.begin()->second.pop();
                if (freq.begin()->second.empty()) {
                    freq.erase(freq.begin());
                }
            } else {
                freq[s[i]].push(i);
            }
        }
        string result;
        for (const char& i : s) {
            if (i == '*' or i == '-')
                continue;
            result.push_back(i);
        }
        return result;
    }
};