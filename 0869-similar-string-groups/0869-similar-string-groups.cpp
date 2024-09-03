class Solution {
public:
    void dfs(int source,vector<bool>&vis, unordered_map<int, vector<int>>&mp )
    {
        vis[source]=true;
        for(auto i: mp[source])
        {
            if(!vis[i])
            {
                dfs(i,vis, mp);
            }
        }
    }
    int numSimilarGroups(vector<string>& strs) 
    {
        unordered_map<int, vector<int>>mp;
        int n=strs.size();
        int grp=0;
        for(int i=0;i<n;i++)   
        {
            string s1= strs[i];
            for(int j=i+1;j<n;j++)
            {
                string s2= strs[j];
                int cnt=0;
                for(int k=0;k<s1.length();k++)
                {
                    if(s1[k]!=s2[k])
                    {
                        cnt++;
                    }
                } 
                if(cnt==0 || cnt ==2)
                {
                    mp[i].push_back(j);
                    mp[j].push_back(i);
                }           
            }
        }     
        vector<bool>vis(n,false);
        for(int i=0;i<n;i++)
        {
            if(!vis[i])
            {
                dfs(i,vis,mp);
                grp++;
            }
        }
        return grp;
    }
};