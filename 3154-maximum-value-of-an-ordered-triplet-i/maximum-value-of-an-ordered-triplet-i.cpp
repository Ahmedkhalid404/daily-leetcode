class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        const int n = static_cast<int>(nums.size());

        int64_t mx = 0;


        for (int i = 0; i < n; i++) {
            multiset<int, greater<>> ms;
            for (int j = i + 1; j < n; j++) {
                ms.insert(nums[j]);
            }

            for (int j = i + 1; j < n; j++) {
                ms.erase(ms.find(nums[j]));
                mx = max<int64_t>(mx, (nums[i] * 1LL - nums[j]) ** ms.begin());
            }
        }

        return mx;
    }

};