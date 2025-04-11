class Solution {
vector<int> ans = [](){
    vector<int> res;res.reserve(10000);
    int ans = 0;
    for (int i = 0; i <= 10000; i++) {
        string s = to_string(i);
        int n = s.size();
        if (n % 2 == 1) {
            res.push_back(ans);
            continue;
        }
        int sum1 = 0, sum2 = 0;
        for (int j = 0; j < n / 2; j++) {
            sum1 += s[j] - '0';
            sum2 += s[n - j - 1] - '0';
        }
        if (sum1 == sum2) ans++;
        res.push_back(ans);
    }
    
    return res;
}();
public:
    int countSymmetricIntegers(int low, int high) {
        return ans[high] - ans[low - 1];
    }
};