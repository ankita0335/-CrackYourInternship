//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    void sort012(vector<int>& arr) {
        // code here
        int n=arr.size();
        int l=0,mid=0,h=n-1;
        while(mid<=h)
        {
            if(arr[mid]==0)
            {
                swap(arr[mid],arr[l]);
                l++;
                mid++;
            }
            else if(arr[mid]==1)
                mid++;
            else
            {
                swap(arr[mid],arr[h]);
                h--; //consider a case [0 2 1 2 2 ] to understand this case in better way  
            }
        }
    }
};

//{ Driver Code Starts.
int main() {

    int t;
    cin >> t;
    cin.ignore();
    while (t--) {

        vector<int> a;
        string input;
        int num;

        getline(cin, input);
        stringstream s2(input);
        while (s2 >> num) {
            a.push_back(num);
        }
        Solution ob;
        ob.sort012(a);

        int n = a.size();
        for (int i = 0; i < n; i++) {
            cout << a[i] << " ";
        }

        cout << endl;
    }
    return 0;
}

// } Driver Code Ends