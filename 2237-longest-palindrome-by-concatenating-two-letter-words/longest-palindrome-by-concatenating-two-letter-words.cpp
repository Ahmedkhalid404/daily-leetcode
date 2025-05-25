class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        unordered_map<string, int> count;
        int length = 0;
        bool usedCenter = false;

        for (const string& word : words) {
            count[word]++;
        }

        for (auto& [word, freq] : count) {
            string rev = string{word.rbegin(), word.rend()};

            if (word == rev) {
                int pairs = freq / 2;
                length += pairs * 4;
                count[word] -= pairs * 2;

                if (!usedCenter && count[word] > 0) {
                    length += 2;
                    usedCenter = true;
                }
            } else if (word < rev && count.find(rev) != count.end()) {
                int pairs = min(count[word], count[rev]);
                length += pairs * 4;
                count[word] -= pairs;
                count[rev] -= pairs;
            }
        }

        return length;
    }
};