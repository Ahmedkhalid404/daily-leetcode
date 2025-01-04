class Solution {
private:
    map<char, vector<int>> make_pref(string &s){
        int size = int(s.size());
        // freq & pref to know number of freq of any letter in range
        map<char, vector<int>> pref_on_freq;
        for (char i = 'a'; i <= 'z'; ++i) {
            pref_on_freq[ i ].resize(size);
        }
        // freq
        for (int i = 0; i < size; ++i) {
            pref_on_freq[s[i]][i] = 1;
        }
        // pref
        for (char i = 'a'; i <= 'z'; ++i) {

            for (int j = 1; j < size; ++j) {
                pref_on_freq[i][j] += pref_on_freq[i][j - 1];
            }

        }
        return pref_on_freq;
    }

    map< char, pair<int, int> > get_first_and_last_appear(string &s){
        int size = int(s.size());
        map<char, pair<int, int>> first_and_last_appear;
        for (char i = 'a'; i <= 'z'; ++i) {
            first_and_last_appear[i] = {-1,-1};
        }

        for (int i = 0; i < size; ++i) {
            auto &[first, last] = first_and_last_appear[s[i]];
            if( first == -1 )
                first = i, last = i;
            else
                last = i;
        }
        return first_and_last_appear;
    }
public:
    int countPalindromicSubsequence(string s) {
        int size = int(s.size());
        map<char, vector<int>> pref_to_each_letter = make_pref(s);
        map< char, pair<int, int> > first_and_last_appear = get_first_and_last_appear(s);
        auto freq_in_range = [&](char ch,int l,int r){
            return pref_to_each_letter[ch][r] - (l? pref_to_each_letter[ch][l - 1] : 0);
        };
        int ans = 0;
        for(auto &[ch, range] : first_and_last_appear){
            auto &[first, last] = range;
            if( (first == -1) or (last == first) ) continue;

            for (char i = 'a'; i <= 'z'; ++i) {
                ans += freq_in_range(i, first + 1, last - 1) > 0;
            }
            
        }
        
        return ans;
    }
};
