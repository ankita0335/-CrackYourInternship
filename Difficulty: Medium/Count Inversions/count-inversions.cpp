//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution 
{
  public:
    // Function to count inversions in the array.
    int merge(int l,int m,int r,vector<int> &a)
    {
        vector<int> b;
        int i=l,j=m+1;
        int c=0;
        while(i<=m && j<=r)
        {
            if(a[i]<=a[j])
            {
                b.push_back(a[i]);
                i++;
            }
            else
            {
                b.push_back(a[j]);
                j++;
                c+=(m-i+1);
            }
            
        }
        while(i<=m)
        {
            b.push_back(a[i]);
            i++;
        }
        while(j<=r)
        {
            b.push_back(a[j]);
            j++;
        }
        for(int k=l;k<=r;k++)
        {
            a[k]=b[k-l];
        }
        return c;
    }
    int mergeSort(int l,int r,vector<int> &arr)
    {
        if(l>=r)
            return 0;
        int count=0;
        int mid=l+(r-l)/2;
        count+=mergeSort(l,mid,arr);
        count+=mergeSort(mid+1,r,arr);
        count+=merge(l,mid,r,arr);
        return count;    
    }
    int inversionCount(vector<int> &arr) 
    {
        // Your Code Here
        return mergeSort(0,arr.size()-1,arr);
        
    }
};

//{ Driver Code Starts.

int main() {

    int T;
    cin >> T;
    cin.ignore();
    while (T--) {
        int n;
        vector<int> a;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int num;
        while (ss >> num)
            a.push_back(num);
        Solution obj;
        cout << obj.inversionCount(a) << endl;
        cout << "~" << endl;
    }

    return 0;
}

// } Driver Code Ends