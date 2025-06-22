class Solution {
public:
    vector<string> divideString(string& s, int k, char fill) {
        string curr;
        vector<string> res;
        for (int i = 0; i < s.size(); i++) {
            curr.push_back(s[i]);
            if (curr.size() == k) {
                res.push_back(curr);
                curr.clear();
            }
        }
        if (!curr.empty()) {
            while (curr.size() != k)
                curr.push_back(fill);
            res.push_back(curr);
        }
        return res;
    }
};