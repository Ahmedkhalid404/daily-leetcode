class Solution {
private:
    vector<vector<int>> make_pref(string &s) {
        int size = int(s.size());
        // freq & pref to know number of freq of any letter in range
        vector<vector<int>> pref_on_freq(26, vector<int>(size, 0));

        // freq
        for (int i = 0; i < size; ++i) {
            pref_on_freq[s[i] - 'a'][i] = 1;
        }

        // pref
        for (int i = 0; i < 26; ++i) {
            for (int j = 1; j < size; ++j) {
                pref_on_freq[i][j] += pref_on_freq[i][j - 1];
            }
        }
        return pref_on_freq;
    }

    vector<pair<int, int>> get_first_and_last_appear(string &s) {
        int size = int(s.size());
        vector<pair<int, int>> first_and_last_appear(26, {-1, -1});

        for (int i = 0; i < size; ++i) {
            auto &[first, last] = first_and_last_appear[s[i] - 'a'];
            if (first == -1)
                first = i, last = i;
            else
                last = i;
        }
        return first_and_last_appear;
    }

public:
    int countPalindromicSubsequence(string s) {
        int size = int(s.size());
        vector<vector<int>> pref_to_each_letter = make_pref(s);
        vector<pair<int, int>> first_and_last_appear = get_first_and_last_appear(s);

        auto freq_in_range = [&](int ch, int l, int r) {
            return pref_to_each_letter[ch][r] - (l ? pref_to_each_letter[ch][l - 1] : 0);
        };

        int ans = 0;
        for (int ch = 0; ch < 26; ++ch) {
            auto &[first, last] = first_and_last_appear[ch];
            if ((first == -1) || (last == first)) continue;

            for (int i = 0; i < 26; ++i) {
                ans += freq_in_range(i, first + 1, last - 1) > 0;
            }
        }

        return ans;
    }
};
