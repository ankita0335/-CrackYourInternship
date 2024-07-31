//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:
    
    string check(string a, string b)
    {
        string res = "";
        for(int i=0;i<a.size();i++)
        {
            if(a[i]==b[i])
            {
                res+=a[i];
            }
            else 
                break;
        }
        return res ;
    }
    string longestCommonPrefix(vector<string> arr) {
        sort(arr.begin(), arr.end());
        int n=arr.size();
        string res = check(arr[0],arr[n-1]);
        return res == "" ? "-1" : res ;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<string> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        string number;
        while (ss >> number) {
            arr.push_back(number);
        }

        Solution ob;
        cout << ob.longestCommonPrefix(arr) << endl;
    }
}

// } Driver Code Ends