//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int dp[1001][1001];
    int longestCommonSubstr(string s1, string s2) {
        // your code here
        memset(dp,0,sizeof(dp));
        int n=s1.length();
        int m=s2.length();
        int maxi=0;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                if(s1[i-1]==s2[j-1])
                {
                    dp[i][j]=1+dp[i-1][j-1];
                    maxi=max(maxi,dp[i][j]);
                }
            }
        }
        return maxi;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        string s1, s2;
        cin >> s1 >> s2;
        Solution ob;

        cout << ob.longestCommonSubstr(s1, s2) << endl;
    }
}

// Contributed By: Pranay Bansal

// } Driver Code Ends