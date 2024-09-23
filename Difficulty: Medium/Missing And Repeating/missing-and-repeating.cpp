//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> findTwoElement(vector<int>& arr) {
        // code here
        
        int n=arr.size();
        vector<int> v;
        for(int i=0;i<n;i++)
        {
            int e=abs(arr[i]);
            if(arr[e-1]<0)
            v.push_back(e);
            else
            arr[e-1]*=-1;
        }
        for(int i=0;i<n;i++)
        {
            if(arr[i]>0)
            {
            v.push_back(i+1);
            return v;
            }
        }
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.findTwoElement(a);
        cout << ans[0] << " " << ans[1] << "\n";
    }
    return 0;
}
// } Driver Code Ends