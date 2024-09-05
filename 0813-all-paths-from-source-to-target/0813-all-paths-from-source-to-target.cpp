class Solution {
public:
    void dfs(vector<vector<int>>& graph,int u,int tr, vector<vector<int>>&res,vector<int>&tmp)
    {
        tmp.push_back(u);
        if(u==tr)
        {
            res.push_back(tmp);
        }
        else
        {
            for(auto &v:graph[u])
            {
                dfs(graph,v,tr,res,tmp);
            }
        }
        tmp.pop_back();//Backtrack: remove u from path before returning
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int s=0;
        int target=graph.size()-1;
        vector<vector<int>>res;
        vector<int>tmp;
        dfs(graph,s,target,res,tmp);
        return res;
    }
};