class Solution {
public:
    void dfs(int row, int col, vector<vector<int>>&image, int initialColor, int color)
    {
        int n = image.size();
        int m = image[0].size();

        if(row >= n || row < 0 || col >=m || col<0){
            return ;
        }

        if(image[row][col] != initialColor){
            return;
        }

        image[row][col] = color;

        dfs(row-1,col,image,initialColor, color);
        dfs(row,col+1,image,initialColor, color);
        dfs(row,col-1,image,initialColor, color);
        dfs(row+1,col,image,initialColor, color);

        
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int initialColor = image[sr][sc];
        if(initialColor == color) return image;

        dfs(sr,sc,image,initialColor,color); 

        return image;
    }
};