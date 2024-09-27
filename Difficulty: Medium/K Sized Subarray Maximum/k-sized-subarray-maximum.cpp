//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:
    // Function to find maximum of each subarray of size k.
    vector<int> max_of_subarrays(int k, vector<int> &arr) {
        // your code here
        int n = arr.size();
        int i = 0, j = 1, maxi = 0;
        vector<int> ans;
        
        while(i < k) 
        {
            if(arr[i] > maxi) 
                maxi = arr[i];
            i++;
        }
        ans.push_back(maxi);
        
        while(i < n) 
        {
            if(arr[j-1]==maxi)
                maxi = *max_element(arr.begin()+j,arr.begin()+i+1);
            else if(arr[i]>maxi) 
                maxi = arr[i];
            ans.push_back(maxi);
            i++; 
            j++;
        }
        
        return ans;
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    cin.ignore();

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
        vector<int> res = obj.max_of_subarrays(k, arr);
        for (int i = 0; i < res.size(); i++)
            cout << res[i] << " ";
        cout << endl;
    }

    return 0;
}

// } Driver Code Ends