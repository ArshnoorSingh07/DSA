class Solution {
public:
    void dfs(int row, int col, vector<vector<int>>&image, int oldColor, int color)
    {
        int n = image.size();
        int m = image[0].size();

        if(row < 0 || row >=n || col < 0 || col >=m || image[row][col] != oldColor){
            return;
        }

        image[row][col] = color;

        dfs(row-1,col,image, oldColor, color);
        dfs(row,col+1,image, oldColor, color);
        dfs(row+1,col,image, oldColor, color);
        dfs(row,col-1,image, oldColor, color);
        
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int oldColor = image[sr][sc];
        if(oldColor == color) return image;

        dfs(sr,sc,image,oldColor,color);
        return image;

    }
};