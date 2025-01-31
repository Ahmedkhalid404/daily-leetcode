class Solution {
private:
    vector<int> dx = { 1 , -1 , 0 , 0 },
            dy = { 0 , 0 , 1 , -1 };
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

            if( sz[rootA] < sz[rootB] )
                swap(rootA, rootB);

            parent[ rootB ] = rootA;

            sz[ rootA ] += sz[ rootB ];
        }

        void init(int n){
            size = n;
            parent.resize( n );
            sz.resize( n );

            for (int i = 0; i < n; ++i) {
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

        int getComponent(int a){
            return getRoot(a);
        }

        int getSize(int a){
            return sz[ getRoot(a) ];
        }
    };


public:
    int largestIsland(vector<vector<int>>& grid) {
        int n = int(grid.size());

        auto getIdx = [&](int i, int j){
            return n * i + j;
        };

        DSU dsu(n * n + 5);

        vector vis(n, vector(n, false));

        auto valid = [&](int i,int j,int k)-> optional<pair<int, int>>{
            int new_i = i + dy[ k ];
            int new_j = j + dx[ k ];

            if(
                    ( ( new_i < n ) && ( new_i > -1) )  &&
                    ( ( new_j < n ) && ( new_j > -1 ) ) &&
                    ( grid[new_i][new_j] == 1 )         &&
                    ( !vis[new_i][new_j] )
                    ){
                return make_pair(new_i, new_j);
            }

            return nullopt;
        };


        function<int(int, int, int, int)> dfs = [&](int st_i, int st_j, int i, int j) -> int{
            int idx1 = getIdx(st_i, st_j);
            int idx2 = getIdx(i, j);
            dsu.connect(idx1, idx2);

            vis[i][j] = true;

            int cnt = 1;
            for (int k = 0; k < dx.size(); ++k) {

                if(auto new_idx = valid(i, j, k)){
                    cnt += dfs(st_i, st_j, new_idx->first, new_idx->second);
                }

            }

            return cnt;
        };

        int mx = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {

                if( (!vis[i][j]) and (grid[i][j] == 1) ){
                    mx = max(mx, dfs(i, j, i, j));
                }

            }
        }

        auto validBorder = [&](int i,int j,int k)-> optional<pair<int, int>>{
            int new_i = i + dy[ k ];
            int new_j = j + dx[ k ];

            if(
                    ( ( new_i < n ) && ( new_i > -1) )  &&
                    ( ( new_j < n ) && ( new_j > -1 ) ) &&
                    ( grid[new_i][new_j] == 1 )
                    ){
                return make_pair(new_i, new_j);
            }

            return nullopt;
        };

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if( !grid[i][j] ){ // If we make this cell 1, what is the maximum number of 1's we can get ?
                    
                    set< int > components;
                    for (int k = 0; k < dx.size(); ++k) {
                        if(auto idx = validBorder(i,j,k) ){
                            components.insert( dsu.getComponent(getIdx(idx->first, idx->second)) );
                        }
                    }
                    int current1s = 1; // the current bit already flipped
                    for(auto it : components){
                        current1s += dsu.getSize(it);
                    }
                    mx = max(mx, current1s);
                }

            }
        }

        return mx;
    }
};