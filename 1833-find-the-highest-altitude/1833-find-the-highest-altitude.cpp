class Solution {
public:
    int largestAltitude(vector<int>& gain) 
    {
        int n= gain.size();
        vector<int>ans(n+1, 0);
        for(int i=1;i<=n;i++)    
        {
            ans[i]= ans[i-1]+ gain[i-1]; 
        }
        return *max_element(ans.begin(), ans.end());
    }
};