class Solution {
private:
    vector<int> dx = { 1 , -1 , 0 , 0 },
            dy = { 0 , 0 , 1 , -1 };
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        int n = int(isWater.size());
        int m = int(isWater.front().size());

        vector res(n, vector(m, -1));// -1 -> empty ceil
        
        

        auto bfs = [&](){
            queue< pair< int, int > > q;
            vector vis(n, vector(m, false));
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < m; ++j) {
                    if( isWater[i][j] )
                        q.push({i,j}), vis[i][j] = true;
                }
            }

            auto isValid = [&](int i,int j,int k){
                int new_i = i + dy[ k ];
                int new_j = j + dx[ k ];

                return (
                        ( ( new_i < n ) && ( new_i > -1) ) &&
                        ( ( new_j < m ) && ( new_j > -1 ) ) &&
                        ( !vis[ new_i ][ new_j ] ) &&
                        ( res[ new_i ][ new_j ] == -1 )
                );
            };
            
            int lvl = 0;
            while( !q.empty() ){

                int size = int(q.size());
                while( size --> 0 ){

                    auto [i, j] = q.front();
                    q.pop();

                    res[i][j] = lvl;

                    for (int k = 0; k < 4; ++k) {
                        
                        if(isValid(i,j,k)){
                            int new_i = i + dy[ k ];
                            int new_j = j + dx[ k ];
                            
                            q.push({new_i, new_j});
                            vis[new_i][new_j] = true;
                            
                        }
                        
                    }


                }
                lvl ++;
            }

        };

        bfs();
        
        return res;

    }
};
