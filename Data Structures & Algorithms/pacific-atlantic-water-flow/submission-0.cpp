class Solution {
public:
    int m, n;

    void dfs(int r, int c, vector<vector<int>>& heights,
             vector<vector<bool>>& vis) {
        vis[r][c] = true;

        int dr[] = {1, -1, 0, 0};
        int dc[] = {0, 0, 1, -1};

        for (int k = 0; k < 4; k++) {
            int nr = r + dr[k];
            int nc = c + dc[k];

            if (nr < 0 || nr >= m || nc < 0 || nc >= n)
                continue;

            if (vis[nr][nc])
                continue;

            // Move uphill (reverse flow)
            if (heights[nr][nc] < heights[r][c])
                continue;

            dfs(nr, nc, heights, vis);
        }
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        m = heights.size();
        n = heights[0].size();

        vector<vector<bool>> pac(m, vector<bool>(n, false));
        vector<vector<bool>> atl(m, vector<bool>(n, false));

        // Pacific: top row + left column
        for (int i = 0; i < m; i++)
            dfs(i, 0, heights, pac);

        for (int j = 0; j < n; j++)
            dfs(0, j, heights, pac);

        // Atlantic: bottom row + right column
        for (int i = 0; i < m; i++)
            dfs(i, n - 1, heights, atl);

        for (int j = 0; j < n; j++)
            dfs(m - 1, j, heights, atl);

        vector<vector<int>> ans;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (pac[i][j] && atl[i][j]) {
                    ans.push_back({i, j});
                }
            }
        }

        return ans;
    }
};