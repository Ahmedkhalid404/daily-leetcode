class Solution {
public:
    vector<int> pivotArray(vector<int> nums, int pivot) {
        stable_sort(nums.begin(), nums.end(),[&pivot](auto &a, auto &b) {

            if ( a != pivot and b != pivot ) {
                if ( (a < pivot) and (b < pivot) )
                    return false;
                if ( (a > pivot) and (b > pivot) )
                    return false;

                if ( (a < pivot) and (b > pivot) )
                    return true;

                return false;
            }
            else {
                if ( (a == pivot) and (b > pivot) )
                    return true;
                if ( (a == pivot) and (b < pivot) )
                    return false;

                if ( b == pivot ) {
                    if ( a < pivot )
                        return true;
                    if ( a > pivot )
                        return false;
                }
            }
            return false;
        });
        return nums;
    }
};