class Solution {
public:
    vector<int> pivotArray(vector<int> nums, int pivot) {
        stable_sort(nums.begin(), nums.end(),[&pivot](auto &a, auto &b) {
            if ( a == b )
                return false;

            if ( (a < pivot and b < pivot) or (a > pivot and b > pivot) )
                return false;

            return a < b;
        });
        return nums;
    }
};
