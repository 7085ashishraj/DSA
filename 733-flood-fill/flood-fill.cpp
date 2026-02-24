class Solution {
public:
    void dfs(vector<vector<int>>& image, int i, int j, int orig_color, int modi_color){
        //base case
        if(i<0 || j<0 || i>=image.size() || j>=image[0].size() || image[i][j]!= orig_color){
            return;
        }
        //work
        image[i][j] = modi_color;
        //recursive call

        dfs(image, i-1,j,orig_color, modi_color);//top
        dfs(image, i,j+1,orig_color, modi_color);//bottom
        dfs(image, i+1,j,orig_color, modi_color);//left
        dfs(image, i,j-1,orig_color, modi_color);//right
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int orig_color = image[sr][sc];
        if(orig_color != color)
            dfs(image, sr, sc, orig_color, color);
        return image;
    }
};