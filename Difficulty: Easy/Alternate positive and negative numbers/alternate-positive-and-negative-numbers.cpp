//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
// User function template for C++
class Solution {
  public:

    void rearrange(vector<int> &arr) {
        // code here
        vector<int> pos,neg;
        for(auto i: arr)
        {
            if(i<0) neg.push_back(i);
            else pos.push_back(i);
        }
        int p=0,n=0;
        for(int i=0; i<arr.size(); i++)
        {
            if(p<pos.size() && n<neg.size())
            {
                if(i%2) arr[i]=neg[n++];
                else arr[i]=pos[p++];
            }
            else if(p<pos.size()) 
                arr[i]=pos[p++];
            else arr[i]=neg[n++];
        }
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;
        int num;

        getline(cin, input);
        stringstream s2(input);
        while (s2 >> num) {
            arr.push_back(num);
        }
        Solution ob;
        ob.rearrange(arr);
        for (int i = 0; i < arr.size(); i++) {
            cout << arr[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends