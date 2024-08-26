class Solution {
public:
    void dfs(vector<vector<int>>& stones,int idx, vector<bool>&vis)
    {
        vis[idx]=true;
        for(int i=0;i<stones.size();i++)
        {
            int r=stones[idx][0];
            int c=stones[idx][1];
            if(!vis[i] && (stones[i][0]==r || stones[i][1]==c))
            {
                dfs(stones,i,vis);
            }
        }
    }
    int removeStones(vector<vector<int>>& stones) {
        int n=stones.size();
        int grp=0;
        vector<bool>vis(n,false);
        for(int i=0;i<n;i++)
        {
            if(vis[i]==true)
            {
                continue;
            }
            dfs(stones,i,vis);
            grp++;
        }
        return n-grp;       
    }
};