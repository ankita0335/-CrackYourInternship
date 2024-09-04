class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) 
    {
        unordered_map<int, unordered_set<int>> mp;
        for(auto i: roads)
        {
            int u= i[0];
            int v= i[1];
            mp[u].insert(v);
            mp[v].insert(u);
        }
        int maxi= 0;
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                int irank= mp[i].size();
                int jrank= mp[j].size();
                int rank= irank + jrank;
                if(mp[i].find(j)!= mp[i].end())
                    rank --;
                maxi = max(maxi, rank);
            }
        }
        return maxi;
    }
};