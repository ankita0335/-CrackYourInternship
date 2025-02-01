//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
  int dp[21][21][21];
    int solve(int i, int j, int k,string& s1, string& s2, string& s3)
    {
        if(i<0 || j<0 || k<0)
            return 0; //base case ok
        if(dp[i][j][k]!=-1)
            return dp[i][j][k];
        if(s1[i]==s2[j] && s2[j]==s3[k])
        {
            return dp[i][j][k]=1+solve(i-1,j-1,k-1,s1,s2,s3);
        }
        else 
        {
            return dp[i][j][k]=max({solve(i-1,j,k,s1,s2,s3),solve(i,j-1,k,s1,s2,s3), solve(i,j,k-1,s1,s2,s3)});
        }
    }
    int LCSof3(string& s1, string& s2, string& s3) {
        // your code here
        memset(dp,-1,sizeof(dp));
        int n=s1.size();
        int m = s2.size();
        int n2= s3.size();
        int ans= solve(n-1,m-1,n2-1,s1,s2,s3);
        return ans;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        // int n1, n2, n3; cin >> n1 >> n2 >> n3;
        string s1, s2, s3;
        cin >> s1 >> s2 >> s3;
        cin.ignore();
        Solution obj;
        cout << obj.LCSof3(s1, s2, s3) << endl;

        cout << "~"
             << "\n";
    }
}

// Contributed By: Pranay Bansal

// } Driver Code Ends