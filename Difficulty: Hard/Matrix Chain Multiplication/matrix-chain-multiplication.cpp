//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int dp[102][102];
    int mcm(vector<int>&arr, int i, int j)
    {
        if(i==j)
        {
            return 0;
        }
        
        if(dp[i][j]!= -1)
            return dp[i][j];
            
        int mini = INT_MAX;
        int steps = 0;
        
        for(int k =i;k<j;k++)
        {
            steps = arr[i-1] * arr[k] * arr[j]+ mcm(arr, i, k)+ mcm(arr, k+1, j);
            mini = min(steps, mini);
        }
        
        return dp[i][j] = mini;
    }
    int matrixMultiplication(vector<int> &arr) 
    {
        // code here
        memset(dp, -1, sizeof(dp));
        return mcm(arr, 1, arr.size()-1);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore(); // to ignore the newline after the integer input
    while (t--) {
        int n;
        vector<int> a;
        string input;

        // Input format: first number n followed by the array elements
        getline(cin, input);
        stringstream ss(input);
        int num;
        while (ss >> num)
            a.push_back(num);

        Solution obj;
        cout << obj.matrixMultiplication(a) << endl << "~\n";
    }

    return 0;
}

// } Driver Code Ends