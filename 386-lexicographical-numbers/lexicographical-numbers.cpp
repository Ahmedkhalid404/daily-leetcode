class Solution {
public:
    vector<int> lexicalOrder(int n) {
        vector<int> nums(n);
        iota(nums.begin(), nums.end(), 1);
        ranges::sort(nums, [](auto a, auto b){
               return to_string(a) < to_string(b); 
        });

        return nums;
    }
};