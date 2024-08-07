//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int kthElement(int k, vector<int>& arr1, vector<int>& arr2) 
    {
        int n=arr1.size();
        int m= arr2.size();
        int i=0 , j=0;
        vector<int>arr3;
        int c=1;
        while(i<n && j<m)
        {
            if(arr1[i]<arr2[j])
            {
                if(c==k)    return arr1[i];
                i++;
            }
            else
            {
                if(c==k) return arr2[j];
                j++;
            }
            c++;
        }
        while(i<n)
        {
            if(c==k)    return arr1[i];
            i++;
            c++;
        }
        while(j<m)
        {
            if(c==k)    return arr2[j];
            j++;
            c++;
        }
        return -1;
    }
};
//Fixed Size Initialization: When you initialize a vector with a 
//fixed size (vector<int> arr3(n + m)), you are creating a vector 
//with n + m default-initialized elements (typically zeros for integers).
//If you then use push_back(), you are appending new elements beyond this 
//fixed size, effectively doubling the expected storage requirements and leaving
//the initial default-initialized elements unused.

//{ Driver Code Starts.

// Driver code
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        int n, m, k;
        cin >> k;
        cin.ignore();
        string input;
        int num;
        vector<int> arr1, arr2;

        getline(cin, input);
        stringstream s2(input);
        while (s2 >> num) {
            arr1.push_back(num);
        }

        getline(cin, input);
        stringstream s3(input);
        while (s3 >> num) {
            arr2.push_back(num);
        }

        Solution ob;
        cout << ob.kthElement(k, arr1, arr2) << endl;
    }
    return 0;
}
// } Driver Code Ends