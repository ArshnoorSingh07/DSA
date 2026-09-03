class Solution {
public:

    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>>vis(n, vector<int>(m,0));
        queue<pair<pair<int, int>,int>>q;

        for(int row = 0; row<n; row++)
        {
            for(int col = 0; col < m; col++)
            {
                if(grid[row][col] == 2){
                    q.push({{row, col}, 0});
                    vis[row][col] = 2;
                }else{
                    vis[row][col] = 0;
                }
            }
        }

        int delrow[] = {-1, 1, 0, 0};
        int delcol[] = {0, 0, +1, -1};
        int tm = 0;
        while(!q.empty())
        {
            int r = q.front().first.first;
            int c = q.front().first.second;
            int t = q.front().second;
            q.pop();
            
            tm = max(tm, t);
            for(int k = 0; k<4; k++){
                int nrow = r + delrow[k];
                int ncol = c + delcol[k];
                if(nrow >=0 && nrow < n && ncol >= 0 && ncol < m
                        && vis[nrow][ncol] !=2 && grid[nrow][ncol] == 1)
                {
                    q.push({{nrow, ncol}, t+1});
                    vis[nrow][ncol] = 2;
                }
            }
        }

        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++)
            {
                if(grid[i][j] == 1 && vis[i][j] != 2){
                    return -1;
                }
            }
        }

        return tm;



    }
};