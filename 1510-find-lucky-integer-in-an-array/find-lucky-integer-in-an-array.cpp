class Solution {
public:
    int findLucky(vector<int>& arr) {
        int constexpr maxRkm = 500 + 5;
        int freq[ maxRkm ] = {};

        for(int i = 0; i < arr.size() ; i++){
            freq[ arr[i] ] ++;
        }
        for(int i = 500; i > 0 ; i --){
            if( freq[i] == i ){
                return i;
            }
        }
        return -1;
    }
};