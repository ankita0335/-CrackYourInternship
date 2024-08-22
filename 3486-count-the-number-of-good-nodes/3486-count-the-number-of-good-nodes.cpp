class Solution {
public:
    int ans=0;
    int dfs(unordered_map<int, vector<int>>&tree, vector<bool>&vis, int source)
    {
        vis[source]=true;
        int n =-1 , total= 0;
        bool f = true;
        for(auto i: tree[source])
        {
            if(!vis[i])
            {
                int s = dfs(tree,vis,i);
                total +=s;
                if(n==-1)
                    n=s;
                else if(n!=s)
                    f = false;
            }
        }
        if(f)   
            ans++;
        return total+1;
    }
    int countGoodNodes(vector<vector<int>>& edges) {
        unordered_map<int, vector<int>>tree;
        for(auto i: edges)
        {
            tree[i[0]].push_back(i[1]);
            tree[i[1]].push_back(i[0]);
        }
        vector<bool>vis(edges.size()+1, false);
        dfs(tree, vis, 0);
        return ans;
    }
};



