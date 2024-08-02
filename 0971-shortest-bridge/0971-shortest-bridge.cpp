class Solution {
public:
    int n, m;
    int ax[4] = {-1, 1, 0, 0};
    int ay[4] = {0, 0, -1, 1};
    bool isSafe(int i, int j) 
    {
        return (i >= 0 && i < n && j >= 0 && j < m);
    }
    void dfs(vector<vector<int>>& grid, int i, int j, set<pair<int, int>>& vis) 
    {
        if (!isSafe(i, j) || grid[i][j] == 0 || vis.find({i, j}) != vis.end()) 
        {
            return;
        }
        vis.insert({i, j});
        for (int k = 0; k < 4; k++) 
        {
            int new_i = i + ax[k];
            int new_j = j + ay[k];
            dfs(grid, new_i, new_j, vis);
        }
    }

    int bfs(vector<vector<int>>& grid, set<pair<int, int>>& vis) 
    {
        queue<pair<int, int>> que;
        for (auto &it : vis) 
        {
            que.push(it);
        }
        int level = 0;
        while (!que.empty()) 
        {
            int L = que.size();
            while (L--) 
            {
                pair<int, int> P = que.front();
                que.pop();
                int i = P.first;
                int j = P.second;
                for (int k = 0; k < 4; k++) 
                {
                    int new_i = i + ax[k];
                    int new_j = j + ay[k];
                    if (isSafe(new_i, new_j) && vis.find({new_i, new_j}) == vis.end()) 
                    {
                        if (grid[new_i][new_j] == 1) 
                        { // found another island
                            return level;
                        }
                        vis.insert({new_i, new_j});
                        que.push({new_i, new_j});
                    }
                }
            }
            level++;
        }
        return level;
    }

    int shortestBridge(vector<vector<int>>& grid) 
    {
        set<pair<int, int>> vis;
        n = grid.size();
        m = grid[0].size();
        bool found = false;
        for (int i = 0; i < n; i++) 
        {
            for (int j = 0; j < m; j++) 
            {
                if (grid[i][j] == 1) 
                {
                    dfs(grid, i, j, vis);
                    found = true;
                    break;
                }
            }
            if (found) break;
        }
        return bfs(grid, vis);
    }
};

