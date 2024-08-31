class Solution {
public:
    void dfs(vector<vector<int>>& rooms, int source, vector<bool>&vis)
    {
        vis[source]=true;
        for(int &nd: rooms[source])
        {
            if(!vis[nd])
                dfs(rooms, nd, vis);
        }
    }
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n=rooms.size();
        vector<bool>vis(n,false);
        dfs(rooms, 0, vis);
        for(bool i : vis)
        {
            if(i== false)   return false;
        }
        return true;
    }
};