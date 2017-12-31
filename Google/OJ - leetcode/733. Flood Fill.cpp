/* dfs */
class Solution {
public:
    void dfs(vector<vector<int> > &v, int m, int n, int row, int col, int color, int ncolor) {
        if (row >= m || row < 0 || col >= n || col < 0 || v[row][col] != color) return;
        v[row][col] = ncolor;
        dfs(v, m, n, row + 1, col, color, ncolor);
        dfs(v, m, n, row - 1, col, color, ncolor);
        dfs(v, m, n, row, col + 1, color, ncolor);
        dfs(v, m, n, row, col - 1, color, ncolor);
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int m = image.size();
        int n = image[0].size();
        int color = image[sr][sc];
        if (color == newColor) return image;
        dfs(image, m, n, sr, sc, color, newColor);
        return image;
    }
};
