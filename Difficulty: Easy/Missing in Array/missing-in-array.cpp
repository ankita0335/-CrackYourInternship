//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++
class Solution {
  public:

    // Note that the size of the array is n-1
    int missingNumber(int n, vector<int>& arr) 
    {
        int miss =0;
        sort(arr.begin(), arr.end());
        if(arr[n-2]!=n)
        {
            miss = n;
        }
        else if(arr[0]!=1)
        {
            miss = 1;
        }
        else 
        {
            for(int i =0; i<n-2; i++)
            {
                if(arr[i+1] != arr[i]+1)
                {
                miss = arr[i]+1;
                }
            }
        }
        return miss;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        vector<int> arr(n - 1);
        for (int i = 0; i < n - 1; ++i)
            cin >> arr[i];
        Solution obj;
        cout << obj.missingNumber(n, arr) << "\n";
    }
    return 0;
}
// } Driver Code Ends