//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> spirallyTraverse(vector<vector<int> > &matrix) {
        // code here
        int n = matrix.size();
        int m = matrix[0].size();
        vector<int>ans;
        int left = 0, top = 0, right = m-1, bottom = n-1;
        while(ans.size() < n*m)
        {
            if(left<=right)
            {
                for(int i = left ; i <= right ; i++)
                {
                    ans.push_back(matrix[top][i]);
                }
                top++;
            }
            
            if(top <= bottom && ans.size()< n*m)
            {
                for(int i = top ; i <= bottom ; i++)
                {
                    ans.push_back(matrix[i][right]);
                }
                right--;
            }
            
            if(right >= left && ans.size() < n*m)
            {
                for(int i = right ;i >= left ; i--)
                {
                    ans.push_back(matrix[bottom][i]);
                }
                bottom--;
            }
            
            if(bottom >= top &&  ans.size() < n*m )
            {
                for(int i=bottom ; i >= top ; i--)
                {
                    ans.push_back(matrix[i][left]);
                }
                left++;
            }
        }
        
        return ans;
        
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;

    while (t--) {
        int r, c;
        cin >> r >> c;
        vector<vector<int>> matrix(r, vector<int>(c, 0));

        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                cin >> matrix[i][j];
            }
        }

        Solution ob;
        vector<int> result = ob.spirallyTraverse(matrix);
        for (int i = 0; i < result.size(); ++i)
            cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends