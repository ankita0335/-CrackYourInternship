class Solution {
public:
    int dp[1001][1001];
    bool isPal(string &s,int i,int j)
    {
        int n=s.length();
        if(i>=j) return true;
        if(dp[i][j]!=-1)    return dp[i][j];
        if(s[i]==s[j])
            return dp[i][j]=isPal(s, i+1, j-1);
        return false;
    }
    string longestPalindrome(string s) {
        int n=s.length();
        int maxl=0,st=0;
        memset(dp,-1,sizeof(dp));
        for(int i=0;i<n;i++)
        {
            for(int j=i;j<n;j++)
            {
                if(isPal(s,i,j))
                {
                    if((j-i+1)>maxl)
                    {
                        maxl=(j-i+1);
                        st=i;
                    }
                }
            }
        }
        return s.substr(st,maxl);
    }
};