class Solution {
private:
template<class T>
class LazySegmentTree{
private:
    struct node{
        node *left{},*right{};
        T val = -1;
        int64_t lazy = 0;
    };
    node *root;
    vector<int> nums;
    int size;

    void Union(node *seg,int l,int r){
        seg->val = seg->val + seg->lazy;
        if( l != r ){
            seg->left->lazy += seg->lazy;
            seg->right->lazy += seg->lazy;
        }
        seg->lazy = 0;
    }

    void marge(node *seg){
        seg->val = max(seg->left->val, seg->right->val);
    }

    T merge(T left, T right) {
        return max(left, right);
    }

    void build(node *seg,int l,int r){
        if( l == r ) {
            seg->val = nums[l - 1];
            return;
        }

        int md =  (l + r) >> 1;
        seg->left = new node;
        seg->right = new node;
        build( seg->left , l , md );
        build( seg->right , md + 1 , r );

        marge(seg);
    }
    void update(node *seg,int l,int r,int _l,int _r,int val){
        Union(seg,l,r);

        if( ( l > _r ) || ( r < _l ) )
            return;

        if( ( l >= _l ) && ( r <= _r ) ){
            seg->lazy += val;
            Union(seg,l,r);
            return;
        }

        int md = (l + r) >> 1;
        update( seg->left , l , md , _l , _r , val );
        update( seg->right , md + 1 , r , _l , _r , val );

        marge(seg);
    }

    int get(node *seg,int l,int r,int _l, int _r){

        Union(seg,l,r);

        if( ( l > _r ) || ( r < _l ) )
            return -1;

        if( ( l >= _l ) && ( r <= _r ) ){
            return seg->val;
        }

        int md = ( l + r ) >> 1;
        int left = get( seg->left , l , md , _l, _r );
        int right = get( seg->right , md + 1 , r , _l, _r );

        marge(seg);

        return merge(left, right);
    }
public:
    explicit LazySegmentTree(const vector<T> &nums){
        this->nums = nums;
        this->size = nums.size();
        this->root = new node;
        build( this->root , 1 , this->size );
    }
    void plusRange(const int l,const int r,const int val){
        update( this->root , 1 , size , l , r, val );
    }
    int get(const int l, const int r){
        return get( this->root , 1 , size , l, r );
    }
};

public:
    int minZeroArray(const vector<int>& nums,const vector<vector<int>>& queries) {
        LazySegmentTree seg(nums);

        const int q = static_cast<int>(queries.size());
        const int n = static_cast<int>(nums.size());

        if( seg.get(1, n) <= 0 ){
            return 0;
        }

        for (int i = 0; i < q; i++) {

            const int l   = queries[i][0];
            const int r   = queries[i][1];
            const int val = queries[i][2];

            seg.plusRange(l + 1, r + 1, -val);

            if ( seg.get(1, n) <= 0 )
                return i + 1;
        }

        return -1;
    }
};