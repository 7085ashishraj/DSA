class Solution {
public:
    void dfs(int row, int col, vector<vector<int>>&ans,vector<vector<int>>& image, int newColor, int initColor ){
        int n = image.size();
        int m = image[0].size();
        ans[row][col] = newColor;
        //recursive traversal in all 4 directions
        int delRow[] = {-1, 0, 1, 0};
        int delCol[] = {0,1, 0, -1};
        for(int i=0;i<4;i++){
            int nrow = row + delRow[i];
            int ncol = col + delCol[i];

            //checking for valid rows and cols
            if(nrow >=0 && nrow <n && ncol >= 0 && ncol <m
            && image[nrow][ncol] == initColor && ans[nrow][ncol] != newColor){
                dfs(nrow, ncol, ans, image, newColor, initColor);
            }
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int initColor = image[sr][sc];
        vector<vector<int>> ans = image;
        dfs(sr,sc, ans,image,color, initColor);  
        return ans; 
    }
};