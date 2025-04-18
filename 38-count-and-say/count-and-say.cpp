class Solution {
public:
    string countAndSay(int n) {
        string curr = "1*";
        n--;
        while (n --> 0) {

            int cnt = 1;
            char prev = curr[0];
            string temp;

            for (int i = 0; i < curr.size(); i++) {
                if (curr[i] == '*') {
                    temp.push_back('*');
                } else if (curr[i] != curr[i + 1]) {
                    temp += to_string(cnt);
                    temp += prev;

                    prev = curr[i + 1];
                    cnt = 1;
                } else { // curr[i] == curr[i + 1]
                    cnt++;
                }
            }

            curr = temp;
        }

        return curr.substr(0, curr.size() - 1);
    }
};