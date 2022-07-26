class Solution {
private:
    void _dfs(vector<vector<int>>& grid, int i, int j, int h, int w) {
        if (i > 0 && grid[i-1][j] != 0 && (grid[i-1][j] == 1 || grid[i-1][j] > grid[i][j] + 1)) {
            grid[i-1][j] = grid[i][j] + 1;
            _dfs(grid, i-1, j, h, w);
        }
        if (i < h - 1 && grid[i+1][j] != 0 && (grid[i+1][j] == 1 || grid[i+1][j] > grid[i][j] + 1)) {
            grid[i+1][j] = grid[i][j] + 1;
            _dfs(grid, i+1, j, h, w);
        }
        if (j > 0 && grid[i][j-1] != 0 && (grid[i][j-1] == 1 || grid[i][j-1] > grid[i][j] + 1)) {
            grid[i][j-1] = grid[i][j] + 1;
            _dfs(grid, i, j-1, h, w);
        }
        if (j < w - 1 && grid[i][j+1] != 0 && (grid[i][j+1] == 1 || grid[i][j+1] > grid[i][j] + 1)) {
            grid[i][j+1] = grid[i][j] + 1;
            _dfs(grid, i, j+1, h, w);
        }
    }
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int h = grid.size();
        int w = grid[0].size();
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                if (grid[i][j] == 2) {
                    _dfs(grid, i, j, h, w);
                }
            }
        }
        int minutes = 0;
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                if (grid[i][j] == 1) {
                    return -1;
                } else if (grid[i][j] >= 2) {
                    minutes = max(minutes, grid[i][j] - 2);
                }
            }
        }
        return minutes;
    }
};