class Solution {
    public:
        string removeOccurrences(string s, string part) {
            int find = s.find(part);
            while( find != string::npos ){
                s.erase(find, part.size());
                find = s.find(part);
            }
            return s;
        }
    };
