//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
public:
    int editDistance(string str1, string str2) 
    {
        int n = str1.size();
        int m = str2.size();
        vector<vector<int>> dp(n+1, vector<int>(m+1, -1));

        for(int i = 0; i <= n; i++)
        {
            for(int j = 0; j <= m; j++)
            {
                if(i == 0 && j == 0)
                    dp[i][j] = 0;
                else if(i == 0)
                {
                    dp[i][j] = 1 + dp[i][j-1];
                }
                else if(j == 0)
                {
                    dp[i][j] = 1 + dp[i-1][j];
                }
                else if(str1[i-1] == str2[j-1])
                {
                    dp[i][j] = dp[i-1][j-1];
                }
                else
                {
                    dp[i][j] = 1 + min(dp[i-1][j-1], min(dp[i][j-1], dp[i-1][j]));
                }
            }
        }
        return dp[n][m];
    }
};


//{ Driver Code Starts.
int main() {
    int T;
    cin >> T;
    while (T--) {
        string s, t;
        cin >> s >> t;
        Solution ob;
        int ans = ob.editDistance(s, t);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends