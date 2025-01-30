class Solution {
private:
    class DSU{
    private:
        int size{};
        vector< int > parent,sz;

        int getRoot(int x){
            return parent[ x ] = ( parent[ x ] == x ? x : getRoot( parent[ x ] ) );
        }

        bool isUnion(int a,int b){
            return getRoot( a ) == getRoot( b );
        }

        void Union(int a,int b){
            int rootA = getRoot( a );
            int rootB = getRoot( b );

            if( rootA == rootB )
                return;


            parent[ rootB ] = rootA;

            sz[ rootA ] += sz[ rootB ];
        }

        void init(int n){
            size = n;
            parent.resize( n );
            sz.resize( n );

            for (int i = 1; i < n; ++i) {
                parent[ i ]  = i;
                sz[ i ]      = 1;
            }

        }
    public:
        explicit DSU(int n){
            init( n + 5 );
        }

        void connect(int a,int b){
            Union( a , b );
        }

        bool isConnected(int a,int b){
            return isUnion(a,b);
        }
    };
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {

        DSU dsu(1000 + 5);
        int n = int(edges.size());

        for (int i = 0; i < n; ++i) {
            auto [a, b] = make_pair(edges[i][0], edges[i][1]);
            if( dsu.isConnected(a, b) ){
                return vector{a,b};
            }
            dsu.connect(a, b);
        }

        return vector<int>{};
    }
};
