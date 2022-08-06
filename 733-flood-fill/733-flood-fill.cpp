class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int prevColor = image[sr][sc];
        if(prevColor != color){
            dfs(image,sr,sc,prevColor,color);
        }
        return image;
    }
    void dfs(vector<vector<int>>& image,int sr,int sc,int prevColor,int newColor){
        if(sr<0||sr>=image.size()||sc<0||sc>=image[0].size()||image[sr][sc]!=prevColor){
            return;
        }
        image[sr][sc] = newColor;
        dfs(image,sr,sc-1,prevColor,newColor);
        dfs(image,sr,sc+1,prevColor,newColor);
        dfs(image,sr-1,sc,prevColor,newColor);
        dfs(image,sr+1,sc,prevColor,newColor);
    }
};