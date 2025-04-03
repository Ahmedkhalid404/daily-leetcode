class Solution {
    template<class T = int,T def = 0>
class SparcTable{
private:
    vector< vector< T > > sp;
    function< T(T,T) > mergeWhenBuild , mergeWhenQuery ;
    vector< vector< T > > sparcTable(vector< T >&nums){
        int size = int(nums.size());
        vector< vector< T > > sparc( __lg( size ) + 1 , vector< T >( size ) );
        sparc[ 0 ] = nums;
        for (int mask = 1; ( 1 << mask ) <= size ; ++mask) {
            int sizeOfCurrentSegment = 1 << mask;
            for (int i = 0; (i + sizeOfCurrentSegment ) <= size; ++i) {
                T leftSegmentWithHalfSize = sparc[ mask - 1 ][ i ];
                T rightSegmentWithHalfSize = sparc[ mask - 1 ][ i + ( sizeOfCurrentSegment >> 1 ) ];
                sparc[ mask ][ i ] = mergeWhenBuild( leftSegmentWithHalfSize , rightSegmentWithHalfSize );
            }
        }
        return sparc;
    }
    T _get(int l,int r){
        function<bool(int,int)> getBit = [](int num,int idx){
            return ( ( num >> idx ) & 1 );
        };
        T res = def;
        int len = r - l + 1;
        for (int mask = 0; l <= r ; ++mask) {
            if( getBit( len , mask ) ){
                res = mergeWhenQuery( res , sp[ mask ][ l ] );
                l = l + (1 << mask);
            }
        }
        return res;
    }
    T _getO1(int l,int r){
        int lgLen = __lg( r - l + 1 );
        return mergeWhenQuery( sp[ lgLen ][ l ] , sp[ lgLen ][ r - ( ( 1 << lgLen ) - 1 ) ] );
    }
public:
    explicit SparcTable(
                            vector< T > &nums ,
                            function< T(T,T) > mergeWhenBuild = [](T x,T y){return x + y;} ,
                            function< T(T,T) > mergeWhenQuery = [](T x,T y){return x + y;}
                        ){
        this->mergeWhenBuild = mergeWhenBuild;
        this->mergeWhenQuery = mergeWhenQuery;
        sp = sparcTable(nums);
    }
    T get(int l,int r){
        return _get(l,r);
    }
    T getO1(int l,int r){
        return _getO1(l,r);
    }
};

public:
    long long maximumTripletValue(vector<int>& nums) {
    SparcTable<int, INT_MIN> sp(nums, [](auto a, auto b) {return max(a,b);}, [](auto a,auto b) {return max(a,b);});

    int const n = static_cast<int>(nums.size());
    int64_t ans = 0;
    for (int j = 1; j < n - 1; j++) {
        ans = max<int64_t>(ans, (sp.getO1(0, j - 1) * 1LL - nums[j]) * sp.getO1(j + 1, n - 1) );
    }

    return ans;

}
};