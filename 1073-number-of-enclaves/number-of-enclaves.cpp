class Solution {
public:
    void dfs(int row,int col, vector<vector<int>>&visited, vector<vector<int>>&grid)
    {
        int n = grid.size();
        int m = grid[0].size();

        if(row >= n || row <0 || col >=m || col <0 ){
            return ;
        }

        if(grid[row][col] == 0 || visited[row][col]){
            return;
        }

        visited[row][col] = 1;

        dfs(row-1,col,visited,grid); //up
        dfs(row,col+1,visited,grid); //right
        dfs(row+1,col,visited,grid); //down
        dfs(row,col-1,visited,grid); // left
        
    }
    int numEnclaves(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>>visited(n,vector<int>(m,0));

        for(int col = 0; col<m;col++)
        {
            dfs(0, col,visited,grid);
            dfs(n-1, col,visited,grid);
        }

        for(int row= 0; row<n; row++)
        {
            dfs(row,0,visited,grid);
            dfs(row,m-1,visited,grid);
        }
        
        int count = 0;
        for(int row = 0; row<n; row++){
            for(int col = 0; col <m; col++){
                if(grid[row][col] == 1 && !visited[row][col]){
                    count++;
                }
            }
        }

        return count;

    }
};