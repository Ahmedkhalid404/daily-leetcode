class Solution {
public:
    string largestGoodInteger(string num) {
        char ans = char('0' - 1);
        for (int i = 0; i < num.size() - 2; i++) {

            if (set{num[i], num[i + 1], num[i + 2]}.size() == 1) {
                ans = max(ans, num[i]);
            }
        }

        if (ans == char('0' - 1))
            return "";
        return string(3, ans);
    }
};