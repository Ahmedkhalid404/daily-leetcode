class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        int n = int(nums.size());

        //         el   idx
        set< pair< int, int > > setNums;
        for (int i = 0; i < n; ++i) {
            setNums.insert({nums[i], i});
        }

        set< pair< int , int > > comp;
        set< int > index;
        
        comp.insert(*setNums.begin());
        index.insert(setNums.begin()->second);

        setNums.erase(setNums.begin());
        for(auto &it : setNums){
            int range = comp.rbegin()->first + limit;
            if( it.first <= range ){ // can be in the same component
                comp.insert(it);
                index.insert(it.second);
            }
            else{ // we can't add new elements to curr component
                for(auto &ij : comp){
                    nums[ *index.begin() ] = ij.first;
                    index.erase(index.begin());
                }
                comp.clear();
                comp.insert(it);
                index.insert(it.second);
            }
        }
        for(auto &ij : comp){
            nums[ *index.begin() ] = ij.first;
            index.erase(index.begin());
        }

        return nums;
    }
};
