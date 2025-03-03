class Solution {
public:
    vector<int> pivotArray(vector<int> nums, int pivot) {
        vector<int> res;
        int cntPivot = 0;
        queue<int> greaterThanPivot;

        for (auto &it : nums) {
            if ( it < pivot ) res.push_back(it);
            else if ( it == pivot ) cntPivot ++;
            else greaterThanPivot.push(it);
        }

        while ( cntPivot --> 0 ) res.push_back(pivot);
        while ( !greaterThanPivot.empty() ) res.push_back(greaterThanPivot.front()), greaterThanPivot.pop();

        return res;
    }
};
