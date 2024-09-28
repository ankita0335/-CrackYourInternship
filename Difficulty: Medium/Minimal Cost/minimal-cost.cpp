//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int dp[10001];
    int solve(int i, int k, vector<int>&arr)
    {
        int ans= INT_MAX;
        if(i== arr.size()-1)    return 0;
        if(dp[i]!= -1)  return dp[i];
        for(int j= i+1; j<= i+k && j<arr.size() ;j++)
        {
            int cost = abs(arr[i]-arr[j])+solve(j,k,arr);
            ans = min(ans, cost);
        }
        return dp[i]= ans;
    }
    int minimizeCost(int k, vector<int>& arr) {
        // Code here
        memset(dp,-1,sizeof(dp));
        return solve(0,k,arr);
    }
};

//{ Driver Code Starts.

int main() {
    string ts;
    getline(cin, ts);
    int t = stoi(ts);
    while (t--) {
        string ks;
        getline(cin, ks);
        int k = stoi(ks);
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        Solution obj;
        int res = obj.minimizeCost(k, arr);
        cout << res << endl;
        // string tl;
        // getline(cin, tl);
    }
    return 0;
}

// } Driver Code Ends