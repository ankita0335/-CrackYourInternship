//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:
    // Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int> >& mat) {
        int n = mat.size();

        for (int candidate = 0; candidate < n; ++candidate) {
            bool isCelebrity = true;

            for (int i = 0; i < n; ++i) {
                if (i != candidate) {
                    if (mat[candidate][i] == 1 || mat[i][candidate] == 0) {
                        isCelebrity = false;
                        break;
                    }
                }
            }

            if (isCelebrity) {
                return candidate;
            }
        }

        return -1;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int> > M(n, vector<int>(n, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> M[i][j];
            }
        }
        Solution ob;
        cout << ob.celebrity(M) << endl;
    }
}

// } Driver Code Ends