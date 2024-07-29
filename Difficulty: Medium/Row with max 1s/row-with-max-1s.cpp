//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++
class Solution {
  public:
int rowWithMax1s(vector<vector<int>>& arr) {
    int n = arr.size();
    if (n == 0) return -1;
    int m = arr[0].size();
    if (m == 0) return -1;

    int max_row_index = -1;
    int j = m - 1; // Start from the top-right corner

    for (int i = 0; i < n; i++) {
        while (j >= 0 && arr[i][j] == 1) {
            j--; // Move left
            max_row_index = i; // Update the row index
        }
    }

    return max_row_index;
}

};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int> > arr(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> arr[i][j];
            }
        }
        Solution ob;
        auto ans = ob.rowWithMax1s(arr);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends