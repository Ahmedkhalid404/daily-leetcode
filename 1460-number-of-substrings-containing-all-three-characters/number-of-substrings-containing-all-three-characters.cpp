class Solution {
public:
    int numberOfSubstrings(const string_view s) {
        int n = static_cast<int>(s.size());
        vector<deque<int>> idx(3);


        for (int i = 0; i < n; i++) {
            idx[s[i] - 'a'].push_back(i);
        }
        int res = 0;


        set letters = {'a', 'b', 'c'};
        for (int i = 0; i < n; i++) {

            idx[ s[i] - 'a' ].pop_front();
            letters.erase(s[i]);

            int mxIdx = -1;
            for (auto ch : letters) {
                if ( idx[ch - 'a'].empty() ) goto finish;

                mxIdx = max(mxIdx, idx[ch - 'a'][0]);
            }

            letters.insert(s[i]);
            res += n - mxIdx;
        }

        finish:;

        return res;
    }
};