//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // Function to return the minimum cost of connecting the ropes.
    long long minCost(vector<long long>& arr) 
    {
        // Your code here
        long long sum=0;
        int n=arr.size();
        int currsum= 0;
        priority_queue<int,vector<int>, greater<int>>pq;
        for(auto i: arr)
        {
            pq.push(i);
        }
        while(pq.size()>1)
        {
            int top1 = pq.top();
            pq.pop();
            int top2=pq.top();
            pq.pop();
            currsum = top1+top2;
            pq.push(currsum);
            sum += currsum;
        }
        return sum;
    }
};


//{ Driver Code Starts.

int main() {
    long long t;
    cin >> t;
    cin.ignore();
    while (t--) {
        string input;
        long long num;
        vector<long long> a;

        getline(cin, input);
        stringstream s2(input);
        while (s2 >> num) {
            a.push_back(num);
        }
        Solution ob;
        cout << ob.minCost(a) << endl;
    }
    return 0;
}

// } Driver Code Ends