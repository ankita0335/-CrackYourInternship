//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
  void dfs(int cur,unordered_map<int,list<int>>&adj,vector<bool>&vis,stack<int>&st){
        vis[cur]=1;
        for(auto i:adj[cur]){
            if(!vis[i]){
                dfs(i,adj,vis,st);
                st.push(i);
            }
        }
        return;
    }
    string findOrder(string dict[], int n, int k) {
        unordered_map<int,list<int>>adj;
        vector<int>inDegree(k);
        for(int i=0;i<n-1;i++){
            int len=min(dict[i].length(),dict[i+1].length());
            for(int j=0;j<len;j++){
                if(dict[i][j]!=dict[i+1][j]){
                    adj[dict[i][j]-'a'].push_back(dict[i+1][j]-'a');
                    inDegree[dict[i+1][j]-'a']++;
                    break;
                }
            }
        }
        vector<bool>vis(k);
        stack<int>st;
        for(int i=0;i<k;i++){
            if(inDegree[i]==0 && !vis[i]){
                dfs(i,adj,vis,st);
            }
        }
        string ans="";
        while(!st.empty()){
            int temp=st.top();
            ans+=('a'+temp);
            st.pop();
        }
        return ans;
    }
};

//{ Driver Code Starts.
string order;

bool f(string a, string b) {
    int p1 = 0;
    int p2 = 0;
    for (int i = 0; i < min(a.size(), b.size()) and p1 == p2; i++) {
        p1 = order.find(a[i]);
        p2 = order.find(b[i]);
        //	cout<<p1<<" "<<p2<<endl;
    }

    if (p1 == p2 and a.size() != b.size())
        return a.size() < b.size();

    return p1 < p2;
}

// Driver program to test above functions
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> N >> K;
        string dict[N];
        for (int i = 0; i < N; i++)
            cin >> dict[i];

        Solution obj;
        string ans = obj.findOrder(dict, N, K);
        order = "";
        for (int i = 0; i < ans.size(); i++)
            order += ans[i];

        string temp[N];
        std::copy(dict, dict + N, temp);
        sort(temp, temp + N, f);

        bool f = true;
        for (int i = 0; i < N; i++)
            if (dict[i] != temp[i])
                f = false;

        if (f)
            cout << 1;
        else
            cout << 0;
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends