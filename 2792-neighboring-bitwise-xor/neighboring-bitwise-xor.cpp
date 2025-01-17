class Solution {
public:
    bool doesValidArrayExist(vector<int>& derived) {
        int n = int(derived.size());

        vector<int> original_0(n), original_1(n);
        original_0[ 0 ] = 0;
        original_1[ 0 ] = 1;


        auto tryIt = [&](vector<int> original){
            for (int i = 0; i < n - 1; ++i) {
                original[i + 1] = derived[i] ^ original[i];
            }

            return original;
        };

        auto canBeOriginal = [&](const vector< int > &original){
            for (int i = 0; i < n; ++i) {
                int curr = original[i] ^ ( i == n - 1 ? original[0] : original[i + 1] );
                if( derived[i] != curr )
                    return false;
            }

            return true;
        };

        return (canBeOriginal(tryIt(original_0) ) || canBeOriginal(tryIt(original_1)));
    }
};
