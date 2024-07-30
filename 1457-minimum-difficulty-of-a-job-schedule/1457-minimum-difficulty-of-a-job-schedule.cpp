class Solution {
public:
    int dp[301][11];
    int solve(vector<int> &jb, int n, int idx , int d)
    {
        //base case
        if(d==1)
        {
            //take max from all remaining elements
            int maxd=jb[idx];
            for(int i=idx;i<n;i++)
            {
                maxd=max(maxd,jb[i]);
            }
            return maxd;
        }
        if(dp[idx][d]!=-1)  return dp[idx][d];
        int maxd=jb[idx];
        int res=INT_MAX;
        for(int i=idx;i<=n-d;i++)
        {
            maxd=max(maxd,jb[i]);
            int curres=maxd+solve(jb,n,i+1,d-1);
            res=min(res,curres);
        }
        return dp[idx][d]=res;
    }
    int minDifficulty(vector<int>& jb, int d) {
        int n=jb.size();
        memset(dp,-1,sizeof(dp));
        if(n<d) return -1;
        int res=solve(jb,n,0,d);
        return res;
    }
};