class Solution {
public:
    void dfs(int u, int prev,unordered_map<int,vector<int>>&adj, vector<int>&ans)
    {
        ans.push_back(u);
        for(auto &v: adj[u])
        {
            if( v!=prev)
                dfs(v,u,adj, ans);
        }
    }
    vector<int> restoreArray(vector<vector<int>>& adjacentPairs) 
    {
        vector<int> ans;
        unordered_map<int,vector<int>>adj;
        for(vector<int>&vc: adjacentPairs)
        {
            int u= vc[0];
            int v= vc[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        int strtpnt=-1;
        for(auto i: adj)
        {
            if(i.second.size()==1)
            {
                strtpnt=i.first;
                break;
            }
        }
        dfs(strtpnt, INT_MIN, adj, ans);
        return ans;
    }
};

//sbse phle maine ek adj list bnayi map k through, then strtpnt nikala , uske baad maine us strtpnt se dfs traversal kiya ...dfs se saare adjecent element aagye :)