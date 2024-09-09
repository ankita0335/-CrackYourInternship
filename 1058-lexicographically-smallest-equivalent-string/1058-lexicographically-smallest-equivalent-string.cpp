class Solution {
public:
    char dfs(unordered_map<char, vector<char>>&adj, char &currch, vector<int>&vis)
    {
        vis[currch - 'a'] = 1;
        char minimumchar = currch;
        for(auto & i: adj[currch])
        {
            if(vis[i-'a']==0)
            {
                minimumchar = min( minimumchar, dfs(adj, i , vis));
            }
        }
        return minimumchar;
    }
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        int n= s1.length();
        int m= baseStr.length();
        unordered_map<char, vector<char>>adj;
        for(int i=0;i<n;i++)
        {
            char u= s1[i];
            char v= s2[i];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        string ans;
        for(int i=0;i < m;i++)
        {
            vector<int>vis(26,0);
            char currch = baseStr[i];
            char mini = dfs(adj, currch, vis);
            ans.push_back(mini);
        }
        return ans;
    }
};