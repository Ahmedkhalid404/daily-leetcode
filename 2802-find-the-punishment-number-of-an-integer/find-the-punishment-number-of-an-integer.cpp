class Solution {
public:
    int punishmentNumber(int n) {
        int ans = 0;
        function<bool(int,string,int,int,int)> getSum = [&](int idx, string num, int prev, int sum, int target) {
            if(idx >= num.size()){
                return (prev + sum) == target;
            }
            
            bool flag = getSum(idx + 1, num, prev * 10 + int(num[idx] - '0'), sum, target);
            flag |= getSum(idx + 1, num, int(num[idx] - '0'), prev + sum, target);
            
            return flag;
        };
        for (int i = 1; i <= n; i++) {
            string num = to_string(i * i);
            if( getSum(1, num, num[0] - '0', 0, i ) ) ans += i * i;
        }
        return ans;
    }
};