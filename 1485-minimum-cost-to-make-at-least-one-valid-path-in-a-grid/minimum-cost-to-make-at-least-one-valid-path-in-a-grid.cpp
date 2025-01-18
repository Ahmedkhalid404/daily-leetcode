class Solution {
private:
    vector<int> dx =  { 1 , -1 , 0 , 0  },
                dy =  { 0 ,  0 , 1 , -1 },
                dir = { 1 ,  2 , 3 ,  4 };




    bool isValid(int i,int j,int k, int n, int m){
        int new_i = i + dy[ k ];
        int new_j = j + dx[ k ];

        return (
                ( ( new_i < n ) && ( new_i > -1) ) &&
                ( ( new_j < m ) && ( new_j > -1 ) )
                );
    }

public:
    int minCost(vector<vector<int>>& grid) {

        int n = int(grid.size());
        int m = int(grid[0].size());

        vector vis(n, vector<bool>(m, false));

        function<int(int, int)> dijkstra = [&] (int st_y, int st_x) -> int {

            vector< vector< int > > dist(n, vector< int >(m , -1)); // -1 -> inf

            //                   dis, node
            priority_queue<pair< int, pair<int, int> >, vector<pair< int, pair<int, int> >>, greater<>> pq;

            pq.push({0, {st_y,st_x}});
            dist[st_y][st_x] = 0;

            while( !pq.empty() ){

                auto [mn_dist, node] = pq.top();
                auto [y, x] = node;

                pq.pop();

                if( (y == (n - 1)) and (x == (m - 1)) )
                    return mn_dist;

                if( mn_dist > dist[y][x] ) continue;

                for (int k = 0; k < 4; ++k) {

                    if( isValid(y, x, k, n, m) ){
                        int new_y = y + dy[ k ];
                        int new_x = x + dx[ k ];

                        int new_dist = mn_dist + (grid[y][x] != dir[k]);

                        if( (dist[new_y][new_x] == -1) or (new_dist < dist[new_y][new_x]) ){
                            dist[new_y][new_x] = new_dist;
                            pq.push({new_dist, {new_y, new_x}});
                        }

                    }

                }

            }
            
            assert(false); // we should return before `pq` became empty
            return -1;
        };
        
        return dijkstra(0,0);
    }
};